/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.cpp
    Author          : Oğuz Karan
    Last Update     : 24th Jun 2022
    Platform        : All
    Version         : 3.0.0

    Implementation file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include "Point.hpp"

#include <iostream>
#include <cmath>

void Point::print() const
{
    std::cout << "(" << m_x << ", " << m_y << ")\n";
}

void Point::offset(double dx, double dy)
{
    m_x += dx;
    m_y += dy;
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
    return distance(other.m_x, other.m_y);
}

double Point::distance(double a, double b) const
{
    return std::sqrt(std::pow(m_x - a, 2) + std::pow(m_y - b, 2));
}