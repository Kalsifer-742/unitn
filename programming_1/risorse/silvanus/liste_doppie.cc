struct nodo;
typedef nodo * lista;

struct nodo
{
  int info;
  
  lista prev;
  lista next;
};

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

void inserimento_coda(lista &l, int n)
{
  if (l == nullptr)
  {
    l = new nodo;
    
    l -> info = n;
    l -> next = nullptr;
    l -> prev = nullptr;
  }
  else
  {
    lista tmp = l;
    
    while (tmp -> next != nullptr)
    {
      tmp = tmp -> next;
    }
    
    tmp -> next = new nodo;
    tmp -> next -> next = nullptr;
    tmp -> next -> prev = tmp;
    tmp -> next -> info = n;
  }
}

void inserimento_testa(lista &l, int n)
{
  if (l == nullptr)
  {
    l = new nodo;
    
    l -> info = n;
    l -> next = nullptr;
    l -> prev = nullptr;
  }
  else
  {
    lista tmp = new nodo;
    
    tmp -> prev = nullptr;
    tmp -> next = l;
    tmp -> info = n;
    
    l -> prev = tmp;
    l = tmp;
  }
}

void rimuovi_elemento(lista &l, int n) 
{ 
  if (l != nullptr) 
  { 
    lista curr = l; 
    if(curr->info == n) 
    {  
       l = curr->next; 
       delete curr; 
    } 
    else 
    { 
     
       while (curr -> info != n || curr == nullptr) 
       { 
       
          curr = curr -> next; 
       
       } 
 
       if (curr->next != nullptr && curr -> info == n) 
       { 
         curr -> next -> prev = curr -> prev; 
         curr -> prev -> next = curr -> next; 
       
         delete curr; 
       } 
      else if(curr->next == nullptr && curr -> info == n) 
      { 
          curr -> prev -> next = curr -> next; 
          delete curr; 
      } 
    } 
  } 
}

void elimina_lista(lista l)
{
  if (l -> next != nullptr)
  {
    elimina_lista(l -> next);
  }
  delete l;
}
