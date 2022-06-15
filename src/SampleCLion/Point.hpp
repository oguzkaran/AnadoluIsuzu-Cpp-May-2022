/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.hpp
    Author          : Oğuz Karan
    Last Update     : 15th Jun 2022
    Platform        : All
    Version         : 2.0.0

    Header file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef POINT_HPP_
#define POINT_HPP_

class Point {
public:
    double x, y;
public:
    explicit Point(double x = 0., double y = 0.) : x{x}, y{y}
    {}
public:
    void print() const;
    void offset(double dx, double dy);
    void offset(double dxy);
    double distance() const;
    double distance(const Point &other) const;
    double distance(double a, double b) const;
};


#endif //POINT_HPP_
