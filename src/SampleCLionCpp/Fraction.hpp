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
        Fraction();
        explicit Fraction(int a, int b = 0);
    public:
        //accessors
        int numerator() const;
        void numerator(int a);
        int denominator() const;
        void denominator(int a);
        double realValue() const;
    public:
        //additive operators
        Fraction operator+(const Fraction &other) const;
        Fraction operator+(int value) const;
        Fraction &operator+=(const Fraction &other) const;
        Fraction &operator+=(int value) const;

        //subtractive operators
        Fraction operator-(const Fraction &other) const;
        Fraction operator-(int value) const;
        Fraction &operator-=(const Fraction &other) const;
        Fraction &operator-=(int value) const;

        //multiplicative operators
        Fraction operator*(const Fraction &other) const;
        Fraction operator*(int value) const;
        Fraction &operator*=(const Fraction &other) const;
        Fraction &operator*=(int value) const;

        //divide operators
        Fraction operator/(const Fraction &other) const;
        Fraction operator/(int value) const;
        Fraction &operator/=(const Fraction &other) const;
        Fraction &operator/=(int value) const;

        //Sign - and + operators
        Fraction operator-() const;
        Fraction operator+() const;

        //increment operators
        Fraction &operator++();
        Fraction operator++(int);

        //decrement operators
        Fraction &operator--();
        Fraction operator--(int);

        //explicit type cast to real value of fraction
        explicit operator double() const;
    };
}

#endif //FRACTION_HPP_
