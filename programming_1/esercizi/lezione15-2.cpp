#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "parametro file di input mancante" << endl;
		return 0;
	}

	fstream input;
	input.open(argv[1], ios::in);
	if(input.fail()){
		cout << "errore nell'apertura del file" << endl;
		return 0;
	}

	char buffer[2048];
	while(!input.eof()){
		input >> buffer;
		cout << buffer << endl;
	}
	input.close();
	
	return 0;
}