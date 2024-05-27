bool is_prime_recursive(const int num, int i)
{
  bool result = true;
  
  if (i > num)
  {
    result = false;
  }
  else
  {
    if (num % i == 0)
    {
      if (num == i)
      {
        result = true;
      }
      else
      {
        result = false;
      }
    }
    else
    {
      result = is_prime_recursive(num, i + 1);
    }
  }
  
  return result;
}