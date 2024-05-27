#include <cstdlib>
#include <ctime>

//MIN inclusivo | MAX esclusivo
int generate_random_number_in_range(const int MIN, const int MAX){
    srand (time(NULL));
    
    return (rand() % (MAX-MIN) + MIN);    //  MIN --> MAX-1
}