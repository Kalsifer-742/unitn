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

/*
typedef struct Distance {
    int feet;
    float inch;
} distances;
*/

struct kill_args_t
{
    int pid;
    int sig_n;
};
void* kill_handler(void* args)
{   
    struct kill_args_t* tmp = (struct kill_args_t*)args;
    kill(tmp->pid, tmp->sig_n);
}

struct msg_buffer 
{
    long mtype;
    char mtext[PARAM_MAX_SIZE];
};

struct queue_args_t
{
    int category;
    char word[PARAM_MAX_SIZE];
    char path[PARAM_MAX_SIZE];
};
void* queue_handler(void* args)
{
    struct queue_args_t* tmp = (struct queue_args_t*)args;
    key_t key = ftok(tmp->path, 1);
    int queue_id = msgget(key, IPC_CREAT | 0777);
    struct msg_buffer message;
    message.mtype = tmp->category;
    strncpy(message.mtext, tmp->word, sizeof(message.mtext));
    int result = msgsnd(queue_id, &message, sizeof(message.mtext), 0);
}

struct fifo_args_t
{
    char name[PARAM_MAX_SIZE];
    char word[PARAM_MAX_SIZE];
};
void* fifo_handler(void* args)
{
    struct fifo_args_t* tmp = (struct fifo_args_t*)args;
    mkfifo(tmp->name, 0666);
    int fd = open(tmp->name, O_WRONLY);
    write(fd, tmp->word, strlen(tmp->word));
    close(fd);
}

bool next = true;
void read_file(FILE* file, char* path)
{
    char command[PARAM_MAX_SIZE];
    char param_1[PARAM_MAX_SIZE];
    char param_2[PARAM_MAX_SIZE];
    while (!feof(file))
    {
        if (!next)
        {
            continue;
        }
        next = false;
        
        fscanf(file, "%s %s %s", command, param_1, param_2);
        if (strcmp("kill", command) == 0)
        {
            int sig_n = atoi(param_1);
            int pid = atoi(param_2);
            if (sig_n == 0 || pid == 0)
            {
                fprintf(stderr, "errore tipo parametri\n");
                exit(1);
            }
            
            pthread_t t_id;
            struct kill_args_t args = {.pid = pid, .sig_n = sig_n};
            pthread_create(&t_id, NULL, kill_handler, &args);
        }
        if (strcmp("queue", command) == 0)
        {   
            int category = atoi(param_1);
            if (category == 0)
            {
                fprintf(stderr, "errore tipo parametri\n");
                exit(1);
            }
            char* word = param_2;

            pthread_t t_id;
            struct queue_args_t args = {.category = category};
            strncpy(args.word, word, strlen(args.word));
            strncpy(args.path, path, strlen(args.path));
            pthread_create(&t_id, NULL, kill_handler, &args);
        }
        if (strcmp("fifo", command) == 0)
        {
            char* name = param_1;
            char* word = param_2;

            pthread_t t_id;
            struct fifo_args_t args;
            strncpy(args.name, name, strlen(args.name));
            strncpy(args.word, word, strlen(args.word));
            pthread_create(&t_id, NULL, fifo_handler, &args);
        }
    }
}

void handler(int sig_n)
{
    next = true;
}

int main(int argc, char** argv)
{
    signal(SIGUSR1, handler);
    
    if(argc != 2)
    {
        fprintf(stderr, "parametro mancante, specificare path del file\n");
        return 1;
    }
    char* path = argv[1];
    FILE* input = fopen(path, "r");
    if (input == NULL)
    {
        fprintf(stderr, "errore apertura file\n");
        return 1;
    }
    
    read_file(input, path);

    fclose(input);

    return 0;
}