// Funzioni che restitucono int

#include <cctype>

isalnum(c)  se alfanumerico
isalpha(c)  se lettera
isblank(c)  se tab o spazio
iscntrl(c)  se carattere di controllo (ASCII 0-37 + 127 (DEL))
isdigit(c)  se numero
isgraph(c)  tutti quelli di isprint() tranne lo spazio
islower(c)  lettera minuscola
isprint(c)  caratteri stampabili (ASCII > 37 (tranne 127 DEL))
ispunct(c)  se punteggiatura
isspace(c)  ' ', '\t', '\n', '\v', '\f', '\r'
isupper(c)  se lettera maiuscola
isxdigit(c) se numero esadecimale

toupper(c)  rende lettera minuscola maiuscola
tolower(c)  rende lettera maiuscola minuscola

// Funzioni riscritte & more

bool is_alnum(char c)
{
  return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool is_alpha(char c)
{
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

bool is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

// Se non funziona, invece di c <= '‘' scrivi c <= '_'
bool is_punct(char c)
{
  return ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '‘') || (c >= '{' && c <= '~'));
}

bool is_space(char c)
{
  return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

bool is_upper(char c)
{
  return (c >= 'A' && c <= 'Z');
}

bool is_lower(char c)
{
  return (c >= 'a' && c <= 'z');
}

char to_upper(char c)
{
  return (c - ('a' - 'A'));
}

char to_lower(char c)
{
  return (c + ('a' - 'A'));
}

// Rovescia e rende cambia da maiuscola a minuscola (o viceversa)

char flip_and_upper(char c)
{
  return ('A' - (c - 'z'));
}

// Rovescia una cifra 0 -> 9, 1 -> 8, ..., 8 -> 1, 9 -> 0
char flip(char c)
{
  return ('9' - (c - '0'));
}
