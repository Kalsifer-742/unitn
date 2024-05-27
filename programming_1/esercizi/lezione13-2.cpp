#include <iostream>
using namespace std;

void stampa_array(int [], int);
void popula_array(int [], int);
int cerca(int, int[], int);
void bubble_sort(int[], int);

int main(){
	const int DIM = 10;
	int array[DIM];

	popula_array(array, DIM);
	stampa_array(array, DIM);
	
	bubble_sort(array, DIM);
	stampa_array(array, DIM);
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

int cerca(int x, int arr[], int DIM){
	for(int i = 0; i < DIM; i++){
		if(arr[i] == x){
			return i;
		}
	}
	return -1;
}

void bubble_sort(int arr[], int DIM){
	int tmp;
	
	bool swapped = true;	
	while(swapped){
		swapped = false;
		for(int i = 0; i < DIM-1; i++){
			if(arr[i] > arr[i+1]){
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				swapped = true;
			}
		}	
	}

}
