/*----------------------------------------------------------------------------------------------------------------------
    File Name       : AnalyticalCircle.cpp
    Author          : Oğuz Karan
    Last Update     : 27th Jul 2022
    Platform        : All
    Version         : 1.0.0

    Implementation file for AnalyticalCircle class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include "AnalyticalCircle.hpp"
namespace com::isuzu::math::geometry {
    void AnalyticalCircle::x(double x)
    {
        m_center.x() = x;
    }

    void AnalyticalCircle::y(double y)
    {
        m_center.y() = y;
    }

    void AnalyticalCircle::offset(double dx, double dy)
    {
        m_center.offset(dx, dy);
    }

    void AnalyticalCircle::offset(double dxy)
    {
        offset(dxy, dxy);
    }
}