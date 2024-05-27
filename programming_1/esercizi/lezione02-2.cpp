#include <iostream>
using namespace std;

int main()
{
	int ore,minuti,secondi;
	int mezzanotte = 86399;
	int secondi_mancanti;

	cout << "inserire secondi: ";
	cin >> secondi_mancanti;

	ore = secondi_mancanti / 3600;
	minuti = (secondi_mancanti - ore*3600) / 60;
	secondi = (secondi_mancanti - ore*3600 - minuti*60);

	cout << ore <<" "<< minuti <<" "<< secondi << endl;
}
