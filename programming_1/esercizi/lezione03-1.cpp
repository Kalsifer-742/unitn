#include <iostream>
using namespace std;

int main(){
	float prezzo, iva;
	cout << "inserire prezzo ed iva "<<endl;
	cin >> prezzo >> iva;
	cout << "prezzo al cliente: " << prezzo + ((prezzo*iva)/100) << endl;
}
