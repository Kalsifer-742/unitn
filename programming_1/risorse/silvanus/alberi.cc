// Albero ricerca binaria

#include <iostream>
#include <fstream>

using namespace std;

// Definisco la struttura nodo

struct nodo;
typedef nodo * albero;
struct nodo
{
  int value;
  albero left, right;
};

albero init();
bool search(const albero &);
void insert(albero &, int);
void print(const albero &);
void deinit(albero &);

void carica(albero &, char * file);

albero crea_bilanciato_aux(int *, int, int);
albero crea_bilanciato_rec(int *, int);

// si invoca "stampaAlbero(radice);"
void stampaAlbero(albero radice, int spazio=0);

void stampaAlbero(albero radice, int spazio){
   if (radice != NULL) {
    spazio ++;
    
    stampaAlbero(radice->right, spazio);
 
    for (int i = 1; i < spazio; i++) {
        cout<<"\t";
    }
    cout<<radice->value<<"\n";
    
    stampaAlbero(radice->left, spazio);
   }
}

int main(int argc, char * argv[])
{
  if (argc != 2)
  {
    cout << "Usage: a.out <file>" << endl;
    exit(0);
  }
  
  albero t = init();
  
  carica(t, argv[1]);
  
  cout << "Stampa ordinata:" << endl;
  print(t);
  
  deinit(t);
  
  return 0;
}

albero init()
{
  albero t = NULL;
  return t;
}

bool search(const albero & t, int val)
{
  bool found = false;
  
  if (t == NULL)
  {
    found = false;
  }
  else if (val == t -> value)
  {
    found = true;
  }
  else if (val > t -> value)
  {
    found = search (t -> left, val);
  }
  else
  {
    found = search (t -> right, val);
  }
    
  return found;
}

void insert(albero & t, int val)
{
  if (t == NULL)
  {
    albero tmp = new (nothrow) nodo;
    tmp -> value = val;
    tmp -> left = NULL;
    tmp -> right = NULL;
    t = tmp;
  }
  else if (val < t -> value)
  {
    insert(t -> left, val);
  }
  else
  {
    insert(t -> right, val);
  }
}

void print(const albero & t)
{
  if (t != NULL)
  {
    print(t -> left);
    cout << t -> value << endl;
    print(t -> right);
  }
}

void deinit(albero & t)
{
  if (t != NULL)
  {
    deinit(t -> left);
    deinit(t -> right);
    delete t;
  }
}

void carica(albero & t, char * file)
{
  fstream input;
  input.open(file, ios::in);
  
  if (input.fail())
  {
    cout << "Errore nell'apertura del file" << endl;
    input.close();
    exit(0);
  }
  
  int n;
  
  while (input >> n)
  {
    insert(t, n);
  }
  
  input.close();
}

// EXTRA: inserimento da file 'in' ITERATIVO

albero a = nullptr;

int buffer = -1;

while (in >> buffer)
{
  if (a == nullptr)
  {
    a = new nodo;
    
    a -> value = buffer;
    a -> right = nullptr;
    a -> left = nullptr;
  }
  else
  {
    albero current = a;
    
    do
    {
      if (buffer < current -> value)
      {
        if (current -> left == nullptr)
        {
          current -> left = new nodo;
          current -> left -> value = buffer;
          current -> left -> left = nullptr;
          current -> left -> right = nullptr;
          
          current = current -> left;
        }
        else
        {
          current = current -> left;
        }
      }
      else
      {
        if (current -> right == nullptr)
        {
          current -> right = new nodo;
          current -> right -> value = buffer;
          current -> right -> left = nullptr;
          current -> right -> right = nullptr;
        }
        else
        {
          current = current -> right;
        }
      }
    }
    while (current -> value != buffer);
  }

}

// Ricorsivamente, va a metà dell'array, la rende una radice, e tutto ciò che sta a sinistra diventerà parte del ramo sinitro, tutto ciò che nell'array sta a destra diventerà ramo destro

// Lo faccio ricorsivamente per la parte sinistra, poi per quella destra, e così via...

albero crea_bilanciato_aux(int * v, int start, int end)
{
  albero t = nullptr;
  
  if (start <= end)
  {
    
    int mid = ((start + end) / 2);
    
    t = new nodo;
    t -> value = v[mid];
    t -> left = crea_bilanciato_aux(v, start, mid - 1);
    t -> right = crea_bilanciato_aux(v, mid + 1, end);
  }
  
  return t;
}

albero crea_bilanciato_rec(int * v, int DIM)
{
  albero t;;
  
  if (DIM < 1)
  {
    t = nullptr;
  }
  else
  {
    t = crea_bilanciato_aux(v, 0, DIM - 1);
  }
  
  return t;
}
