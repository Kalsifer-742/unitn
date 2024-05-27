#include <iostream>
using namespace std;

// Definizione della struttura del nodo
struct Node {
    double coefficient;
    Node* next; 
};

// Funzione ricorsiva per calcolare il fattoriale di un numero intero positivo
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Funzione ricorsiva per calcolare i coefficienti del polinomio di Taylor del seno
void taylorCoefficientsRec(double derivatives[], Node*& coefficientsList, int term) {
    
    if (term!=-1){
        double coefficient = derivatives[term] / factorial(term);
        cout << "term: " << term << " Derivates[term]: " << derivatives[term] << " Coefficent: " << coefficient << endl;

        Node* newNode = new Node{coefficient,NULL};
        newNode->next = coefficientsList;
        coefficientsList = newNode;
        
        taylorCoefficientsRec(derivatives, coefficientsList, term -1);
    }
}

void printCoefficients(Node* coefficientsList) {
    if (coefficientsList == nullptr) {
        return; // Caso base: la lista è vuota, quindi termina la ricorsione.
    }

    cout << "Coefficiente: " << coefficientsList->coefficient << endl;

    // Chiamata ricorsiva per stampare il resto della lista
    printCoefficients(coefficientsList->next);
}

// Funzione per deallocare la memoria occupata dalla lista
void deleteList(Node*& coefficientsList) {
    if (coefficientsList != nullptr) {
        if (coefficientsList->next != nullptr)
            deleteList(coefficientsList->next);
        delete coefficientsList;
        coefficientsList = nullptr; // Reimposta il puntatore a nullptr dopo aver deallocato il nodo corrente
    }
}


int main() {
    // Array delle derivate del seno
    double derivatives[] = {0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0};

    // Numero di derivate (termini) del polinomio di Taylor da calcolare
    int n = 7;

    // Lista collegata per i coefficienti del polinomio di Taylor
    Node* coefficientsList = nullptr;

    // Calcola i coefficienti in modo ricorsivo e salvali nella lista
    taylorCoefficientsRec(derivatives, coefficientsList, n);

    // Stampa i coefficienti
    printCoefficients(coefficientsList);

    // Dealloca la memoria occupata dalla lista
    deleteList(coefficientsList);

    printCoefficients(coefficientsList);

    return 0;
}
