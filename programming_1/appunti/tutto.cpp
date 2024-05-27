// NON è ammesso utilizzare break, continue, goto e return all'interno dei cicli. Ad eccezzione del break nello switch.

#include <iostream> //  I/O base, cout/cin
#include <fstream>  //  I/O sui file
#include <cmath>    //  operazioni matematiche come sqrt()
#include <stdlib.h> //  la utilizziamo per ottenere valori random o definire NULL
#include <time.h>   //  utilizzata in coppia con quella precedente
using namespace std;

struct return_value //  posso creare nuovi tipi con struct
{
    bool status;    //  posso gestire situazioni di errore
    int value;      //  effettivo valore di ritorno
};

//int main(int argc, char* argv[])
//argc è il numero di parametri e nel conteggio viene inclusa anche la chiamata al programma(./a.out)
//argv[] é il vettore dei parametri in ordine
int main(){
    //RANDOM
    srand (time(NULL)); //  inizializzo con un seed randomico basato sul tempo
    rand() % 10;        //  genero numeri interi compresi tra 0 e 9

    //PUNTATORI - REFERENCE
    int a;
    int& b = a;     //  alias della variabile a, le modifiche si rispecchiano sulla variabile riferita. ~tecnicamente si tratta di un puntatore con dello zucchero sintattico
    int* c = &a;    //  puntatore alla variabile a
    int z;          
    int* p = &z;
    b = 3;          //  operazione su b che si applica anche ad a
    *c = 5;         //  dereference di c, corrisponde al valore contenuto da a, cambia il valore contenuto in a
    c = &z;         //  cambio il valore puntato da c. ora punta z invece di a
    c = p;          //  idem all'operazione precedente
    cout << &a;     //  operatore & restituisce l'indirizzo di una variabile oltre che essere usato per dichiarare reference

    //ARRAY ~tecnicamente sono puntatori al primo alemento dell'array
    int array[5];                   // array sulla stack di dimensione 5
    int* array_heap = new int[5];   // array sulla heap di dimenzione 5

    //CHIAMATE FUNZIONI
    funzione_array_by_value(array);
    funzione_array_by_pointer(array);
    funzione_array_by_pointer(array_heap);
    funzione_array_by_pointer_reference(array_heap);
    funzione_array_by_pointer_pointer(&array_heap);

    //MEMORIA - bisogna deallocare solamente gli elementi sulla heap
    delete c;               //  dealloca memoria puntata dal puntatore

    // quando cambio l'indirizzo puntato da un puntatore devo ricordarmi di liberare la memoria a cui prima puntava
    delete c;               //  devo deallocare la memoria che non sarà più indirizzata da c
    c = p;                  //  prima di modificare l'indirizzo puntato da c

    delete[] array_heap;    //  dealloca memoria occupata dall'array ~tecnicamente si tratta sempre di un puntatore, solo che devo liberare la memoria occupata da tutti gli elementi

    //FILES
    fstream input;
    input.open("nomefile.estensione", ios::in); //  ios::out
    input.seekg(0);   //  setta la posizione in lettura
    input.seekp(0);   //  setta la posizione in scrittura
    input.tellg();  //  ritorna la poszione in lettura o scrittura(input.tellp())
    //  operazioni sul file
    input.eof();    //  ritorna true raggiunta la fine del file

    input.close();  //  ricordarsi sempre di chiudere lo stream
}

void by_valore(int x){
    /*
        modifiche ad x NON si propagano esternamente alla funzione.
        ~tecnicamente si tratta di una copia locale della variabile.
    */
}

void by_reference(int& x){
    /*
        x è un alias della variabile passata. Tutte le modifiche applicate ad x si propagano al di fuori della funzione.
        ~tecnicamente si tratta di un puntatore alla variabile passata con dello zucchero sintattico
    */
}

void by_pointer(int* x){
    /*
        x è un nuovo puntatore che contiene l'indirizzo della variabile puntata dal valore passato
        (ho un nuovo puntatore interno alla funzione che punta allo stesso elemento a cui punta il puntatore passato alla chiamata della funzione)
        bisogna avere coscenza di quello che si sta facendo.
        si tratta quindi di un pasaggio per valore di un puntatore (o dell'indirizzo puntato, in base a come si preferisce vederla).
        operazioni al valore riferito dal puntatore (*x = y) si propagano al di fuori della funzione.
        operazioni all'indirizzo di x (x = y) non si propagano al di fuori della funzione (perchè x è appunto un nuovo puntatore intero alla funzione).
        ~tecnicamente si tratta di una copia per valore del puntatore
    */
}

void by_pointer_reference(int*& x){
    /*
        x è un alias al puntatore passato. Tutte le modifiche applicate ad x si propagano al di fuori della funzione.
        funziona esattamente come un alias ad una variabile
        operazioni al valore riferito dal puntatore (*x = y) si propagano al di fuori della funzione.
        operazioni all'indirizzo di x (x = y) si propagano al di fuori della funzione (perchè x è lo stesso puntatore passato alla chiamata della funzione).
        ~tecnicamente si tratta in realtà di puntatore ad un puntatore (**))
    */
}

void funzione_array_by_value(int arr[]){
    /*
        operazioni ai valori dell'array (array[i] = y) si propagano al di fuori della funzione.
        operazioni (arr = y) non si propagano al di fuori della funzione e possono essere fatte solo con array (puntatori) allocati sulla heap.
        ~tecnicamente si tratta di una copia per valore del puntatore
    */
}

void funzione_array_by_pointer(int* arr){
    /*
        operazioni ai valori dell'array (array[i] = y / *(arr+i) = y) si propagano al di fuori della funzione.
        operazioni (arr = y) non si propagano al di fuori della funzione e possono essere fatte solo con array (puntatori) allocati sulla heap
        ~tecnicamente si tratta di una copia per valore del puntatore
    */
}

void funzione_array_by_pointer_reference(int*& arr){
    /*
        operazioni ai valori dell'array (array[i] = y / *(arr+i) = y) si propagano al di fuori della funzione.
        operazioni (arr = y / *arr = y) si propagano al di fuori della funzione e possono essere fatte solo con array (puntatori) allocati sulla heap
        ~tecnicamente si tratta di un puntatore ad un puntatore
    */
}

void funzione_array_by_pointer_pointer(int** arr){
    /*
        operazioni ai valori dell'array (array[i] = y / *(*arr+i) = y) si propagano al di fuori della funzione.
        operazioni (arr = y / *arr = y) si propagano al di fuori della funzione e possono essere fatte solo con array (puntatori) allocati sulla heap
        ~tecnicamente si tratta di un puntatore ad un puntatore
    */
}