/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Circle.cpp
    Author          : Oğuz Karan
    Last Update     : 24th Jun 2022
    Platform        : All
    Version         : 1.0.1

    Implementation file for Circle class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/

#include "Circle.hpp"
#include <cmath>

Circle::Circle(double r) : m_r{std::abs(r)}
{
}

void Circle::setRadius(double r)
{
    m_r = std::abs(r);
}