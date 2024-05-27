#include <iostream>
using namespace std;

void prime_factorization_iterative(int n){
    int i = 2;
    while(n > 1)
    {
        if(n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
        else i++;
    }
}