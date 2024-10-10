#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>

struct msg_buffer
{ 
    long mtype; 
    pid_t mtext; 
} message;

void handler(int sig_n)
{
    printf("Ricevuto un SIGALRM\n");
}

//programma utile a debuggare l'ultima richiesta del compito
//gcc queue_checker.c -o queue_checker
int main(int argc, char** argv)
{
    int pid = getpid();
    message.mtype = 1;
    message.mtext = pid;

    key_t key = ftok(argv[1], 1);
    int id = msgget(key , 0777 | IPC_CREAT);

    msgsnd(id , &message, sizeof(message.mtext), 0);
    
    signal(SIGALRM, handler);

    while (1);

    return 0;
}