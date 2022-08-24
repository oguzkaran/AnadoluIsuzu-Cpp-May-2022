/*----------------------------------------------------------------------------------------------------------------------
   Aşağıdaki örnekte Complex sınıfı için operator < yazıldığında csdMax fonksiyonu Complex sınıfı için yazılabilir duruma
   gelmiştir. Ayrıca Complex sınıfının operator<< fonksiyonu yazıldığından printArray fonksiyonu da Complex sınıfı için
   derleyici tarafından yazılabilmektedir. csdSum fonksiyonun açılabilmesi için açılıma ilişkin türün uygun operator+
   derleyici tarafından yazılabilmektedir. csdSum fonksiyonun açılabilmesi için açılıma ilişkin türün uygun operator+
   fonksiyonunun olması gerekir. Ayrıca efektif olması açısından csdMax fonksiyonunda taşıma semantiği kullanıldığına
   dikkat ediniz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "csd/utility.hpp"
#include "Complex.hpp"

using org::csystem::math::Complex;
bool operator <(const Complex &c1, const Complex &c2);

template <typename T>
T csdMax(const T *p, std::size_t size);

template <typename T>
T csdSum(const T *p, std::size_t size);


template <typename T>
void csdPrintArray(const T *p, std::size_t size, char delim = ' ', char end = '\n');

template <typename T>
T csdMax(const T *p, std::size_t size)
{
    auto max{p[0]};

    for (std::size_t i{1}; i < size; ++i)
        if (max < p[i])
            max = p[i];

    return max;
}

template <typename T>
T csdSum(const T *p, std::size_t size)
{
    T sum{};

    for (std::size_t i{}; i < size; ++i)
        sum = std::move(sum) + p[i];

    return sum;
}

template <typename T>
void csdPrintArray(const T *p, std::size_t size, char delim, char end)
{
    for (std::size_t i{}; i < size; ++i)
        std::cout << p[i] << delim;

    std::cout << end;
}

Complex getRandomComplex(double min, double bound)
{
    using org::csystem::util::random::randomDouble;

    return Complex{randomDouble(min, bound), randomDouble(min, bound)};
}

void fillComplexArrayRandom(Complex *p, std::size_t size, double min, double bound)
{
    for (std::size_t i{}; i < size; ++i)
        p[i] = getRandomComplex(min, bound);
}

bool operator <(const Complex &c1, const Complex &c2)
{
    return c1.norm() < c2.length();
}

int main()
{
    using namespace std;
    using org::csystem::math::Complex;
    constexpr int SIZE = 10;
    Complex c[SIZE];

    fillComplexArrayRandom(c, SIZE, 3.456, 7.899);
    csdPrintArray(c, SIZE, '\n');

    cout << "Max length complex number:" << csdMax(c, SIZE) << '\n';
    cout << "Total:" << csdSum(c, SIZE) << '\n';

    return 0;
}

