//  ritorna il valore assoluto della differenza tra 2 numeri
int absolute_value(int a, int b){
    return ( (a - b) * ( (a > b) - (b > a) ) );
}