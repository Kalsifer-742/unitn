#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/msg.h>

struct parameters_t {
    char* pathToLogFile;
    int error;
};

struct parameters_t read_parameters(int argc, char** argv){
    struct parameters_t tmp = { .error = 0 };
    
    if(argc == 2) 
    {
        tmp.pathToLogFile = argv[1];
    } 
    else if (argc > 2) 
    {
        printf("%s \n", "ERROR: too many arguments");
        tmp.error = 1;
    }

    return tmp;
}

FILE* file;
void logger(FILE* f, int pid, int sig_n)
{
    if (fork() == 0)
    {
        sleep(3);
        fprintf(f, "%d-%d\n", pid, sig_n);
        exit(3);
    }
}

void repeater(int signo, siginfo_t* info, void* context)
{
    kill(info->si_pid, SIGUSR1);
    printf("DEBUG - Segnale SIGUSR1 ricevuto da %d e inviato a %d da parte di %d\n", info->si_pid, info->si_pid, getpid());
    logger(file, info->si_pid, SIGUSR1);
}

void relay(int signo, siginfo_t* info, void* context)
{
    int pid = fork();
    if (pid == 0) //pid is 0 for the child
    {
        kill(info->si_pid, SIGUSR2);
        printf("DEBUG - Segnale SIGUSR2 ricevuto da %d e inviato a %d da parte di %d\n", info->si_pid, info->si_pid, getpid());
        logger(file, info->si_pid, SIGUSR2);
        exit(2); //use exit and not return. return just exit functions
    }

    waitpid(pid, NULL, 0);
}

void stop(int sig_n)
{
    fprintf(file, "stop\n");
    fflush(file);
}

int create_queue(char* path, int value)
{
    key_t key;
    int id;
    
    key = ftok(path, value);
    if (key == -1) //error
    {
        creat(path, S_IRWXU); //also rewrite if exists. depends on open
        key = ftok(path, value);
    }

    //crea una coda se non esiste già, altrimenti restituisce l’identificativo di quella già esistente
    //S_IRWXU  00700 user (file owner) has read, write, and execute permission
    id = msgget(key, IPC_CREAT | S_IRWXU);

    return id;
}

struct msg_buffer 
{
    long mtype;
    pid_t mtext;
};

//ps -A r use to see running processes in the system
int main(int argc, char** argv)
{
    int default_value = 1;
    struct parameters_t parameters = read_parameters(argc, argv);
    if (parameters.error != 0)
    {
        return parameters.error;
    }
    file = fopen(parameters.pathToLogFile, "a");
    int queue_id = create_queue(parameters.pathToLogFile, default_value);

    printf("DEBUG - pid: %d\n", getpid());

    struct sigaction sa;

    sa.sa_sigaction = repeater;
    sa.sa_flags = SA_SIGINFO;
    //non mi interessa otterene la vecchia sigaction quindi ultimo parametro NULL
    sigaction(SIGUSR1, &sa, NULL);

    sa.sa_sigaction = relay;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);

    signal(SIGINT, stop);

    struct msg_buffer message;
    while(1)
    {
        //msgtyp = 0 ritorna il primo messaggio presente nella coda
        int result = msgrcv(queue_id, &message, sizeof(message.mtext), 0, IPC_NOWAIT);
        if (result != -1)
        {
            kill(message.mtext, SIGALRM);
        }
    }

    return 0;
}