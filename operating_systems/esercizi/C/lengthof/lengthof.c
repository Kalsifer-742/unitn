#include <stdio.h>

int lengthof(char* str) {
    int counter = 0;

    for (int i = 0; ; i++) {
        //printf("%c \n", *(str+i));

        if (*(str+i) == '\0')
        {
            return counter;
        }
        
        counter++;
    }
    
    
    return -1;
}

int main(int argc, char** argv) {
    if(argc < 2)
    {
        printf("ERRORE - passare una stringa come parametro\n");

        return 1;
    }

    int string_length = lengthof(argv[1]);
    if (string_length == -1)
    {
        printf("ERRORE - carratere terminatore mancante\n");

        return 2;
    }
    
    printf("%d \n", string_length);

    return 0;
}