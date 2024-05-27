#include <iostream>
using namespace std;
 
void prime_factorization_recursive(int n, int i = 2)
{
    if (n <= 1)
    {
        return;
        /*
            caso base
            se voglio salvare i numeri primi in un array
            arrivato a questo punto posso crearne uno pari alla grandezza dei numeri primi che ho contato
            e durante la risalita riempire l'array con i vari valori
        */
    }
    else
    {
        if ((n % i == 0))
        {
            cout << i << " ";
            prime_factorization_recursive(n / i, i);
        }
        else
        {
            prime_factorization_recursive(n, i + 1);
        }
    }
}