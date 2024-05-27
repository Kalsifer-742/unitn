#include <iostream>
using namespace std;

void print_array_iterative(int array[], int DIM){ 
    for (int i = 0; i < DIM; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}