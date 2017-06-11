#include <iomanip>
#include <iostream>
  
void calc_pi_nilakantha()
{
  // pi = 3 + 4(2*3*4) - 4/(4*5*6) + 4(6*7*8) - 4/(8*9*10) + 4/(10*11*12) - ...
  //    = 3 + 4/(n * [n+1] * [n+2]) - 4/([n+2] * [n+3] * [n+4]) + ...
  //    where n starts at 2 then we add 4 each time.

  double pi = 3.;
  int n = 2; 
  const int NUM_ITERS = 4000;
  for (int i = 0; i < NUM_ITERS; i++)
  {
    pi += 4. / (double(n)   * double(n+1) * double(n+2))
        - 4. / (double(n+2) * double(n+3) * double(n+4));

    n += 4;

    std::cout << std::setprecision(50) << double(pi) << "\n";   
  }
}

int main()
{
  calc_pi_nilakantha();
}


