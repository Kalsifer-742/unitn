#include <iostream>
using namespace std;

int main()
{
int x = 5;
int * y = &x;
int ** k = &y;

cout << x << " " << &x << endl;
cout << (*y) << " " << &y << endl; //y ha il proprio indirizzo dove vi è scritto il suo contenuto, ovvero l'indirizzo di x

cout << y << endl; //y contiene l'indirizzo di x

cout << (*k) << " " << &k << endl; //k punta al valore contenuto in y che poi è l'indirizzo di x
cout << **k << endl; //deferenziando una volta ottengo il contenuto di y e con la seconda quello di x

return 0;
}
