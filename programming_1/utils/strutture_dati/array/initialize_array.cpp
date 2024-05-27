#include <stdlib.h>
#include <time.h>

void initialize_array(int array[], int DIM){
    srand (time(NULL));
    
    for (int i = 0; i < DIM; i++)
    {
        array[i] = rand() % 10 + 1;
    }
}