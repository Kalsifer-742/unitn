#include <stdio.h>
#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h> //fcntl.h — file control options
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>

struct msg_buffer {
    long mtype;
    char mtext[32];
};

int default_value = 1;

struct parameters_t {
    char* name;
    char* action;
    char* value;
    char* pid;
    int result;
};

struct parameters_t parse_parameters(int argc, char** argv){
    struct parameters_t tmp = { .result = 0 };
    
    if (argc == 1) {
        printf("%s \n", "ERROR: no arguments");
        tmp.result = -1;
    } else if(argc == 3) {
        tmp.name = argv[1];
        tmp.action = argv[2];
    } else if(argc < 4) {
        printf("%s \n", "ERROR: too few arguments");
        tmp.result = -1;
    } else if (argc == 4) {
        tmp.name = argv[1];
        tmp.action = argv[2];
        tmp.value = argv[3];
    } else if (argc == 5) {
        tmp.name = argv[1];
        tmp.action = argv[2];
        tmp.value = argv[3];
        tmp.pid = argv[4];
    } else if (argc > 5) {
        printf("%s \n", "ERROR: too many arguments");
        tmp.result = -1;
    }

    return tmp;
}

key_t get_key(char* path, int id)
{
    key_t key = ftok(path, id);
    return key;
}

int get_queue_id(key_t key)
{
    //S_IRWXU  00700 user (file owner) has read, write, and execute permission
    int id = msgget(key, S_IRWXU);
    return id;
}

//also creates file if it does not exist
key_t create_key(char* path, int id)
{
    key_t key = get_key(path, id);
    if (key == -1) //error
    {
        creat(path, S_IRWXU); //also rewrite if exists. depends on open
        key = get_key(path, id);
    }
    
    return key;
}

//also creates the queue if it does not exist
int create_queue_id(key_t key)
{
    int queue_id = msgget(key, IPC_CREAT | S_IRWXU);
    return queue_id;
}

int write_queue(struct msg_buffer message, int queue_id)
{
    //IPC_NOWAIT = 0 aspetta che ci sia spazio per inviare il messaggio
    int result = msgsnd(queue_id, &message, sizeof(message.mtext), 0);
    return result;
}

int read_queue_nowait(struct msg_buffer* message, int queue_id)
{
    //IPC_NOWAIT aspetta che ci sia un messaggio da ricevere
    int result = msgrcv(queue_id, message, sizeof(message->mtext), 0, IPC_NOWAIT);
    return result;
}

int delete_queue(int queue_id)
{
    int result = msgctl(queue_id, IPC_RMID, NULL);
    return result;
}

//la gestione degli errori non è completa come vuole il prof
int main(int argc, char** argv) {    
    struct parameters_t parameters = parse_parameters(argc, argv);

    if (parameters.result == -1)
    {
        return 1;
    }
    
    if (strcmp("new", parameters.action) == 0) 
    {
        key_t key = create_key(parameters.name, default_value);
        int queue_id = get_queue_id(key);

        if (queue_id != -1)
        {
            printf("%d \n", queue_id);
        }
        else
        {
            create_queue_id(key);
        }
        
        kill(atoi(parameters.pid), SIGUSR1);
    } 
    else if (strcmp("put", parameters.action) == 0) 
    {
        int queue_id = create_queue_id(create_key(parameters.name, default_value));

        struct msg_buffer message = { .mtype = default_value };
        strncpy(message.mtext, parameters.value, 32);

        int result = write_queue(message, queue_id);
        if (result == -1)
        {
            kill(atoi(parameters.pid), SIGUSR2);
            return 1;
        }
        
        kill(atoi(parameters.pid), SIGUSR1);
    }
    else if (strcmp("get", parameters.action) == 0) 
    {
        int queue_id = create_queue_id(create_key(parameters.name, default_value));

        struct msg_buffer message;
        
        int result = read_queue_nowait(&message, queue_id);
        if (result != -1)
        {
            printf("%s\n", message.mtext);
        }
        else
        {
            printf("\n");
        }
        
        kill(atoi(parameters.pid), SIGUSR1);
    } 
    else if (strcmp("del", parameters.action) == 0) 
    {
        int queue_id = get_queue_id(get_key(parameters.name, default_value));

        if (queue_id != -1)
        {
            delete_queue(queue_id);
        }

        kill(atoi(parameters.pid), SIGUSR1);
    } 
    else if (strcmp("emp", parameters.action) == 0)
    {
        int queue_id = create_queue_id(create_key(parameters.name, default_value));
        struct msg_buffer message;

        while (1)
        {
            int result = read_queue_nowait(&message, queue_id);
            if (result != -1){
                printf("%s \n", message.mtext);
            } else {
                break;
            }
        }

        kill(atoi(parameters.pid), SIGUSR1);
    } 
    else if (strcmp("mov", parameters.action) == 0) 
    {
        int queue_id_from = get_queue_id(get_key(parameters.name, default_value));
        if (queue_id_from == -1)
        {
            kill(atoi(parameters.pid), SIGUSR2);
            return 1;
        }
        
        int queue_id_to = get_queue_id(get_key(parameters.value, default_value));
        if (queue_id_to == -1)
        {
            create_queue_id(create_key(parameters.value, default_value));
        }

        struct msg_buffer message;
        int n_msg = 0;
        while (1)
        {
            int result = read_queue_nowait(&message, queue_id_from);
            if (result != -1){
                printf("%s\n", message.mtext);

                struct msg_buffer tmp = { .mtype = default_value };
                strncpy(tmp.mtext, message.mtext, 32);
                result = write_queue(tmp, queue_id_to);
                n_msg++;
            } else {
                delete_queue(queue_id_from);
                printf("%d\n", n_msg);
                break;
            }
        }

        kill(atoi(parameters.pid), SIGUSR1);
    }
    
    return 0;
}