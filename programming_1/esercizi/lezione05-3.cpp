#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	if(a<b){
		cout << 1 << endl;
		return 0;
	}
	else if(a > c){
		cout << 0 << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}
