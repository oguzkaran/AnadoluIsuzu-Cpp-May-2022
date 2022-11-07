/*----------------------------------------------------------------------------------------------------------------------
    File Name       : mathutility.hpp
    Author          : Oğuz Karan
    Last Update     : 07th Nov 2022
    Platform        : All
    Version         : 1.0.0

    Header file for math operations

    Copyleft (c) 1993 by  Anadolu Isuzu
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef MATH_UTILITY_HPP_
#define MATH_UTILITY_HPP_

#include <optional>
#include <tuple>
#include <cmath>

namespace com::anadoluisuzu::util::math {
    [[nodiscard]] std::optional<std::tuple<double, double>> solveQuadraticEquation(double a, double b, double c);
}


#endif //MATH_UTILITY_HPP_
