/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.hpp
    Author          : Oğuz Karan
    Last Update     : 27th Jul 2022
    Platform        : All
    Version         : 5.0.0

    Header file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

namespace org::csystem::math::geometry {
    class Point {
        friend std::ostream &operator<<(std::ostream &os, const Point &p);
        friend std::istream &operator>>(std::istream &is, Point &p);
    private:
        double m_x, m_y;
    private:
        explicit Point(double x, double y, bool cartesian);
    public:
        static Point createCartesian(double x, double y);
        static Point createPolar(double r, double theta);
    public:
        double &x()
        { return m_x; }

        double x() const
        { return m_x; }

        double &y()
        { return m_y; }

        double y() const
        { return m_y; }

        void offset(double dx, double dy);

        void offset(double dxy);

        double distance() const;

        double distance(const Point &other) const;

        double distance(double a, double b) const;
    };
}

#endif //POINT_HPP_
