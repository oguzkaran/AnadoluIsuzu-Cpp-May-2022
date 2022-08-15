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
#include <string>
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

    std::ostream &operator<<(std::ostream &os, const Fraction &f)
    {
        return os << f.m_a << (f.m_b == 1 ? "" : " / " + std::to_string(f.m_b) + " = " + std::to_string(f.realValue()));
    }

    std::istream &operator>>(std::istream &is, Fraction &f)
    {
        int a, b;
        is >> a >> b;

        check(a, b);
        Fraction::set(f, a, b);

        return is;
    }

    void Fraction::set(Fraction &f,  int a, int b)
    {
        if (a == 0) {
            f.m_a = 0;
            f.m_b = 1;
            return;
        }

        f.m_a = a;
        f.m_b = b;
        if (f.m_b < 0) {
            f.m_a = -f.m_a;
            f.m_b = -f.m_b;
        }
        auto gcdVal{gcd(std::abs(f.m_a), f.m_b)};

        f.m_a /= gcdVal;
        f.m_b /= gcdVal;
    }

    Fraction::Fraction(int a, int b)
    {
        check(a, b);
        set(*this, a, b);
    }

    void Fraction::numerator(int a)
    {
        if (a == m_a)
            return;

        set(*this, a, m_b);
    }

    void Fraction::denominator(int b)
    {
        if (b == m_b)
            return;

        check(m_a, b);
        set(*this, m_a, b);
    }

    Fraction &Fraction::operator++()
    {
        m_a += m_b;

        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        m_a += m_b;

        return Fraction{m_a - m_b, m_b};
    }


    Fraction &Fraction::operator--()
    {
        m_a -= m_b;

        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        m_a -= m_b;

        return Fraction{m_a + m_b, m_b};
    }
}