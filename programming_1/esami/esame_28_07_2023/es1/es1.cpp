#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//NON è ammesso utilizzare break, continue e return all'interno dei cicli.
bool match(char* input, char* pattern, int input_len, int pattern_len)
{
    int letter_matched = 0;
    char wildcard = '+';

    //DEBUG
    //cout << input << " " << pattern << endl;
    //cout << input_len << " " << pattern_len << endl;

    if(input_len < pattern_len)
    {
        return false;
    }

    for (int i = 0; i < input_len && (input_len - i) >= pattern_len; i++)
    {
        letter_matched = 0;
        for (int j = 0; j < pattern_len && (input[i + j] == pattern[j] || (pattern[j] == wildcard && input[i + j] != ' ')); j++)
        {
            //DEBUG
            //cout << input[i + j] << " " << pattern[j] << endl;

            letter_matched++;         
        }
    }

    if (letter_matched == pattern_len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char* argv[])
{
    ifstream input;
    input.open("input.txt", ios::in);
    char* pattern = argv[1];
    int pattern_length = strlen(pattern);
    
    //DEBUG
    //cout << "Pattern: " << pattern << endl;

    while (!input.eof())
    {
        char buffer[pattern_length+1];
        input.read(buffer, pattern_length);
        buffer[pattern_length] = '\0';

        //DEBUG
        //cout << buffer << endl;
        
        if(match(buffer, pattern, strlen(buffer), pattern_length))
        {
            cout << "trovata: " << buffer << endl;
        }

        if (!input.eof())
        {
            input.seekg(-(pattern_length - 1), ios::cur);
        }
    }
    
    input.close();

    return 0;
}