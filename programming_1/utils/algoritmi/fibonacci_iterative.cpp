long long fibonacci_iterative(int n)
{
    long long n1 = 0, n2 = 1, result;
  
    if (n < 2)
    {
        return 1;
    }
    else
    {   
        n1 = 1;
        n2 = 1;
        for (int i = 2; i <= n; i++)
        {
            result = n1 + n2;
            n2 = n1;
            n1 = result;
        }
    }
  
    return result;
}