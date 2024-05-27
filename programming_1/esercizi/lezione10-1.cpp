#include <iostream>
using namespace std;

int fattoriale(int);

int main()
{
	int a;
	cin >> a;
	cout << fattoriale(a) << endl;
}

int fattoriale(int a)
{
	if(a == 0)
	{
		return 1;
	}
	else
	{
		return (a * fattoriale(a-1));
	}
}
