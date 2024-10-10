#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

/*
Scrivere dei programmi in C che:
1. Avendo come argomenti dei “binari”, si eseguono con exec ciascuno in un sottoprocesso
2. idem punto 1 ma in più salvando i flussi di stdout e stderr in un unico file
3. Dati due eseguibili come argomenti del tipo ls e wc si eseguono in due processi distinti: il primo
deve generare uno stdout redirezionato su un file temporaneo, mentre il secondo deve essere
lanciato solo quando il primo ha finito leggendo lo stesso file come stdin.
Ad esempio ./main ls wc deve avere lo stesso effetto di ls | wc.
*/

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        int result = fork();

        if (result == 0)
        {
            int error = execvp(argv[i], NULL);

            if (error == -1)
            {
                printf("%s\n", strerror(errno));
            }
        }
    }

    while(wait(NULL) > 0); //attendo i figli

    return 0;
}