
CARICA LA SOLUZIONE NON APPENA RISOLTO UN ESERCIZIO


SE PASSI UN PUNTATORE char * s AD UNA FUNZIONE E VUOI CHE VENGA MODIFICATO
LA FUNZIONE DEVE ACCETTARE char* &t, REFERENCE AD UN PUNTATORE


Gli operatori >> ignorano gli spazi, gli \t e gli \n
MA SE METTI stream >> noskipws NON LI IGNORA
cin.get(c)  legge un singolo carattere, spazi compresi (restituisce \0 se eof)
cout.put(c) scrive un singolo carattere
 
stream.eof()  ritorna true (un valore != 0) se lo stream ha raggiunto la sua fine
stream.fail() ritorna true (un valore != 0) se lo stream ha rilevato un errore o un eof

.eof() VA FATTO DOPO ALMENO UNA OPERAZIONE DI LETTURA

Per pulire il cin da eventuali errori

if (cin.fail())
{
  cout << "Errore: tipo di dato errato";

  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



typedef tipo alias;     // es. typedef long Integer;
typedef tipo alias[];   // es. typedef int Sequence[];



QUANDO FAI UNA DIVISIONE FRA INTERI, IL RISULTATO SARÀ UN NUMERO INTERO
DEVI SPECIFICARE IL TIPO (es. 10 / (float) 3)



Nelle assegnazioni exp1 = exp2, exp2 viene prima calcolata, poi assegnata
Cosa che non accade con gli operatori && e || (lazy evaluation)



enum nome_1 {id_1 = val_1, id_2 = val_2, ..., id_N = val_N};
enum nome_2 {id_1, id_2, ..., id_N};

nome_1 casa = id_3;
cout << id_3 << endl;



// Precisione di stampa

#include <iomanip>

cout << setw(n)      imposta la spaziatura di determinati valori in stampa

cout.precision(n)    stampa solo n cifre (es. n = 5, di 32.2334411 stampo 32.233)
cout << fixed        inizia a contare le cifre solo dopo la virgola (quindi 32.23344)
cout << defaultfloat riporta la precisione di stampa a quella di default



int x = 6;
int &y = x;       sinonimo di x, puntano e operano sulla stessa area di memoria
int * px = &x;    px ha come r-value la posizione in memoria di x (l-value di x)
int ** pxx = &px; pxx ha come r-value la posizione in memoria di px
cout << *px;      dereference, stampa il valore contenuto in x (r-value di x)



sizeof() restituisce la dimensioni in byte di una variabile/costante/tipo



PUNTATORI

Per inizializzare un puntatore puoi usare int * px = 0;   // uguale a int * px = NULL

Per verificare che un puntatore non sia NULL

if (px)   restituisce FALSE se px == NULL, TRUE in tutti gli altri casi
{
  ...
}

const int * id_1;             POSSO puntare ad una nuova costante, NO modifica per dereference
int * const id_2 = exp;       NO puntare a nuovo oggetto, POSSO modifica per dereference
const int * const id_3 = exp; NO puntare a nuovo oggetto, NO modifica per dereference



Aritmetica dei puntatori, puoi usarla per gli array (?)

int * px = &x;  prima assegno a px la posizione in memoria di x, poi quella di
px++;           un intero che si trova subito dopo nella memoria

px += i         esegue implicitamente 3 * sizeof(int) (si sposta di 12 byte)

px < (px + 1)   posso applicare operatori di confronto

* pv + 1        corrisponde a (* pv) + 1, NON a * (pv + 1)
* pv++          corrisponde a * (pv ++), NON a (* pv)++

se p punta ad un elemento di un array, p+i punta all'indirizzo dell'i-esimo elemento dell'array

se due puntatori p1 e p2 di tipo T puntano ad un array di T
p2-p1 denota il numero di elementi compresi tra p1 e p2

PASSAGGIO DI PARAMETRI

(int a, int b)                  per valore, copia locale dei valori, non modifica gli originali

(int & a, int & b)              per riferimento ai param. attuali, modifica gli originali
(int * a, int * b)              per puntatore ai param. attuali, modifica gli originali

(const int & a, const int & b)  per riferimento costante, riferimento ma non modifica gli originali

(int a, int b, int c = 0)       si possono mettere degli argomenti di default NELLA DICHIARAZIONE
                                (con i parametri con valore di default tutti a destra di quelli senza)



FUNZIONI RICORSIVE

-> una o più condizioni di terminazione
-> uno o più chiamate ricorsive



// Switch statement

switch (exp)
{
  case 1:
    cout << "No" << endl; break;
  case 2:
    cout << "Assolutamente no" << endl;
    break;
  case 3:
  {
    cout << "Ma figuriamoci" << endl;
    break;
  }
  default:
  cout << "Va bene" << endl;
    break;
}

// Non mettendo break; se exp == 1, esegui solo case 1:
// Mentre se exp == 2 eseguo fino a default compreso (esegue fino ad un break;)

switch (exp)
{
  case 1:
    cout << "Forse " << endl;
    break;
  case 2:
    cout << "Magari..." << endl;
  case 3:
    cout << "Vuoi vedere che..." << endl;
  default:
    cout << "no" << endl;
}



ARRAY

int v[100];       array di 100 interi
int v[10] = {};   array di 10 interi, inizializzato a zero
int v[] = {1, 2}  array di 2 interi

float sum(float v[], int dim);   non metto la dim fra parentesi, la passo come parametro
                                 nel passaggio viene copiato solo la posizione della prima cella
                                 in memoria (equivale a passare tutti gli elementi per riferimento)
int f(const int v[], int dim);   per impedire di modificare gli elementi metto const
int f(const int * v[], int dim);


MATRICI

int m[dim1][dim2]...[dimN];
int m[dim1][dim2]...[dimN] = {{...}, {...}, ..., {...}};
int m[][dim2]...[dimN] = {{...}, {...}, ..., {...}};

int m[9][2] = {{}};             ha inizializzato a zero il resto
int m[4][3] = {{5, 4, 9}, {}};  ha inizializzato il resto

void stampa(int m[][dim2]...[dimN], int dim1, int dim2, ..., int dimN);



STRINGHE

char s[] = "ciao";            così e dagli stream il \0 viene messo in automatico
char s[] = {'N', 'o', '\0'};  qui va specificato, sennò è solo un array di char

>> legge caratteri da uno stream finché non incontra una spaziatura (ignorata)
<< stampa fino al primo \0

cin.getline(s, num, ch) legge una stringa e la mette in s fino a n-1 caratteri, o fino a ch (se ch è \n non serve metterlo) (che ignora) restituisce un equivalente a 0 se incontra eof

cin.get(c)  legge un singolo carattere, spazi compresi (restituisce \0 se eof)
cout.put(c) scrive un singolo carattere



ARGOMENTI LINEA DI COMANDO

int main(int argc, char * argv[])

CONVERTIRE STRINGHE IN numeri

#include <cstdlib>

int n = atoi(argv[1]);
float a = atof(argv[2]);

FILE

#include <fstream>

fstream stream;
stream.open(file, ios::in)  lettura
                  ios::out  scrittura da 0, crea, svuota un file se necessario
                  ios::app  aggiungere ad un file, non cancella il contenuto

CHIUDERE GLI STREAM con stream.close();

if (argc != n)
{
  cerr << "Utilizzo: " << endl;
  exit(1);
}

// apertura file

if (stream.fail())
{
  cerr << "Errore nella gestione dei file" << endl;
  
  stream.close();
  exit(1);
}

1° MODO

char buffer[256];
input >> buffer;
while (!input.eof())
{
  input >> buffer;
}
output << buffer;

2° MODO

char buffer[256];
while (input >> buffer)
{
  output << buffer;
}

STRUTTURE, è preferito allocare dinamicamente

oggetto.campo                 per accedere ad un campo
puntatore_a_oggetto -> campo  se ho un puntatore (tipo puntatore a nodo)

array, gestisco come un campo
struct int_array { int v[3];};
int_array a, b; a.v[2] = 5; b = a copia tutto array in b (meglio per rif. costante)

array dinamico, gestisco come un puntatore
struct int_array { int * v;};
int_array a, b; a.v = new int[3]; b = a copia indirizzo di a.v in b.v

STRUTTURE RICORSIVE

struct S
{
  int value;
  S * next;
}

STRUTTURE MUTUALMENTE RICORSIVE

struct s2;

struct s1
{
  int value;
  s2 * next;
};

struct s2
{
  int value;
  s1 *  next;
}

GESTIONE DINAMICA DELLA MEMORIA

int * n = new int;  delete n;

int * v = new int[dim]; delete [] v;

int ** M = new int*[dim1];
for (int i = 0; i < dim1; i++)
{
  M[i] = new int[dim2];
}
for (int i = 0; i < dim1; i++)
{
  delete [] M[i];
}
delete [] M;

char * s = new char[dim]; dove dim tiene conto di lunghezza + \0

QUANDO ALLOCHI USA

char * p = new (nothrow) char[dim];

if (p != NULL)
{
  ...
}

perché se non ho memoria, new restituisce NULL



FILE .H

#ifndef MODULO_I_H
#define MODULO_I_H
// dichiarazioni di struct, costanti, var globali, di funzioni
#endif

FILE .CC

modulo_i.cc

#include "modulo_i.h"
//definizione di funzioni, se vuole funzioni ausiliarie


PILA/STACK

Una pila è una collezione di dati omogenei (e.g., puntatori a struct) in cui gli elementi sono gestiti in modo LIFO (Last In First Out)
Viene visualizzato/estratto l’elemento inserito più recentemente Es: una scatola alta e stretta contenente documenti
Operazioni tipiche definite su una pila di oggetti di tipo T:
init()/deinit(): inizializza/deinizializza la pila
push(T): inserisce elemento sulla pila; fallisce se piena
pop(): estrae l’ultimo elemento inserito (senza visualizzarlo); fallisce se vuota top(T &): ritorna l’ultimo elemento inserito (senza estrarlo); fallisce se vuota
Varianti:
pop() e top(T &) fuse in un’unica operazione pop(T &) talvolta disponibili anche print()
[ deinit() non sempre presente]

CODA/QUEUE

Una coda è una collezione di dati omogenei in cui gli elementi sono gestiti in modo FIFO (First In First Out)
Viene visualizzato/estratto l’elemento inserito meno recentemente Es: una coda ad uno sportello
Operazioni tipiche definite su una coda di oggetti di tipo T:
init()/deinit(): inizializza/deinizializza la coda
enqueue(T): inserisce elemento sulla coda; fallisce se piena
dequeue(): estrae il primo elemento inserito (senza visualizzarlo); fallisce se vuota first(T &): ritorna il primo elemento inserito (senza estrarlo); fallisce se vuota
Varianti:
dequeue() e first(T &) fuse in un’unica operazione dequeue(T &) talvolta disponibili anche print()
[ deinit() non sempre presente]

ALBERI

I sottoalberi (possibilmente vuoti) di un nodo N sono detti sottoalbero sinistro e sottoalbero destro di N
Se un nodo N punta nell’ordine a due (eventuali) nodi N1, N2
  N1 e N2 sono detti rispettivamente figlio sinistro e figlio destro di N N è detto nodo padre di N1 e N2
In un albero binario ci possono essere tre tipi di nodi:
  Il nodo radice, che non ha padre
  I nodi foglia, che non hanno figli
  I nodi intermedi, che hanno padre e almeno un figlio

Una catena di nodi dalla radice a una foglia è detta ramo
  Il numero di nodi in un ramo è detto lunghezza del ramo
  La massima lunghezza di un ramo è detta altezza dell’albero
  L’altezza di un albero binario di N elementi è h ∈ [⌈log2(N + 1)⌉, N]
Un albero binario di N elementi è bilanciato se la sua altezza è h = ⌈log2(N + 1)⌉ =⇒ tutti i rami hanno lunghezza h o h-1
Un albero binario di N elementi è completo se la sua altezza è tale che N = 2h − 1 =⇒ tutti i rami hanno lunghezza h

...quindi per creare un albero bilanciato si lavora sull'inserimento

TRAMITE ARRAY

Dati:
un array v di dim elementi di tipo T
un (sotto)albero è dato da un puntatore a v e un indice i structtree{ T*v;inti;};
v allocato dinamicamente
l’elemento radice è in v[0]
se un elemento è in posizione v[i], i suoi due figli sono in posizione v[2*i+1] e v[2*i+2]
necessaria una nozione ausiliaria di “elemento vuoto”
Funzionalità: come nell’implementazione precedente, cambia solo la nozione di figlio sinistro/destro

Calcolatrice RPM

Il metodo di calcolo Reverse Polish Notation (RPN) funziona postponendo l’operatore ai due operandi
34 * 3=⇒34 3 *
Permette di effettuare complicate concatenazioni di conti senza usare parentesi:
(34 * 3)/(31 - 5) + (21+3)/(24-12) =⇒ 34 3 * 31 5 - / 21 3 + 24 12 - / +
Una calcolatrice RPN funziona nel modo seguente:
se viene immesso un operando, si inserisce in uno stack di operandi se viene immesso un operatore (binario) op:
1. vengono prelevati dallo stack gli ultimi due operandi op1 e op2 2. viene applicato l’operatore op a op2 e op1
3. il risultato viene ri-immesso nello stack
l’ultimo elemento nello stack contiene il risultato dell’espressione

Coda a priorità

Una coda a priorità di messaggi è una struttura dati in cui ogni messaggio arrivato ha una priorità in [0..10]
i messaggi vengono estratti in ordine di priorità, 0 =⇒ 1 =⇒ 2 ... a parità di priorità vengono estratti in modo FIFO
Realizzabile con un array di code, una per ogni livello di priorità:
un messaggio di priorità i viene inserito nella coda i-esima
l’estrazione avviene a partire dalla coda 0-sima: se vuota si passa alla successiva, ecc.
Esempio: l’accettazione al Pronto Soccorso di un ospedale

Rubbrica

Una Rubbrica è una lista di (dati di) persone, ordinata con qualche criterio (es per cognome)
realizzata come un albero di ricerca binaria di TDA “persona” albero ordinato per il campo “cognome”
importante utilizzare puntatori a persona:
=⇒ ogni copia/passaggio è il passaggio solo di un puntatore
per semplicità, non è possibile eliminare una persona dalla rubbrica

Rubbrica doppia

Una Rubbrica Doppia è una lista di (dati di) persone, ordinata con un doppio criterio (es per cognome e per nome)
realizzata come una coppia di alberi di ricerca binaria di puntatori al TDA “persona” albero ordinato per il campo “cognome”
albero ordinato per il campo “nome”
importante utilizzare puntatori a persona:
=⇒ ogni copia/passaggio è il passaggio solo di un puntatore ogni TDA “persona” è condiviso tra i due alberi
per semplicità, non è possibile eliminare una persona dalla rubbrica doppia

Calcolatrice standard

Un’espressione aritmetica standard utilizza operatori (binari) infissi e parentesi:
((34 * 3)/(31 - 5) + (21+3)/(24-12))
Un’espressione aritmetica standard può essere rappresentata da un albero binario
  le foglie contengano numeri
  gli altri nodi contengano operatori
Un’espressione viene letta e creata ricorsivamente come segue:
  se viene letto un numero, viene creata un’espressione foglia
  altrimenti (viene letta una parentesi aperta):
    viene creato un nodo intermedio
    viene letta e creata ricorsivamente la prima espressione, e assegnata al figlio sinistro
    viene letto l’operatore, ed inserito nel nodo
    viene letta e creata ricorsivamente la seconda espressione, e assegnata al figlio destro
    viene letta la parentesi chiusa
Un’espressione viene valutata ricorsivamente come segue:
  se è una foglia, viene restituito il suo valore
  altrimenti, si valutano ricorsivamente i due sottoalberi, e vi si applica l’operatore del nodo


