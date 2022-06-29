/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.hpp
    Author          : Oğuz Karan
    Last Update     : 29th Jun 2022
    Platform        : All
    Version         : 3.0.0

    Header file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

class Point {
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    friend std::istream &operator>>(std::istream &is, Point &p);
private:
    double m_x, m_y;
public:
    explicit Point(double x = 0., double y = 0.) : m_x{x}, m_y{y}
    {}
public:
    double &x() {return m_x;}
    double x() const {return m_x;}
    double &y()  {return m_y;}
    double y() const {return m_y;}
    void offset(double dx, double dy);
    void offset(double dxy);
    double distance() const;
    double distance(const Point &other) const;
    double distance(double a, double b) const;
};


#endif //POINT_HPP_
