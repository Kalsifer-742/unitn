#include <iostream>
using namespace std;

void conversione(char &a);

int main(){
	char a;
	cin >> a;

	if(a >= 97 && a <= 122){
		conversione(a);
		cout << a << endl;
	}
	else{
		cout << a << endl;
	}

	return 0;
}

void conversione(char &a){
	a -= 32;
}
