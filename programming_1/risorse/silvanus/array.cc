// Ricerca binaria RICORSIVA in un array ORDINATO di interi
// Restituisce l'indirizzo del valore se presente, altrimenti -1
// Per renderla una funzione booleana, sostituire le righe coi commenti

int binarysearch_rec(int v[], int start, int end, int n) // bool
{
  int retval = -1; // bool retval = false;
  
  if (end >= start)
  {
    int mid = start + (end - start) / 2;

    if (v[mid] == n)
    {
      retval = mid; // retval = true;
    }
    else if (v[mid] > n)
    {
      retval = binarysearch_rec(v, start, mid - 1, n);
    }
    else
    {
      retval = binarysearch_rec(v, mid + 1, end, n);
    }
  }

  return retval;
}

// Ricerca binaria ITERATIVA in un array ORDINATO di interi
// Restituisce l'indirizzo del valore se presente, altrimenti -1
// Per renderla una funzione booleana, sostituire le righe coi commenti

bool binarysearch_it(int v[], int dim, int x)  // bool
{
  int start = 0, end = dim - 1, i;
  bool retval = false;  // bool retval = false;
  
  while (start <= end)
  {
    i = (start + end)/2;
    
    if (v[i] == x)
    {
      retval = true; // retval = true;
    }
    if (v[i] < x)
    {
      start = i + 1;
    }
    else
    {
      end = i - 1;
    }
  }
  return retval;
}

// Bubble Sort RICORSIVO

void bubblesort_aux(int arr[], int first, int last)
{
  if (first >= last || last < 0)
  {
    return;
  }
  else
  {
    if (arr[first] > arr[first + 1])
    {
      int t = arr[first];
      arr[first] = arr[first + 1];
      arr[first + 1] = t;
    }
    
    bubblesort_aux(arr, first + 1, last);
    bubblesort_aux(arr, first, last - 1);
  }
}

void bubblesort_rec(int arr[], int size)
{
  bubblesort_aux(arr, 0, size - 1);
}

// Bubble Sort ITERATIVO

void bubblesort_it(int arr[], int n)
{
  for (int k = (n - 1); k > 0; k--)
  {
    for (int i = 0; i < k; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        int t = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = t;
      }
    }
  }
}

// Stampa di un array di interi RICORSIVA

void print_aux(int v[], int dim, int i)
{
  if (i < dim)
  {
    cout << v[i] << " ";
    print_aux(v, dim, i + 1);
  }
  else
  {
    cout << "\b \b" << endl;
  }
}

void print_rec(int v[], int dim)
{
  if (dim > 0)
  {
    print_aux(v, dim, 0);
  }
}

// Stampa di un array di interi ITERATIVA

void print_it(int v[], int dim)
{
  for (int i = 0; i < dim; i++)
  {
    cout << v[i] << " ";
  }
  
  cout << "\b \b" << endl;
}

// Inizializzazione di un array di interi

#include <cstdlib>
#include <ctime>

srand(time(NULL));

void init(int v[], int dim)
{
  for (int i = 0; i < dim; i++)
  {
    v[i] = rand() % 10 + 1;
  }
}

// Unire due array
// dim3 >= (dim1 + dim2)

void merge(const int a[], int dim1, const int b[], int dim2, int c[], int dim3)
{
  for (int i = 0, j = 0, k = 0; k < (dim1 + dim2); k++)
  {
    if (j == dim2 || (i < dim1 && a[i] < b[j]))
    {
      c[k] = a[i];
      i++;
    }
    else
    {
      c[k] = b[j];
      j++;
    }
  }
}

