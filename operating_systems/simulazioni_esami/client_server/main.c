#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//global variables
FILE* log_file;
pid_t childs[10];
int childs_n = 0; //l'idea di tenere un index non sembra portare benefici

void create_child(int sig_n)
{
    int child_pid = fork();
    if (child_pid != 0)
    {
        childs[childs_n] = child_pid;
        childs_n++;
        fprintf(log_file, "+%d\n", child_pid);
        fprintf(stdout, "[server] +%d\n", child_pid);
    }
}

void delete_child(int sig_n)
{
    childs_n--;

    if (childs_n < 0)
    {
        childs_n = 0;
        fprintf(log_file, "%d\n", childs_n);
        fprintf(stdout, "[server] %d\n", childs_n);
    }
    else
    {
        kill(childs[childs_n], SIGKILL);
        fprintf(log_file, "-%d\n", childs[childs_n]);
        fprintf(stdout, "[server] -%d\n", childs[childs_n]);
    }
}

void get_childs_n(int sig_n)
{
    fprintf(log_file, "%d\n", childs_n);
    exit(0);
}

void server()
{
    fprintf(log_file, "%d\n", getpid());
    fprintf(stdout, "[server:%d]\n", getpid());

    signal(SIGUSR1, create_child);
    signal(SIGUSR2, delete_child);
    signal(SIGINT, get_childs_n);

    while (1)
    {
        fflush(log_file);
        pause();
    }
    
}

void client()
{
    int counter = 0;
    char* tmp;
    fscanf(log_file, "%s", tmp);
    pid_t server_pid = atoi(tmp);
    printf("[client] server: %d\n", server_pid);

    char input[3];
    while (1)
    {
        //scanf("%s", input); non posso leggere \n
        fgets(input, 3, stdin);
        
        if (input[0] == '+')
        {
            if (counter < 10)
            {
                counter++;
                printf("[client] %d\n", counter);
                kill(server_pid, SIGUSR1);
            }
        }
        else if (input[0] == '-')
        {
            if (counter > 0)
            {
                counter--;
                printf("[client] %d\n", counter);
                kill(server_pid, SIGUSR2);
            }
        }
        else if (input[0] == '\n')
        {
            for (int i = counter; i > 0; i--)
            {
                printf("[client] %d\n", i);
                kill(server_pid, SIGUSR2);
                sleep(1);
            }

            kill(server_pid, SIGINT);
            exit(0);    
        }
    }
}

int main(int argc, char** argv)
{
    char* mode = argv[1];
    char* path = argv[2];

    if (argc < 3)
    {
        fprintf(stderr, "missing parameters <mode> <path>\n");
        return 1;
    }
    else if(argc > 3)
    {
        fprintf(stderr, "too many parameters\n");
        return 1;
    }

    if (strcmp(mode, "client") != 0 && strcmp(mode, "server") != 0)
    {
        fprintf(stderr, "mode must be \"server\" or \"client\"\n");
        return 1;
    }
    
    if (strcmp(mode, "server") == 0)
    {
        if (fopen(path, "r") != NULL)
        {
            fprintf(stderr, "file already exist or path is not legal\n");
            return 1;
        }
        log_file = fopen(path, "a");

        server();
    }
    else if (strcmp(mode, "client") == 0)
    {
        while (1)
        {
            if (fopen(path, "r") != NULL)
            {
                break;
            }
        }
        log_file = fopen(path, "r");

        client();
    }
    
    return 0;
}