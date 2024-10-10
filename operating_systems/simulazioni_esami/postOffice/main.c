#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdbool.h>
#define PARAM_MAX_SIZE 255
//variabili globali
pid_t workers[10];
int worker_n = 0;
FILE* file;
int queue_id;
bool sigusrone_received = false;

key_t get_key(char* path, int id)
{
    key_t key = ftok(path, id);
    return key;
}

int create_queue_id(key_t key)
{
    int queue_id = msgget(key, IPC_CREAT | 0777);
    return queue_id;
}

struct msg_buffer
{
    long mtype;
    char mtext[PARAM_MAX_SIZE];
};

int write_queue(struct msg_buffer message, int queue_id)
{
    //IPC_NOWAIT = 0 aspetta che ci sia spazio per inviare il messaggio
    int result = msgsnd(queue_id, &message, sizeof(message.mtext), 0);
    return result;
}

void kill_all()
{
    for (int i = worker_n; i >= 0; i--)
    {
        kill(workers[worker_n], SIGKILL);
    }
    exit(0);
}

void kill_with_payload(pid_t pid, int sig_n, void* payload)
{
    union sigval tmp;
    tmp.sival_ptr = payload;
    sigqueue(pid, sig_n, tmp);
}

void worker_signal_handler(int sig_n, siginfo_t* info, void* context)
{
    if(sig_n == SIGUSR1 && !sigusrone_received)
    {
        sigusrone_received = true;
        kill(info->si_pid, SIGUSR1);
    }
    else if(sig_n == SIGUSR2)
    {
        kill(info->si_pid, SIGUSR2);
    }
    else if(sig_n == SIGURG)
    {
        char* payload = (char*)info->si_value.sival_ptr;
        struct msg_buffer tmp;
        tmp.mtype = getpid();
        strncpy(tmp.mtext, payload, strlen(tmp.mtext));
        write_queue(tmp, queue_id);
    }
}

//Worker
void worker_main()
{
    struct sigaction params;
    params.sa_sigaction = worker_signal_handler;
    params.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &params, NULL);
    sigaction(SIGUSR2, &params, NULL);
    sigaction(SIGURG, &params, NULL);

    while(true)
    {
        pause();
    }
}

void postoffice_signal_handler(int sig_n, siginfo_t* info, void* context)
{
    //struct msg_buffer message;
    //message.mtype = 1;
    char buffer[PARAM_MAX_SIZE];

    int n = 0;
    while(!feof(file))
    {
        fgets(buffer, strlen(buffer), file);
        buffer[strlen(buffer) - 1] = '\0';
        //strncpy(message.mtext, buffer, strlen(message.mtext));

        kill_with_payload(workers[(n % worker_n)], SIGURG, (void*)buffer);
        n++;
        sleep(1);
        //write_queue(message, queue_id);
    }

    kill_all();
}

//PostOffice
int main(int argc, char** argv)
{
    int n;
    char path_to_file[PARAM_MAX_SIZE];
    int pid_input;

    //controllo lunghezza parametri
    if(argc != 4)
    {
        fprintf(stderr, "errato numero parametri\n");
        exit(1);
    }
    //controllo validità n
    n = atoi(argv[1]);
    if(n == 0 || n < 1 || n > 10)
    {
        fprintf(stderr, "<%s> non è un numero valido\n", argv[1]);
        exit(2);
    }
    //controllo validità percorso file
    strncpy(path_to_file, argv[2], PARAM_MAX_SIZE);
    file = fopen(path_to_file, "r");
    if(file == NULL)
    {
        fprintf(stderr, "<%s> non è un file valido\n", path_to_file);
        exit(3);
    }
    //controllo validità pid
    pid_input = atoi(argv[3]);
    if(pid_input == 0)
    {
        fprintf(stderr, "<%s> non è un pid valido\n", argv[3]);
        exit(4);
    }

    //creo la coda
    queue_id = create_queue_id(get_key(path_to_file, getpid()));

    //creo i workers
    for (int i = 0; i < n; i++)
    {
        workers[i] = fork();
        if (workers[i] != 0)
        {
            worker_n++;
            kill(pid_input, SIGTERM);
            worker_main();   
        }
    }

    struct sigaction params;
    params.sa_sigaction = postoffice_signal_handler;
    params.sa_flags = SA_SIGINFO;
    sigaction(SIGWINCH , &params, NULL);

    while(true)
    {
        pause();
    }

    return 0;
}