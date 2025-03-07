/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.cpp
    Author          : Oğuz Karan
    Last Update     : 24th Aug 2022
    Platform        : All
    Version         : 5.0.0

    Implementation file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include "Point.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

namespace org::csystem::math::geometry {
    std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        return os << "(" << p.m_x << ", " << p.m_y << ")";
    }

    std::istream &operator>>(std::istream &is, Point &p)
    {
        return is >> p.m_x >> p.m_y;
    }

    Point::Point(double x, double y, bool cartesian) : m_x{cartesian ? x : x * std::cos(y)}, m_y{cartesian ? y : x * std::sin(y)}
    {
    }

    Point Point::createCartesian(double x, double y)
    {
        return Point{x, y, true};
    }

    Point Point::createPolar(double r, double theta)
    {
        return Point{r, theta, false};
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
}