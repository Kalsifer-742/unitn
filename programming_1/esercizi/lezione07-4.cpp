//65 A => 122 a

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	float tmp = 0;

	cin >> n;

	for(int i = 1; i <= n; i++){
		tmp += (1.0 / (float)(i*i));
	}
	cout.precision(10);
	cout << sqrt(tmp*6) << endl;

	return 0;
}
