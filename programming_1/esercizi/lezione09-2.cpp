#include <iostream>
#include <cmath>
using namespace std;

double divisione(double,double&);

int main()
{
	double a,b;
	cin >> a >> b;

	cout << divisione(a,b) << " " << b << endl;
}

double divisione(double a, double &b)
{
	double div = (a/b);
	b = fmod(a,b);
	return div;
}
