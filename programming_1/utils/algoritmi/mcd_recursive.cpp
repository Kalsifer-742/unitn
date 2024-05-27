int mcd_recursive(int a, int b)
{
  int result;
  
  if (b == 0)
  {
    result = a;
  }
  else
  {
    result = mcd_recursive(b, a % b);
  }
  return result;
}