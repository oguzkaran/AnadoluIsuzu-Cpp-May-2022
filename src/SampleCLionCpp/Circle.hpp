/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Circle.hpp
    Author          : Oğuz Karan
    Last Update     : 4th Jul 2022
    Platform        : All
    Version         : 2.0.0

    Header file for Circle class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include <iostream>

namespace org::csystem::math::geometry {
    class Circle {
        friend std::ostream &operator<<(std::ostream &os, const Circle &c);
        friend std::istream &operator>>(std::istream &is, Circle &c);
    private:
        static constexpr double ms_pi = 3.14;
        double m_r;
    public:
        Circle() : m_r{}
        {}

        explicit Circle(double r);

        double radius() const
        { return m_r; }

        double area() const
        { return ms_pi * m_r * m_r; }

        double circumference() const
        { return 2 * ms_pi * m_r; }

        void setRadius(double r);
    };

}

#endif //CIRCLE_HPP_
