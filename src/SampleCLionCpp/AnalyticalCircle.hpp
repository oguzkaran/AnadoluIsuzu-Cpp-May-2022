/*----------------------------------------------------------------------------------------------------------------------
    File Name       : AnalyticalCircle.hpp
    Author          : Oğuz Karan
    Last Update     : 27th Jul 2022
    Platform        : All
    Version         : 1.0.0

    Header file for AnalyticalCircle class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/

#ifndef ANALYTICALCIRCLE_HPP_
#define ANALYTICALCIRCLE_HPP_

#include "Circle.hpp"
#include "Point.hpp"

namespace com::isuzu::math::geometry {
    namespace csdgeo = org::csystem::math::geometry;

    class AnalyticalCircle : public csdgeo::Circle {
    private:
        csdgeo::Point m_center;
    public:
        AnalyticalCircle() : AnalyticalCircle{0.0}
        {}

        explicit AnalyticalCircle(double r) : AnalyticalCircle{r, 0, 0}
        {}

        explicit AnalyticalCircle(double x, double y) : AnalyticalCircle{0, x, y}
        {}

        AnalyticalCircle(double r, double x, double y) : Circle{r}, m_center{csdgeo::Point::createCartesian(x, y)}
        {}
    public:
        double x() const {return m_center.x();}
        void x(double x);
        double y() const {return m_center.y();}
        void y(double y);
        void offset(double dx, double dy);
        void offset(double dxy);
        //bool intersects(const AnalyticalCircle &other) const;
        //bool isTangent(const AnalyticalCircle &other) const;
        //...
    };
}


#endif //ANALYTICALCIRCLE_HPP_
