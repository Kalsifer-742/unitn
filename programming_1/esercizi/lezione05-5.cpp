#include <iostream> 
#include <cmath>
using namespace std;
int main(){
	int a,n;
	cin >> a >> n;
	int c = 1;
	while(c <= n){
		cout << pow(a,c) << " ";
		c++;
	}
	cout << endl;

	return 0;
}
