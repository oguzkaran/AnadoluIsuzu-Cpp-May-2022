/*----------------------------------------------------------------------------------------------------------------------
    File Name       : mathutility.cpp
    Author          : Oğuz Karan
    Last Update     : 07th Nov 2022
    Platform        : All
    Version         : 1.0.0

    Implementation file for math operations

    Copyleft (c) 1993 by  Anadolu Isuzu
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/

#include <cmath>
#include "mathutility.hpp"

namespace com::anadoluisuzu::util::math {
    std::optional<std::tuple<double, double>> solveQuadraticEquation(double a, double b, double c)
    {
        using namespace std;

        optional<tuple<double, double>> result = std::nullopt;

        if (auto delta{b * b - 4 * a * c}; delta > 0) {
            auto sqrtDelta{std::sqrt(delta)};

            result = make_optional(make_tuple((-b + sqrtDelta) / (2 * a), (-b - sqrtDelta) / (2 * a)));
        }
        else if (delta == 0) {
            auto x = -b / (2 * a);
            result = make_optional(make_tuple(x, x));
        }

        return result;
    }
}
