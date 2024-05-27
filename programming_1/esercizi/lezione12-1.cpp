#include <iostream>
using namespace std;

int main(){
	srand (time(NULL));

	int array[10];
	for(int i=0;i<5;i++){
		array[i]=rand() % 10 + 1;
	}
	for(int i=0;i<5;i++){
		cout << array[i];
	}
}
