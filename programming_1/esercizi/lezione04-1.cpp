//g++ -Wall codice.cpp

#include <iostream>
using namespace std;

int main(){
	int a,b, abs;
	cin >> a >> b;
	abs = (a - b) * ( (a > b) - (a < b) ); //in c++ True e False sono anche 0 e 1	
	cout << abs << endl;
}
