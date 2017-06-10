#include <cmath>
#include <iostream>

void prime_fac(long long n)
{
	long long sqr = static_cast<long long>(sqrt(n));
	for (long long i = 2; i < sqr; i++)
	{
		if (n % i == 0)
		{
			std::cout << i << "\n";
			prime_fac(n / i);
			return;
		}
	}
	std::cout << n << "\n";
}

int main()
{
	prime_fac(71); // 600851475143);
}
