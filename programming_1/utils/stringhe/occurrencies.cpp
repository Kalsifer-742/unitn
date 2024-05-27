#include <fstream>

using namespace std;

int occurrencies(char word[], char file[]);

int occurrencies(char word[], char file[])
{
    fstream input;
    input.open(file, ios::in);

    char buffer[256];
    int c = 0;
    while (input >> buffer)
    {
        if (equal_string(word, buffer))
        {
            c++;
        }
    }

    input.close();

    return c;
}