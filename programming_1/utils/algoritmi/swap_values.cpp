//  scambio di variabili senza variabile d'appoggio
void swap_values(int& a, int& b){
    a += b;
    b = a - b;
    a -= b;
}