char to_uppercase(char c)
{
  return ((char)(c - 32));
}

void to_uppercase(char& c)
{
  c = (char)(c - 32);
}