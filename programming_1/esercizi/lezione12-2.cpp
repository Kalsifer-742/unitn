#include <iostream>
using namespace std;

void stampa_array(int [], int);
void popula_array(int [], int);
void inserisci_valore(int [], int, int, int);
void copia_array(int [], int [], int, int, int);

int main(){
	const int DIM = 10;
	int array[DIM];

	popula_array(array, DIM);
	stampa_array(array, DIM);

	inserisci_valore(array, 10, 42, 5-1);
}

void stampa_array(int arr[], int DIM){
	for(int i = 0; i < DIM; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void popula_array(int arr[], int DIM){
	srand(time(NULL));

	for(int i = 0; i < DIM; i++){
		arr[i] = rand() % 10;
	}
}

void inserisci_valore(int arr[], int DIM, int val, int ind){
	int head_array[ind];
	int tail_array[DIM-ind];
	int final_array[DIM+1];

	copia_array(arr, head_array, 0, ind, 0);
	copia_array(arr, tail_array, ind, DIM, 0);

	copia_array(head_array, final_array, 0, ind, 0);
	copia_array(tail_array, final_array, 0, DIM+1, ind+1);
	final_array[ind]=val;

	stampa_array(final_array, DIM+1);	
}

void copia_array(int arr1[], int arr2[], int start1, int end1, int start2){
	for(int i = start1, j = start2; i < end1; i++, j++){
		arr2[j] = arr1[i];
	}
}
