/*----------------------------------------------------------------------------------------------------------------------
    get_if fonksiyonu aldığı variant adresi ve tür açılımına göre variant'a ilişkin elemanın adresine geri döner. O an
    tutulan eleman ile get_if fonksiyonuna verilen tür farklı ise bu durumeda nullptr değerine geri döner.
    Aşağıdaki örneği inceleyiniz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <deque>
#include <variant>
#include <algorithm>
#include <iterator>
#include <complex>
#include "csd/utility.hpp"
#include "csd/stdinutility.hpp"
#include "Point.hpp"

using RandomVariant = std::variant<int, double, std::string, std::complex<double>, org::csystem::math::geometry::Point>;

//int, double, string, complex, Point
auto createRandoRandomVariant()
{
    using namespace std;
    using org::csystem::util::random::randomInt;
    using org::csystem::util::random::randomDouble;
    using org::csystem::util::random::randomString;
    using org::csystem::math::geometry::Point;

    auto val{randomInt(1, 5)};
    RandomVariant v;

    switch (val) {
        case 1:
            v = randomInt(0, 99);
            break;
        case 2:
            v = randomDouble(0, 99);
            break;
        case 3:
            v = randomString(randomInt(5, 10));
            break;
        case 4:
            v.emplace<complex<double>>(randomDouble(-10, 10), randomDouble(-10, 10));
            break;
        default:
            v = Point::createCartesian(randomDouble(-100, 100), randomDouble(-100, 100));
    }

    return v;
}

auto createRandoRandomVariants(std::size_t count)
{
    using namespace std;

    deque<RandomVariant> variant;

    generate_n(back_inserter(variant), count, []{return createRandoRandomVariant();});

    return variant;
}

void doWorkCallback(RandomVariant v)
{
    using namespace std;
    using org::csystem::math::geometry::Point;

    cout << "--------------------------------------------------------\n";

    if (auto pi = get_if<int>(&v)) {
        cout << "int:" << *pi << '\n';
        cout << "int:" << get<int>(v) << '\n';
    }
    else if (auto pd = get_if<double>(&v)) {
        cout << "double:" << *pd << '\n';
        cout << "double:" << get<double>(v) << '\n';
    }
    else if (auto ps = get_if<string>(&v)) {
        cout << "string:" << *ps << '\n';
        cout << "string:" << get<string>(v) << '\n';
    }
    else if (auto pc = get_if<complex<double>>(&v)) {
        cout << "complex<double>:" << *pc << '\n';
        cout << "complex<double>:" << get<complex<double>>(v) << '\n';
    }
    else if (auto pp = get_if<Point>(&v)) {
        cout << "Point:" << *pp << '\n';
        cout << "Point:" << get<Point>(v) << '\n';
    }

    cout << "--------------------------------------------------------\n";
}


void doWork(const std::deque<RandomVariant> &deq)
{
    using namespace std;

    for_each(begin(deq), end(deq), [](const auto &a) { doWorkCallback(a);});
}

int main()
{
    using namespace std;
    using com::anadoluisuzu::util::getInt;

    auto count{getInt("Input a count:")};

    doWork(createRandoRandomVariants(count));

    return 0;
}
