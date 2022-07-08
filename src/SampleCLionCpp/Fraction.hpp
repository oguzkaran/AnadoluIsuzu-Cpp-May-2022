/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Fraction.hpp
    Author          : Oğuz Karan
    Last Update     : 11th Jul 2022
    Platform        : All
    Version         : 1.0.0

    Header file for Fraction class that represents a Fraction

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/

#ifndef FRACTION_HPP_
#define FRACTION_HPP_

#include <iostream>

namespace org::csystem::math {
    class Fraction {
        friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
        friend std::istream &operator>>(std::istream &is, Fraction &f);
    private:
        int m_a, m_b;
    public:
        Fraction(int a, int b);

    public:
        int numerator() const;

        void numerator(int a);

        int denominator() const;

        void denominator(int a);

        double realValue() const;

    public:
        Fraction operator+(const Fraction &other) const;
        Fraction operator+(int value) const;
        Fraction &operator+=(const Fraction &other);
        Fraction &operator+=(int value);

        Fraction operator-(const Fraction &other) const;
        Fraction operator-(int value) const;
        Fraction &operator-=(const Fraction &other);
        Fraction &operator-=(int value);

        Fraction operator*(const Fraction &other) const;
        Fraction operator*(int value) const;
        Fraction &operator*=(const Fraction &other);
        Fraction &operator*=(int value);

        Fraction operator/(const Fraction &other) const;
        Fraction operator/(int value) const;
        Fraction &operator/=(const Fraction &other);
        Fraction &operator/=(int value);

        
    };
}

#endif //FRACTION_HPP_
