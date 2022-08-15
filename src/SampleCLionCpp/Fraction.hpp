/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Fraction.hpp
    Author          : Oğuz Karan
    Last Update     : 15th Aug 2022
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
        int m_a{}, m_b{};
    private:
        static void set(Fraction &f,  int a, int b);
    public:
        Fraction() : m_a{}, m_b{1}
        {}
        explicit Fraction(int a, int b = 0);
    public:
        //accessors
        int numerator() const {return m_a;}
        void numerator(int a);
        int denominator() const {return m_b;}
        void denominator(int b);
        double realValue() const {return static_cast<double>(m_a) / m_b;}
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
