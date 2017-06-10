#include <iostream>

bool is_prime(int n)
{
  int sq = static_cast<int>(sqrt(n));
  for (int i = 2; i <= sq; i++)
  {
    //std::cout << "Trying " << n << " % " << i << "..\n";
    if ((n % i) == 0)
    {
      //std::cout << n << " is not prime.\n";
      return false;
    }
  }
  std::cout << n << " IS prime.\n";
  return true;
}

int main()
{
  for (int i = 2; i < 10000; i++)
  {
    is_prime(i);
  }
}
