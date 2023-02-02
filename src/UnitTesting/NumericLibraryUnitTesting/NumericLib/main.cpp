#include <iostream>
#include "numericutil.hpp"

int main()
{
	using com::anadoluisuzu::util::numeric::isPrime;

	for (unsigned long i{}; i <= 100; ++i)
		if (isPrime(i))
			std::cout << i << " ";

	std::cout << '\n';

	std::cout << std::boolalpha << (isPrime(1'000'003) ? "Prime" : "Not prime") << '\n';

	return 0;
}