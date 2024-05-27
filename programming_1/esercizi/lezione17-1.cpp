#include <iostream>
#include <cstring>
using namespace std;

struct Studente{
    char nome[20];
    char cognome[20];
    int matricola;
    float media;
};

void stampa_studente(const Studente &S);
Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);

int main()
{
    Studente s = genera_studente("Mario", "Rossi", 339768, 24);
    stampa_studente(s);

    return 0;
}

void stampa_studente(const Studente &S){
    cout << S.nome << " " << S.cognome << " " << S.matricola << " " << S.media << endl;
}

Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata){
    Studente studente;
    strcpy(studente.nome, nome);
    strcpy(studente.cognome, cognome);
    studente.matricola = matricola;
    studente.media = media_ponderata;

    return studente;
}