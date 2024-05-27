#include <stdio.h>
#include <fcntl.h> //open ecc...
#include <unistd.h> //close ecc...

/*
Crea un’applicazione che copia il contenuto di un file, leggendolo con i file streams e
scrivendolo con i file descriptors. Crea poi un programma che fa il contrario. Prova a
copiare carattere per carattere e linea per linea.
*/

int main()
{
    FILE* input;
    input = fopen("input.txt", "r");
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); //https://chmodcommand.com/chmod-644/

    char* tmp;
    while (!feof(input))
    {
        *tmp = fgetc(input);
        //printf("%c", *tmp);
        write(fd, tmp, 1);
    }
    
    fclose(input);
    close(fd);

    return 0;
}