/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Complex.cpp
    Author          : Oğuz Karan
    Last Update     : 4th Jul 2022
    Platform        : All
    Version         : 2.0.0

    Implementation file for Complex class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include <cmath>
#include "Complex.hpp"

namespace org::csystem::math {
    std::ostream &operator<<(std::ostream &os, const Complex &z)
    {
        return os << '|' << z.m_real << (z.m_imag < 0 ? " - " : " + ") << std::abs(z.m_imag) << "i| = " << z.norm();
    }

    std::istream &operator>>(std::istream &is, Complex &z)
    {
        return is >> z.m_real >> z.m_imag;
    }

    Complex operator+(double value, const Complex &z)
    {
        return Complex{value + z.m_real, z.m_imag};
    }

    Complex Complex::operator+(const Complex &other) const
    {
        return Complex{m_real + other.m_real, m_imag + other.m_imag};
    }

    Complex Complex::operator+(double value) const
    {
        return Complex{m_real + value, m_imag};
    }

    Complex operator-(double value, const Complex &z)
    {
        return Complex{value - z.m_real, -z.m_imag};
    }

    Complex Complex::operator-(const Complex &other) const
    {
        return Complex{m_real - other.m_real, m_imag - other.m_imag};
    }

    Complex Complex::operator-(double value) const
    {
        return Complex{m_real - value, m_imag};
    }

    Complex &Complex::operator+=(const Complex &other)
    {
        return *this = *this + other;
    }

    Complex &Complex::operator+=(double value)
    {
        return *this = *this + value;
    }

    Complex &Complex::operator-=(const Complex &other)
    {
        return *this = *this - other;
    }

    Complex &Complex::operator-=(double value)
    {
        return *this = *this - value;
    }

    Complex Complex::operator-() const
    {
        return Complex{-m_real, -m_imag};
    }

    Complex Complex::operator+() const
    {
        return *this;
    }

    Complex &Complex::operator++()
    {
        ++m_real;

        return *this;
    }

    Complex Complex::operator++(int)
    {
        return Complex{m_real++, m_imag};
    }

    Complex &Complex::operator--()
    {
        --m_real;
        return *this;
    }

    Complex Complex::operator--(int)
    {
        return Complex{m_real--, m_imag};
    }

    bool Complex::operator==(const Complex &other) const
    {
        return std::abs(m_real - other.m_real) < m_delta && std::abs(m_imag - other.m_imag) < m_delta;
    }

    double Complex::operator()() const
    {
        return norm();
    }

    void Complex::operator()(double real, double imag)
    {
        m_real = real;
        m_imag = imag;
    }

    void Complex::operator()(double real)
    {
        (*this)(real, 0);
    }

    double Complex::operator[](std::size_t idx) const
    {
        return idx == 0 ? m_real : m_imag;
    }
}