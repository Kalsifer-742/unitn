#include <iostream>
using namespace std;

void stampa_array(int [], int);
void popula_array(int [], int);
int cerca(int, int[], int);

int main(){
	const int DIM = 10;
	int array[DIM];
	int x;

	popula_array(array, DIM);
	stampa_array(array, DIM);
	
	cin >> x;

	cout << cerca(x, array, DIM) << endl;
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
