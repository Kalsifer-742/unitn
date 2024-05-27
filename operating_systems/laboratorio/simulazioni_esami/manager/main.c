#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

//global
int target;
pid_t leafs[10];
int leafs_alive = 0;
//int manager_pid;

void block_signals(int signals[], int len)
{
    sigset_t block;
    sigemptyset(&block);

    for (int i = 0; i < len; i++)
    {
        sigaddset(&block, signals[i]);
    }
    
    sigprocmask(SIG_BLOCK, &block, NULL);
}

void leaf_signaler(int sig_n, siginfo_t* info, void* context)
{
    //devo ricevere il pid
    kill(info->si_value.sival_int, SIGUSR2);
}

void leaf_main(int target)
{
    char buffer[32];

    sprintf(buffer, "%d\n", getpid());
    write(target, buffer, strlen(buffer));

    struct sigaction params;
    params.sa_sigaction = leaf_signaler;
    params.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &params, NULL);

    int signals[2] = { SIGCHLD, SIGCONT };
    block_signals(signals, 2);

    while(1)
    {
        //dovrebbe funzionare ed evitare busy waiting stupido ma non funziona
        pause();
    }
}

void kill_with_payload(pid_t pid, int sig_n, int payload)
{
    union sigval tmp;
    tmp.sival_int = payload;
    sigqueue(pid, sig_n, tmp);
}

void leaf_killer(int sig_n, siginfo_t* info, void* context)
{
    leafs_alive--;
    kill_with_payload(leafs[leafs_alive], SIGUSR1, info->si_pid);
    kill(leafs[leafs_alive], SIGTERM); //soft termination

    if (leafs_alive == 0)
    {
        //kill(manager_pid, SIGKILL);
        kill(getpid(), SIGKILL);
    }
}

void kill_all(int sig_n)
{
    for (int i = leafs_alive; i >= 0; i--)
    {
        kill(leafs[leafs_alive], SIGKILL);
    }
    kill(getpid(), SIGKILL);
}

void manager_main(int target, int n)
{
    char buffer[32];
    sprintf(buffer, "%d\n", getpid());
    write(target, buffer, strlen(buffer));

    for (int i = 0; i < n; i++)
    {
        leafs[i] = fork();
        if (leafs[i] == 0)
        {
            leaf_main(target);
        }
        else
        {
            leafs_alive++;
        }
    }

    struct sigaction params;

    params.sa_sigaction = leaf_killer;
    params.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &params, NULL);

    signal(SIGTERM, kill_all);

    int signals[1] = { SIGALRM };
    block_signals(signals, 1);

    while(1)
    {
        //dovrebbe funzionare ed evitare busy waiting stupido ma non funziona
        pause();
    }
}

//watch ps -H -a -f
/*
Running or Runnable (R)
Uninterruptible Sleep (D)
Interruptable Sleep (S)
Stopped (T)
Zombie (Z)
*/
//strace
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "ERROR: missing parameters\n");  
        return 3;
    }

    int n = atoi(argv[2]);
    if (n == 0)
    {
        fprintf(stderr, "ERROR: n must be a valid number\n");        
        return 4;
    }
    else if (n < 1 || n > 10)
    {
        fprintf(stderr, "ERROR: n must be beetween 1 and 10\n");
        return 4;
    }

    char* target_file = argv[1];
    target = open(target_file, O_WRONLY | O_CREAT | O_EXCL | O_APPEND, S_IRUSR | S_IWUSR);
    if (target == -1)
    {
        fprintf(stderr, "ERROR: file must not exists and be a legal path\n");
        return 5;
    }
    //all controls on input passed
    
    char buffer[32];
    sprintf(buffer, "%d\n", getpid());
    write(target, buffer, strlen(buffer));

    int manager_pid = fork();
    if (manager_pid == 0)
    {
        manager_main(target, n);
    }
    else
    {
        close(target);
    }

    return 0;
}