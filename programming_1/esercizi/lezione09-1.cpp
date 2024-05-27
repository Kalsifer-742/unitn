#include <iostream>
using namespace std;

void scambio(double *,double *);

int main()
{
	double a,b;
	cin >> a >> b;
	
	scambio(&a,&b);

	cout << a << " " << b << endl;
}

void scambio(double *a, double *b)
{
	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
