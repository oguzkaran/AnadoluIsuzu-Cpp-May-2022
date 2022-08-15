/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Fraction.cpp
    Author          : Oğuz Karan
    Last Update     : 15th Aug 2022
    Platform        : All
    Version         : 1.0.0

    Implementation file for Fraction class that represents a Fraction

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include <stdexcept>
#include <cmath>
#include "Fraction.hpp"

namespace org::csystem::math {
    static int gcd(int a, int b)
    {
        using std::min;
        auto minValue{min(a, b)};

        for (auto i{minValue}; i >= 2; --i)
            if (a % i == 0 && b % i == 0)
                return i;

        return 1;
    }
    static void check(int a, int b)
    {
        using std::invalid_argument;

        if (b == 0) {
            if (a == 0)
                throw invalid_argument{"Indeterminate"};

            throw invalid_argument{"Undefined"};
        }
    }

    void Fraction::set(int a, int b)
    {
        if (a == 0) {
            m_a = 0;
            m_b = 1;
            return;
        }

        if (m_b < 0) {
            m_a = -m_a;
            m_b = -m_b;
        }
        auto gcdVal{gcd(std::abs(m_a), m_b)};

        m_a /= gcdVal;
        m_b /= gcdVal;
    }

    Fraction::Fraction(int a, int b)
    {
        check(a, b);
        set(a, b);
    }

    void Fraction::numerator(int a)
    {
        if (a == m_a)
            return;

        set(a, m_b);
    }

    void Fraction::denominator(int b)
    {
        if (b == m_b)
            return;

        check(m_a, b);
        set(m_a, b);
    }
}