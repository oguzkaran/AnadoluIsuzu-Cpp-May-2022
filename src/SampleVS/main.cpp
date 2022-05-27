/*----------------------------------------------------------------------------------------------------------------------
	C++ ile C'de yazılmış bir fonksiyon çağrılabilir. Bunun için extern "C" direktifinin kullanılması gerekir. Bu durumda
	fonksiyonların prototip bildirimlerinin extern "C" direktifi verilerek yapılması gerekir. Ayrıca standart C++ 
	derleyicisi için __cplusplus sembolik sabitinin define edilmiştir. Bu durumda programcı bir header dosyanın 
	hem C için hem de C++ için kullanılmasını istediği durumda aşağıdaki gibi koşullu önişlemci komutlarını kullanabilir.
	Örnekte csderrorutil.h dosyasını inceleyiniz.
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "csderrorutil.h"

int run();
int* resize(int* p, std::size_t oldSize, std::size_t newSize);
void print(const int* p, std::size_t size);

int main()
{
	return run();
}

int* resize(int* p, std::size_t oldSize, std::size_t newSize)
{
	auto pn{ new(std::nothrow) int[newSize] };

	if (p == nullptr)
		return nullptr;

	std::memcpy(pn, p, oldSize * sizeof(int));

	delete p;

	return pn;
}


void print(const int* p, std::size_t size)
{
	for (std::size_t i{}; i < size; ++i)
		std::cout << p[i] << ' ';

	std::cout << '\n';
}

int run()
{
	int a;
	std::size_t idx{ 0 };
	std::size_t size{ 3 };

	auto p{ new(std::nothrow) int[size] };

	if (p == nullptr)
		csd_exit_fail("Can not allocate memory");

	for (;;) {
		std::cout << "Input a number:";
		std::cin >> a;

		if (a == 0)
			break;

		if (idx == size) {
			p = resize(p, size, size * 2);

			if (p == nullptr)
				csd_exit_fail("Can not allocate memory");

			size *= 2;
		}

		p[idx++] = a;
	}
	std::cout << "Size:" << size << '\n';
	print(p, idx);

	delete[] p;

	return 0;
}
