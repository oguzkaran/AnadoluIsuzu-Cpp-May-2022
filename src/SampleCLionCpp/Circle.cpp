/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Circle.cpp
    Author          : Oğuz Karan
    Last Update     : 12th Oct 2022
    Platform        : All
    Version         : 2.1.0

    Implementation file for Circle class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/

#include "Circle.hpp"
#include <cmath>

namespace org::csystem::math::geometry {
    std::ostream &operator<<(std::ostream &os, const Circle &c)
    {
        return os << "Radius: " << c.m_r << ", Area: " << c.area() << ", Circumference: " << c.circumference();
    }

    std::istream &operator>>(std::istream &is, Circle &c)
    {
        is >> c.m_r;
        c.m_r = std::abs(c.m_r);

        return is;
    }

    Circle::Circle(double r) : m_r{std::abs(r)}
    {
    }

    void Circle::setRadius(double r)
    {
        m_r = std::abs(r);
    }
}