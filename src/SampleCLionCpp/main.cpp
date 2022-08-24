/*----------------------------------------------------------------------------------------------------------------------
   Point sınıfı ve get friend fonksiyonu
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "Point.hpp"

int main()
{
    using namespace std;
    using org::csystem::math::geometry::Point;
    using org::csystem::math::geometry::get;

    auto p{Point::createCartesian(100, 200)};

    cout << get<0>(p) << '\n';
    cout << get<1>(p) << '\n';
    cout << get<Point::X>(p) << '\n';
    cout << get<Point::Y>(p) << '\n';

    return 0;
}

