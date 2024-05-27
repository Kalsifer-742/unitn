#include <iostream>
#include <time.h>
using namespace std;

void popula_matrice(int m[][10], int r, int c);
void stampa_matrice(int m[][10], int r, int c);

int main(){
	const int DIM = 10;
	int array[DIM][DIM];

	popula_matrice(array, DIM, DIM);
	stampa_matrice(array, DIM, DIM);	
}

void popula_matrice(int m[][10], int r, int c){
	srand (time(NULL));	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			m[i][j] = rand() % 10;
		}
	}
}

void stampa_matrice(int m[][10], int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << " [" << m[i][j] << "] ";
		}
		cout << endl;
	}
}
