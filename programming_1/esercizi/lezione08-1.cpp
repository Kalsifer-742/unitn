#include <iostream>
using namespace std;

char conversione(char a);

int main(){
	char a;
	cin >> a;

	if(a >= 97 && a <= 122){
		cout << conversione(a) << endl;
	}
	else{
		cout << a << endl;
	}

	return 0;
}

char conversione(char a){
	return (a -32);
}
