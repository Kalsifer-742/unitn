long long factorial_recursive(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return (n * factorial_recursive(n - 1));
	}
}