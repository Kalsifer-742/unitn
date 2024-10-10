#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

//onesto
void read_by_fgets(char buffer[], int buffer_size)
{
    //NULL on error
    fgets(buffer, buffer_size, stdin);
    buffer[strlen(buffer) - 1] = '\0'; //to delete the \n
    print_string(buffer);
}

//onesto
void read_by_read(char buffer[], int buffer_size)
{
    //-1 on error
    int bytes_read = read(STDIN_FILENO, buffer, buffer_size);
    printf("bytes read: %d\n", bytes_read);
    buffer[bytes_read - 1] = '\0'; //to delete the \n
    print_string(buffer);
}

//spazzatura
void read_by_scanf()
{
    char c;
    int item_matched = scanf("%c", &c);
    printf("items: %d\n", item_matched);
    printf("%c\n", c);
}

//non lo userò mai
void read_by_getline(char buffer[], size_t buffer_size)
{
    //getdelim(&buffer, &buffer_size, '\n', stdin);
    int c_read = getline(&buffer, &buffer_size, stdin);
    printf("char read: %d\n", c_read);
    buffer[c_read - 1] = '\0'; //to delete the \n
    print_string(buffer);
}

int main()
{
    int buffer_size = 16;
    char buffer[buffer_size];
    
    read_by_fgets(buffer, buffer_size);
    read_by_read(buffer, buffer_size);
    //read_by_scanf();
    //read_by_getline(buffer, buffer_size);
    
    return 0;
}