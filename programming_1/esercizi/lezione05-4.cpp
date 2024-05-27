#include <iostream> 
#include <cmath>
using namespace std;
int main(){
	int a;
	cin >> a;
	switch(a){
		case 1:
		       	cout << "lunedì" << endl;
			
			break;
		case 2:
			cout << "materdì" << endl;
			
			break;
		case 3:
			cout << "mercoledì" << endl;

			break;
		case 4:
			cout << "giovedì" << endl;
	
			break;
		case 5:
			cout << "venerdì" << endl;
	
			break;
		case 6:
			cout << "sabato" << endl;
		
			break;
		case 7:
			cout << "domenica" << endl;
	
			break;
		default:
			cout << "sicuramente si tratta di un input" << endl;
			break;			
	}

	return 0;
}
