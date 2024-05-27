// FUNZIONI

bool is_prime_it(const int& num);
bool is_prime_aux(const int& num, int i);
bool is_prime_rec(const int& num);

long long fact_it(int n);
long long fact_rec(int n);

long long comb(int n,int k);
int mcd(int a, int  b);

long long fib_it(int n);
long long fib_rec(int n);

// ALTRO

// Generazione numeri casuali
// Equazioni di secondo grado
// Piramide di *
// Scambio di 8 bit tra due short
// Stampa fattorizzazione in numeri primi
// Matematica
// Correzione sintassi


bool is_prime_it(const int& num)
{
  bool retval = true;
  
  if (num < 2)
  {
    retval = false;
  }
  else
  {
    for (int i = 2; i < num && retval; i++)
    {
      if ((num % i) == 0)
      {
        retval = false;
      }
    }
  }
  
  return retval;
}

bool is_prime_aux(const int& num, int i)
{
  bool retval = true;
  
  if (i > num)
  {
    retval = false;
  }
  else
  {
    if (num % i == 0)
    {
      if (num == i)
      {
        retval = true;
      }
      else
      {
        retval = false;
      }
    }
    else
    {
      retval = is_prime_aux(num, i + 1);
    }
  }
  
  return retval;
}

bool is_prime_rec(const int& num)
{
  return is_prime_aux(num, 2);
}

// Genera numeri random nel range [0 - (N - 1)]

#include <cstdlib>
#include <ctime>

srand(time(NULL));

int x = rand() % N;

// Genera un numero random nel range [start - end]

#include <cstdlib>
#include <ctime>

srand(time(NULL));

int random(int start, int end)
{
  if (start > end)
  {
    int t = start;
    start = end;
    end = t;
  }
  
  int interval = end - start + 1;
  
  int n = rand() % interval + start;
    
  return n;
}

// Scambio di valori senza l'uso di una terza variabile

a += b;
b = a - b;
a -= b;

// Somma in valore assoluto di due numeri, senza libreria

int valore_assoluto = (a - b) * ((a > b) - (b > a));

// Massimo e minimo senza utilizzare if-else

int massimo = a * (a >= b) + b * (a < b);
int minimo = (a + b) - massimo;

// Fattoriale, iterativo e ricorsivo

long long fact_it(int n)
{
  long long fattoriale = 1;
  
  for (int i = 1; i <= n; i++)
  {
    fattoriale *= i;
  }
  
  return fattoriale;
}

long long fact_rec(int n)
{
  long long res;
  
  if (n == 0)
  {
    res = 1;
  }
  else
  {
    res = n * fact_rec(n - 1);
  }
  
  return res;
}

// Combinazioni semplici (n k) = (n!)/(k!(n-k)!)

long long comb(int n,int k)
{
  long long ris;
  
  ris = fatt(n);
  
  ris /= fatt(k);
  
  ris /= fatt(n - k);
  
  return ris;
}

// Massimo Comune Divisore (MCD), iterativo e ricorsivo

int mcd(int a, int  b)
{
  int resto;
  
  while (b!=0)
  {
    resto = a % b;
    a = b;
    b = resto;
  }
  
  return a;
}

int mcd(int a, int b)
{
  int retval;
  
  if (b == 0)
  {
    retval = a;
  }
  else
  {
    retval = mcd(b, a % b);
  }
  return retval;
}

// Fibonacci, iterativo e ricorsivo

long long fib_it(int n)
{
  long long fn , fnmenouno, fnmenodue;
  
  if (n == 0 || n == 1)
  {
    fn = 1;
  }
  else
  {
    fnmenodue = 1;
    fnmenouno = 1;
    
    for (int i = 2; i <= n; i++)
    {
      fn = fnmenouno + fnmenodue;
      fnmenodue = fnmenouno;
      fnmenouno = fn;
    }
  }
  
  return fn;
}

long long fib_rec(int n)
{
  long long res;
  
  if (n == 0 || n == 1)
  {
    res = 1;
  }
  else
  {
    res = fib_rec(n - 1) + fib_rec(n - 2);
  }
  
  return res;
}

// Equazioni di secondo grado: ax^2 + bx + c = 0

#include <cmath>

double a, b, c;

cout << "Inserisci tre coefficienti:" << endl;
cin >> a >> b >> c;

double x1, x2, delta;

if (a != 0)
{
  delta = (b * b) - 4.0 * (a * c);
  
  if (delta < 0)
  {
    cout << "x1: " << -b/(2.0*a) << " + " << sqrt(-delta) / (2.0 * a) << "i" << endl;
    cout << "x2: " << -b/(2.0*a) << " - " << sqrt(-delta) / (2.0 * a) << "i" << endl;
  }
  else
  {
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
    
    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;
  }
}
else
{
  // Risulta essere 0 == 0
  if ((b == 0) && (c == 0))
  {
    cout << "Infinite soluzioni" << endl;
  }
  // Retta parallela all'asse delle ascisse
  if ((b == 0) && (c != 0))
  {
    cout << "Non esiste soluzione" << endl;
  }
  // Retta
  if (b != 0)
  {
    cout << "Unica soluzione: " << -c/b << endl;
  }
}

// Piramide di *

int height = 5;

for (int i = 0; i < height; i++)
{
  for (int j = 0; j < (height - i) - 1; j++)
  {
    cout << " ";
  }
  
  for (int j = 0; j < ((i + 1) * 2) - 1; j++)
  {
    cout << "*";
  }
  
  cout << endl;
}

// Scambio di 8 bit tra due short

#include <iostream>

using namespace std;

void swapHalf(short * n1, short * n2);

int main() {

    short n1, n2;
    n1 = 1855;
    n2 = 1048;

    cout << "n1 " << n1 << ", n2 " << n2 << endl;

    swapHalf(&n1, &n2);

    cout << "n1 " << n1 << ", n2 " << n2 << endl;

    return 0;
}

void swapHalf(short * n1, short * n2) {

    // n1 = 0000011100111111
    //      ^        ^
    //      |        |
    //     ptr1    ptr1+1

    // Char occupa 1 byte, mentre short occupa 2 byte. Se creiamo un puntatore
    // ad uno short converito in char, il puntatore si porrò all'inizio del mio
    // short, però avrà dimensione dimezzata.
    // Perciò, facendo pn1+1, io vado a posizionarmi a metà del valore short
    // originario. Inoltre, facendo l'assegnamento *(pn1+1) = *(pn2+1); vado a
    // sovrascrivere metà dello short originario con la metà dell'altro short.
    // Vedere schema superiore:

    char * pn1 = (char *) n1;
    char * pn2 = (char *) n2;

    char tempSecondHalfN1 = *(pn1+1*sizeof(char));
    *(pn1+1) = *(pn2+1);
    *(pn2+1) = tempSecondHalfN1;
}

// Stampa fattorizzazione in numeri primi
// Necessita di una funzione per dire se un numero è primo (qui is_prime_rec())

void fatt_aux(int n, int i)
{
  if (i <= n)
  {
    if ((n % i == 0) && is_prime_rec(i))
    {
      cout << i << " ";
      fatt_aux(n / i, i);
    }
    else
    {
      fatt_aux(n, i + 1);
    }
  }
}

void fatt_rec(int n)
{
  if (n < 1)
  {
    cout << "Valore non valido" << endl;
  }
  else if (n == 1)
  {
    cout << 1 << endl;
  }
  else
  {
    fatt_aux(n, 2);
    cout << "\b \b" << endl;
  }
}

// Matematica

#include <cmath>

exp(x)     calcola e^(x)
exp2(x)    calcola 2^(x)
log(x)     calcola log in base e di x
log2(x)    calcola log in base 2 di x
log10(x)   calcola log in base 10 di x
pow(a, b)  calcola a elevato alla b
sqrt(x)    calcola la radice quadrata di x
ceil(x)    arrotonda per eccesso x (es. ceil(2.3) = 3)
floor(x)   arrotonda per difetto x (es. floor(2.8) = 2)
abs(x)     ritorna |x| per i numeri interi
fabs(x)    ritorna |x| per i numeri reali

// Cambio di base

loga(b) = log(b)/log(a) cambio di base

// CORREZIONE SINTASSI
// Prima lettera prima parola maiuscola e prima lettera parole dopo  . ? ! maiuscole

#include <iostream>
#include <fstream>
using namespace std;

bool is_space(char c)
{
  return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int my_strlen(const char * s)
{
  int length;
  
  for (length = 0; s[length] != '\0'; length++);
  
  return length;
}

bool is_lower(char c)
{
  return (c >= 'a' && c <= 'z');
}

char to_upper(char c)
{
  return (c - ('a' - 'A'));
}

bool is_alpha(char c)
{
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int main(int argc, char * argv[])
{
  // Senza controlli sull'input e sui file!!!
  fstream in, out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);
  
  char c;
  
  bool prima_parola  = true;
  bool da_modificare = false;
  bool nuova_parola = false;
  
  while (in.get(c))
  {
    // Se trovo il primo carattere della prima parola
    
    if (prima_parola)
    {
      // Se è una lettera, la rendo maiuscola
      
      if (is_alpha(c) && is_lower(c))
      {
        c = to_upper(c);
      }
      
      // Niente più prima parola
      
      prima_parola = false;
    }
    else
    {
      // Se trovo un carattere che non è uno spazio...
      
      if (!is_space(c))
      {
        // Se ho da cambiare una lettera e sono in una nuova parola
        
        if (da_modificare && nuova_parola)
        {
          if (is_alpha(c) && is_lower(c))
          {
            c = to_upper(c);
          }
          
          da_modificare = false;
          nuova_parola = false;
        }
        
        // Se trovo un carattere speciale
        
        if (c == '.' || c == '?' || c== '!')
        {
          da_modificare = true;
        }
      }
      else
      {
        // Se trovo uno spazio significa che ho finito una parola
        // Quindi sarà poi in una nuova
        
        nuova_parola = true;
      }
    }
    out << c;
  }
    
  in.close();
  out.close();
}
