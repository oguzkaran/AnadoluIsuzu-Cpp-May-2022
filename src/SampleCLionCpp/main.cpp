/*----------------------------------------------------------------------------------------------------------------------
    AnalyticalCircle sınıfının 1.0.0 versiyonu
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "AnalyticalCircle.hpp"

int main()
{
    using namespace std;
    using com::isuzu::math::geometry::AnalyticalCircle;

    AnalyticalCircle ac{-2.3, 400.5, -678.9};

    cout << "Radius:" << ac.radius() << '\n';
    cout << "Area:" << ac.area() << '\n';
    cout << "Circumference:" << ac.circumference() << '\n';
    cout << "(" << ac.x() << ", " << ac.y() << ")\n";

    ac.x(23.5);

    cout << "(" << ac.x() << ", " << ac.y() << ")\n";
    return 0;
}
