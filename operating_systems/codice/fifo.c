#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void print_string(char buffer[])
{
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == '\n')
        {
            printf("\\n");
        }
        else if(buffer[i] == '\0')
        {
            printf("\\0");
        }
        else
        {
            printf("%c ", buffer[i]);
        }
    }
    printf("\n");
}

int main()
{
    char* fifo = "path";
    mkfifo(fifo, 0666);
    
    int child = fork();
    if (child == 0)
    {
        int fd = open(fifo, O_RDONLY);
        printf("[CHILD] read open\n");
        char buffer[16];
        read(fd, buffer, 16);
        printf("[CHILD] <-- %s\n", buffer);
    }
    else
    {
        int fd = open(fifo, O_WRONLY);
        printf("[MASTER] write open\n");
        char buffer[16];
        sprintf(buffer, "ping");
        write(fd, buffer, strlen(buffer));
        printf("[MASTER] --> %s\n", buffer);
    }

    while(wait(NULL) > 0);

    return 0;
}