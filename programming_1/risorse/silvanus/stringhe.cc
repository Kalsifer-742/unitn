// Stringhe in C

#include <cstring>

strlen(s)         lunghezza di s escluso lo \0
strchr(s, c)      puntatore char* alla prima occorrenza di c in s (oppure NULL)
strrchr(s, c)     puntatore char* alla ultima occorrenza di c in s (oppure NULL)
strstr(s, t)      puntatore alla prima occorrenza della sottostringa t in s (o NULL)
strcpy(s, t)      copia t in s e restituisce s (s deve essere abbastanza grande per contenere t)
strncpy(s, t, n)  copia n caratteri di t in s e restituisce s (alla fine serve lo \0)
strcat(s, t)      concatena t al termine di s e restituisce s
strncat(s, t, n)  concatena i primi n caratteri di t a s
strcmp(s, t)      restituisce un valore negativo, nullo o positivo se s è <, == o > di t

// Funzioni riscritte/ricorsive & more

int my_strlen(const char * s)
{
  int length;
  
  for (length = 0; s[length] != '\0'; length++);
  
  return length;
}

int my_strlen_rec(char * s, int i)
{
  int retval;
  
  if (s[i] == '\0')
  {
    retval = 0;
  }
  else
  {
    retval = 1 + my_strlen_rec(s, i + 1);
  }
  
  return retval;
}

char * my_strchr(char * s, char c)
{
  int i = 0;
  char * p = NULL;
  
  while (p == NULL && s[i++] != '\0')
  {
    if (s[i] == c)
    {
      p = &s[i];
    }
  }
  
  return p;
}

char * my_strrchr(char * s, char c)
{
  int i;
  
  for (i = 0; s[i] != '\0'; i++);

  char * p = NULL;
  
  while (p == NULL && (i--) > -1)
  {
    if (s[i] == c)
    {
      p = &s[i];
    }
  }
  
  return p;
}

char * my_strstr(char * s, char * t)
{
  int len1, len2;
  char * p = NULL;
  
  for (len1 = 0; s[len1] != '\0'; len1++);
  for (len2 = 0; t[len2] != '\0'; len2++);
  
  if (len2 <= len1)
  {
    int i = 0;
    
    while (i <= (len1 - len2))
    {
      if (s[i] == t[0])
      {
        int j = 0;
        
        while ((j < len2 && (i + j) < len1) && t[j] == s[i + j])
        {
          j++;
        }
        
        if (j == len2)
        {
          p = &s[i];
        }
      }
      i++;
    }
  }
  
  return p;
}

// Copia t in s
// - se strlen(t) > strlen(s) restituisce NULL
char * my_strcpy(char * s, char * t)
{
  int len1, len2;
  
  for (len1 = 0; s[len1] != '\0'; len1++);
  for (len2 = 0; s[len2] != '\0'; len2++);
  
  char * p = NULL;
  
  if (len2 < len1)
  {
    for (int i = 0; i < len2 + 1; i++)
    {
      s[i] = t[i];
    }
    
    p = s;
  }
  
  return p;
}

// Copia n caratteri di t in s
// - se n > strlen(s) restituisce NULL
// - se n > strlen(t) agisce come strcpy: copia t in s e mette \0
char * my_strncpy(char * s, char * t, int n)
{
  int len1, len2;
  
  for (len1 = 0; s[len1] != '\0'; len1++);
  for (len2 = 0; t[len2] != '\0'; len2++);
  
  char * p = NULL;
  
  if (n <= len1)
  {
    for (int i = 0; i < n; i++)
    {
      if (i < len2)
      {
        s[i] = t[i];
      }
    }
    
    if (n > len2)
    {
      s[len2] = '\0';
    }
        
    p = s;
  }
  
  return p;
}

// LA FUNZIONE NON CONTROLLA CHE s ABBIA SPAZIO PER t
char * my_strcat(char * s, char * t)
{
  int len1, len2;
  
  for (len1 = 0; s[len1] != '\0'; len1++);
  for (len2 = 0; t[len2] != '\0'; len2++);
  
  int i = len1;
  
  for (int j = 0; j < len2; i++, j++)
  {
    s[i] = t[j];
  }
  s[i] = '\0';
  
  return s;
}

// LA FUNZIONE NON CONTROLLA CHE s ABBIA SPAZIO PER n CARATTERI DI t
char * my_strncat(char * s, char * t, int n)
{
  int len1, len2;
  
  for (len1 = 0; s[len1] != '\0'; len1++);
  for (len2 = 0; t[len2] != '\0'; len2++);
  
  int i = len1;
  int k = (n <= len2 ? n : len2);
  
  for (int j = 0; j < k; i++, j++)
  {
    s[i] = t[j];
  }
  s[i] = '\0';
  
  return s;
}

int my_strcmp(char * s, char * t)
{
  int sum = 0;
  
  for (int i = 0; (s[i] != '\0' || t[i] != '\0') && sum >= 0; i++)
  {
    if (s[i] != '\0')
    {
      sum += int(s[i]);
    }
    if (t[i] != '\0')
    {
      sum -= int(t[i]);
    }
  }
  
  return sum;
}

// Copia n caratteri dalla stringa t alla stringa s
// La lettura dei caratteri inizia da t_pos in t e la copia inizia da s_pos in s

// LA FUNZIONE NON CONTROLLA CHE s ABBIA SPAZIO PER n CARATTERI DI t
void other_strncpy(char * s, char * t, int s_pos, int t_pos, int n)
{
  for (int i = 0; i < n; i++)
  {
    s[s_pos + i] = t[t_pos + i];
  }
}
