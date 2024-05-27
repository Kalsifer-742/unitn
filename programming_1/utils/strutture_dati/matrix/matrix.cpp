#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void initialize_matrix(int m[][10], int r, int c);
void print_matrix(int m[][10], int r, int c);

void initialize_matrix(int m[][10], int r, int c){
	srand (time(NULL));	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			m[i][j] = rand() % 10;
		}
	}
}

void print_matrix(int m[][10], int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << " [" << m[i][j] << "] ";
		}
		cout << endl;
	}
}