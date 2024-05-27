#include <iostream>
using namespace std;

void dec_to_bin(int);

int main()
{
	int n;
	cin >> n;
	dec_to_bin(n);
}

void dec_to_bin(int n)
{
	if( n == 1 ){
		cout << 1;
	}else{
		dec_to_bin(n/2);	
		cout << n % 2; //invertiti non andrebbe bene. Importante il concetto di risalita
	}
}
