/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.cpp
    Author          : Oğuz Karan
    Last Update     : 15th Jun 2022
    Platform        : All
    Version         : 2.0.0

    Implementation file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include "Point.hpp"

#include <iostream>
#include <cmath>

void Point::print() const
{
    std::cout << "(" << x << ", " << y << ")\n";
}

void Point::offset(double dx, double dy)
{
    x += dx;
    y += dy;
}

void Point::offset(double dxy)
{
    offset(dxy, dxy);
}

double Point::distance() const
{
    return distance(0, 0);
}

double Point::distance(const Point &other) const
{
    return distance(other.x, other.y);
}

double Point::distance(double a, double b) const
{
    return std::sqrt(std::pow(x - a, 2) + std::pow(y - b, 2));
}