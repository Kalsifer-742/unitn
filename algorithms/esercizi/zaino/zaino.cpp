#include <iostream>
#include <fstream>
using namespace std;

struct oggetto
{
    int peso;
    int valore;
};

int max_value(oggetto ogg[], int l, int i, int c)
{ 
    if (i == l)
    {
        return 0;
    }

    if (ogg[i].peso > c)
    {
        return max_value(ogg, l, i+1, c);
    }
    
    int oggetto_non_preso = max_value(ogg, l, i+1, c);
    int oggetto_preso = ogg[i].valore + max_value(ogg, l, i+1, c - ogg[i].peso);

    int massimo = max(oggetto_non_preso, oggetto_preso);

    return massimo;
}

int main()
{
    fstream input, output;
    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    int C, N;
    input >> C >> N;

    oggetto oggetti[N];
    int mem[N][C];

    for (int i = 0; i < N; i++)
    {
        input >> oggetti[i].peso >> oggetti[i].valore;
    }

    input.close();
    
    output << max_value(oggetti, N, 0, C);

    output.close();

    return 0;
}