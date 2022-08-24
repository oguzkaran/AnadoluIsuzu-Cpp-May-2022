/*----------------------------------------------------------------------------------------------------------------------
   Aşağıdaki örnekte print metodu yalnızca double türü için çağrılabilir. Template fonksiyon delete edildiği için
   diğer türlerle çağrılamaz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "Complex.hpp"
#include "Point.hpp"

template <typename T>
void print(const T &t) = delete;

void print(double a)
{
    std::cout << "void print(double): " << a << '\n';
}

int main()
{
    using namespace std;
    using org::csystem::math::Complex;
    using org::csystem::math::geometry::Point;

    auto p{Point::createCartesian(100, 200)};
    Complex z{3, 4};

    print(p); //error
    print(z); //error
    print(3.4);
    print<double>(3.4); //error
    print(10); //error


    return 0;
}

