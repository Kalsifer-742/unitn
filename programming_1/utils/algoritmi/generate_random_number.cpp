#include <cstdlib>
#include <ctime>

//MAX esclusivo
int generate_random_number(const int MAX){
    srand (time(NULL));
    
    return (rand() % MAX);    //  0 --> MAX-1
}