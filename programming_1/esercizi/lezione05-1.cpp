#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a,b,c,delta;
	cin >> a >> b >> c;
	delta = b*b - 4*a*c;
	if(delta < 0){
		cout << "bella raga" << endl;
		return 0;
	}
	cout << (-b + sqrt(delta))/(2*a) << (-b - sqrt(delta))/(2*a) << endl;
	return 0;
}
