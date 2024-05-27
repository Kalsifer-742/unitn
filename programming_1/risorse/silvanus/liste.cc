struct nodo;
typedef nodo * lista;

struct nodo
{
  int info;
  lista next;
};

void crea_lista(lista &l, char * path);

void inserimento_testa(lista &l, int n);
void inserimento_coda(lista &l, int n);

void inserimento_coda_aux(lista l, lista p);
void inserimento_coda_rec(lista &l, int n);

void stampa_lista(lista l);
void stampa_lista_invertita_aux(lista l);
void stampa_lista_invertita_rec(lista l);

int lunghezza_lista_it(lista l);
int lunghezza_lista_rec(lista l);

int lunghezza_circolare_it(lista s, lista x);

void rovescia_lista_aux(lista l, lista p, lista &current, lista &nodo_finale);
void rovescia_lista_rec(lista &l);

void append_lista(lista &l, lista m);

void bubblesort_aux(lista l, int first, int last);
void bubblesort_rec(lista l, int size);

bool linear_search(lista l, int n);

void elimina_lista(lista l);

// Crea una lista a partire da un file
// Se la lista è vuota la crea, altrimenti aggiunge nodi
void crea_lista(lista &l, char * path)
{
  fstream in;
  in.open(path, ios::in);
  
  if (in.fail())
  {
    cerr << "Errore nell'apertura del file" << endl;
    in.close();
    exit(1);
  }
  
  int buffer;
  lista current = l;
  bool primo;
  
  if (l == nullptr)
  {
    primo = true;
    current = l;
  }
  else
  {
    primo = false;
    while (current -> next != nullptr)
    {
      current = current -> next;
    }
  }
  
  while (in >> buffer)
  {
    if (primo)
    {
      l = new nodo;
      l -> info = buffer;
      l -> next = nullptr;
      
      current = l;
      
      primo = false;
    }
    else
    {
      lista p = new nodo;
      
      p -> info = buffer;
      p -> next = nullptr;
      
      current -> next = p;
      current = p;
    }
  }
  
  in.close();
}

void inserimento_testa(lista &l, int n)
{
  lista p = new nodo;
  
  p -> info = n;
  p -> next = l;
  
  l = p;
}

void inserimento_coda(lista &l, int n)
{
  lista p = new nodo;
  
  p -> info = n;
  p -> next = nullptr;
  
  if (l == nullptr)
  {
    l = p;
  }
  else
  {
    lista tmp = l;
    
    while (tmp -> next != nullptr)
    {
      tmp = tmp -> next;
    }
    tmp -> next = p;
  }
}

void inserimento_coda_aux(lista l, lista p)
{
  if (l -> next == nullptr)
  {
    l -> next = p;
  }
  else
  {
    inserimento_coda_aux(l -> next, p);
  }
}

void inserimento_coda_rec(lista &l, int n)
{
  lista p = new nodo;
  
  p -> info = n;
  p -> next = nullptr;
  
  if (l == nullptr)
  {
    l = p;
  }
  else
  {
    inserimento_coda_aux(l, p);
  }
}


void stampa_lista(lista l)
{
  if (l != nullptr)
  {
    while (l != nullptr)
    {
      cout << l -> info << " ";
      l = l -> next;
    }
    cout << "\b \b" << endl;
  }
}

void stampa_lista_invertita_aux(lista l)
{
  if (l != nullptr)
  {
    if (l -> next != nullptr)
    {
      stampa_lista_invertita_aux(l -> next);
    }
    cout << l -> info << " ";
  }
}

void stampa_lista_invertita_rec(lista l)
{
  if (l != nullptr)
  {
    stampa_lista_invertita_aux(l);
    cout << "\b \b" << endl;
  }
}

int lunghezza_lista_it(lista l)
{
  int length = 0;
  
  for (; l != nullptr; l = l -> next)
  {
    length++;
  }
  
  return length;
}

int lunghezza_lista_rec(lista l)
{
  int retval = 0;
  
  if (l != nullptr)
  {
    if (l -> next != nullptr)
    {
      retval += lunghezza_lista_rec(l -> next);
    }
    retval += 1;
  }
  
  return retval;
}

// lista circolare, x primo elemento
int lunghezza_circolare_it(lista s, lista x)
{
  int l = 0;
  
  if (s != nullptr)
  {
    l = 1;
    for(s = s -> next; s != x; s = s -> next)
    {
      l++;
    }
  }
  return l;
  
}

void rovescia_lista_aux(lista l, lista p, lista &current, lista &nodo_finale)
{
  if (l -> next == nullptr)
  {
    nodo_finale = l;
    current = nodo_finale;
    
    current -> next = p;
    current = current -> next;
  }
  else
  {
    rovescia_lista_aux(l -> next, p -> next, current, nodo_finale);
    
    current -> next = p;
    current = current -> next;
  }
}

void rovescia_lista_rec(lista &l)
{
  if (l != nullptr)
  {
    lista nodo_finale = nullptr;
    lista current = nodo_finale;
    
    rovescia_lista_aux(l -> next, l, current, nodo_finale);
    l -> next = nullptr;
    
    l = nodo_finale;
  }
}

void append_lista(lista &l, lista m)
{
  if (l == nullptr)
  {
    l = m;
  }
  else
  {
    lista penultimo = l;
    
    while (penultimo -> next != nullptr)
    {
      penultimo = penultimo -> next;
    }
    
    penultimo -> next = m;
  }
}

void bubblesort_aux(lista l, int first, int last)
{
  if (first >= last || last < 0)
  {
    return;
  }
  else
  {
    if (l -> info > l -> next -> info)
    {
      int t = l -> info;
      l -> info = l -> next -> info;
      l -> next -> info = t;
    }
    
    bubblesort_aux(l -> next, first + 1, last);
    bubblesort_aux(l, first, last - 1);
  }
}

void bubblesort_rec(lista l, int size)
{
  if (l == nullptr || l -> next == nullptr)
  {
    return;
  }
  else
  {
    bubblesort_aux(l, 0, size - 1);
  }
}

bool linear_search(lista l, int n)
{
  bool retval;
  
  if (l == nullptr)
  {
    retval = false;
  }
  else
  {
    if (l -> info == n)
    {
      retval = true;
    }
    else
    {
      retval = linear_search(l -> next, n);
    }
  }
  
  return retval;
}

lista copia(lista l)
{
  lista m = nullptr;
  
  if (l != nullptr)
  {
    m = new nodo;
    m -> info = l -> info;
   
    lista curr_m = m;
    
    while (l -> next != nullptr)
    {
      curr_m -> next = new nodo;
      l = l -> next;
      
      curr_m = curr_m -> next;
      
      curr_m -> info = l -> info;
    }
    curr_m -> next = nullptr;
  }
  
  return m;
}

void elimina_lista(lista l)
{
  if (l != nullptr)
  {
    if (l -> next != nullptr)
    {
      elimina_lista(l -> next);
    }
    delete l;
  }
}
