#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//strstr(input, pattern) != NULL
bool verifica(char parola[], char pattern[])
{
    int dim = strlen(pattern);
    bool found = false;
    //cout << parola << " " << pattern << endl;
    
    for (int i = 0; parola[i] != '\0'; i++)
    {
        for (int j = 0, k = i; j < dim && (parola[k] == pattern[j] || pattern[j] == '+'); j++, k++)
        {
            //cout << k << " " << parola[k] << " " << j << " " << pattern[j] << endl;
            if (j == dim - 1)
            {
                found = true;
            }
        }
    }

    return found;
}

int main(int argc, char * argv[]){
    char pattern[] = "+me+";
    ifstream in;
    in.open("input.txt", ios::in);

    char buffer[255];
    while(in >> buffer)
    {
        if(verifica(buffer, pattern))
        {
            cout << "trovata: " << buffer << endl;
        }
    }

    in.close();

    return 0;
}