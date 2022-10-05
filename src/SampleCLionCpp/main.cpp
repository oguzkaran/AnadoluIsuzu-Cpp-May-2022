/*----------------------------------------------------------------------------------------------------------------------
    Aşağıdaki örneği inceleyiniz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "csd/utility.hpp"
#include "Point.hpp"

auto createRandomPoint(double min, double max)
{
    using org::csystem::math::geometry::Point;
    using org::csystem::util::random::randomDouble;

    return Point::createCartesian(randomDouble(min, max), randomDouble(min, max));
}

auto createRandomPoints(std::size_t count, double min, double max)
{
    using org::csystem::math::geometry::Point;
    using namespace std;

    vector<Point> points;

    generate_n(back_inserter(points), count, [min, max]{return createRandomPoint(min, max);});

    return points;
}

int main()
{
    using namespace std;
    using org::csystem::math::geometry::Point;

    auto points{createRandomPoints(10, -100, 100)};

    copy(begin(points), end(points), ostream_iterator<Point>(cout, "\n"));

    return 0;
}
