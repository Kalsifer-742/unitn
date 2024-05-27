#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
#define PARAMETERS_N 3

int lengthof(char* str)
{
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

bool is_valid_parameter(char* string, char** possible_values)
{
    for (int i = 0; i < PARAMETERS_N; i++)
    {
        //printf("%s - %s\n", string, possible_values[i]);
        if (strcmp(string, possible_values[i]) == 0)
        {
            return true;
        }
    }
    
    return false;
}

void read_file(char* file_name) 
{
    FILE* fp = fopen(file_name, "r");
    char ch;

    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
}

double calculate_pi()
{
    //codice dello internet
    int i;
    double pi = 0.0, n = 1.0, term;
    for (i = 0; i < 100; i++) {
        term = 4.0 / n;
        if (i % 2 == 0) {
            pi += term;
        } else {
            pi -= term;
        }
        n += 2.0;
    }

    return pi;
}

void maybe_pi(int seed)
{
    srand(seed);
    int r = rand() % 6;
    //printf("%d - %d\n", seed, r);

    switch (r)
    {
    case 1:
        printf("L'ultima volta che ho controllato: PI = 3.14159");
        break;
    case 2:
        printf("Iuppa mi odia... PI = 3.5");
        break;
    case 3: 
        printf("In quanto a quel che non puoi fare che tu per te qualche modo di calcolare PI da solo dovresti averlo!");
        break;
    case 4:
        printf("Oggi sono di buonumore, ecco a te una PI fresca fresca:\n");
        read_file("pie.txt");
        break;
    case 5:
        int pi = calculate_pi();
        printf("Ho ricontrollato calcolandolo al momento e PI = %f", pi);
        break;
    
    default:
        printf("sono stanco, arrangiati!");
        break;
    }

    printf("\n");
}

int main(int argc, char** argv) 
{
    char** possible_parameters;
    possible_parameters[0] = "-help";
    possible_parameters[1] = "-version";
    possible_parameters[2] = "-pi";

    if(argc < 2)
    {
        printf("ERRORE - passare almeno 1 parametro\n");

        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        //printf("%s\n", argv[i]);
        if (!is_valid_parameter(argv[i], possible_parameters)) 
        {
            printf("ERRORE - [%s] non è un parametro\n", argv[i]);
        } 
        else 
        {
            if (strcmp(argv[i], "-help") == 0) {
                read_file("help.txt");
            } 
            else if (strcmp(argv[i], "-version") == 0) 
            {
                printf("version 1.0\n");
            } 
            else if (strcmp(argv[i], "-pi") == 0) 
            {
                maybe_pi(atoi(argv[i + 1]));
                //printf("PI %d\n", atoi(argv[i + 1]));
                printf("(da risolvere che il parametro sia visto come un altro comando)\n");
            }
        }
    }
    
    return 0;
}