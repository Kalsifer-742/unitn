#include <iostream>
#include <cstdlib>
using namespace std;

int * generate_numbers(int N);
void stampa(int* array, int N);

int main(){
    int N;
    cin >> N;

    int* array = generate_numbers(N);
    stampa(array, N);
    delete[] array;
}

int* generate_numbers(int N){
    srand(time(NULL));
    
    int* array = new int[N];
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100;
    }

    return array;
}

void stampa(int* array, int N){
    for(int i = 0; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}