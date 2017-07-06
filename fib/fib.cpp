#include <iostream>

// Return nth fibonacci number
int r_fib(int n)
{
  if (n < 3)
  {
    return 1;
  }
  // This smells inefficient, we seem to be doing twice the work needed?
  return r_fib(n - 1) + r_fib(n - 2);
}

// Without recursion
int fib(int n)
{
  int res = 1;
  float fib1 = 1;
  float fib2 = 1;
  for (int i = 2; i < n; i++)
  {
    res = fib1 + fib2;
    fib2 = fib1; 
    fib1 = res;
  }
  return res;
}

int main()
{
  for (int i = 1; i < 10; i++)
  {
    std::cout << i << "\t" << fib(i) << "\n";
  }
}

