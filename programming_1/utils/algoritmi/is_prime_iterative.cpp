bool is_prime_iterative(const int num)
{
  bool result = true;
  
  if (num < 2)
  {
    result = false;
  }
  else
  {
    for (int i = 2; i < num && result; i++)
    {
      if ((num % i) == 0)
      {
        result = false;
      }
    }
  }
  
  return result;
}