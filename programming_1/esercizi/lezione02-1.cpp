#include <iostream>
using namespace std;

int main()
{
	int ore,minuti,secondi;
	int mezzanotte = 86399;
	int secondi_mancanti;

	cout << "inserire ore minuti e secondi: ";
	cin >> ore >> minuti >> secondi;

	cout << ore << minuti << secondi;

	secondi_mancanti = mezzanotte - (ore*60*60 + minuti*60 + secondi);

	cout << "secondi mancanti: " << secondi_mancanti << endl;
}
