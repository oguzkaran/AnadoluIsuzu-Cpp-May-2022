/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Point.hpp
    Author          : Oğuz Karan
    Last Update     : 25th Aug 2022
    Platform        : All
    Version         : 5.0.0

    Header file for Point class that represents a point in cartesian coordinates

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

#include "common.hpp"

namespace org::csystem::math::geometry {
    class DLLSPEC Point {
        template <std::size_t I>
        friend double get(const Point &p);
        friend std::ostream &operator<<(std::ostream &os, const Point &p);
        friend std::istream &operator>>(std::istream &is, Point &p);
    private:
        double m_x, m_y;
    private:
        explicit Point(double x, double y, bool cartesian);
    public:
        constexpr static std::size_t X = 0;
        constexpr static std::size_t Y = 1;
        [[nodiscard]] static Point createCartesian(double x, double y);
        [[nodiscard]] static Point createPolar(double r, double theta);
    public:
        double &x() { return m_x; }

        [[nodiscard]] double x() const { return m_x; }

        double &y(){ return m_y; }

        [[nodiscard]] double y() const { return m_y; }

        void offset(double dx, double dy);

        void offset(double dxy);

        [[nodiscard]] double distance() const;

        [[nodiscard]] double distance(const Point &other) const;

        [[nodiscard]] double distance(double a, double b) const;
    };

    template <std::size_t I>
    double get(const Point &p)
    {
        if (I != 0 && I != 1)
            throw std::out_of_range{"I must be zero or one"};

        return I == 0 ? p.m_x : p.m_y;
    }

}

#endif //POINT_HPP_
