/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Complex.hpp
    Author          : Oğuz Karan
    Last Update     : 29th Jun 2022
    Platform        : All
    Version         : 1.0.0

    Header file for Complex class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <iostream>
#include <cmath>

class Complex {
    friend std::ostream &operator <<(std::ostream &os, const Complex &z);
    friend std::istream &operator >>(std::istream &is, Complex &z);
    friend Complex operator +(double value, const Complex &z);
    friend Complex operator -(double value, const Complex &z);
    /*
     * TODO:
     friend Complex operator *(double value, const Complex &z);
     friend Complex operator /(double value, const Complex &z);
     */
private:
    double m_real;
    double m_imag;
    double m_delta{0.00001};
public:
    constexpr explicit Complex(double real = 0, double imag = 0) : m_real{real}, m_imag{imag}
    {}
public:
    constexpr double real() const {return m_real;}
    constexpr void real(double value) {m_real = value;}
    constexpr double imag() const {return m_imag;}
    constexpr void imag(double value) {m_imag = value;}
    double norm() const {return std::sqrt(m_real * m_real + m_imag * m_imag);}
    double length() const {return norm();}
    double delta() const  {return m_delta;}
    double delta(double value) {m_delta = value;}
public:
    Complex operator+(const Complex &other) const;
    Complex operator+(double value) const;
    Complex operator-(const Complex &other) const;
    Complex operator-(double value) const;
    Complex &operator+=(const Complex &other);
    Complex &operator+=(double value);
    Complex &operator-=(const Complex &other);
    Complex &operator-=(double value);

    /*
    TODO:
    Complex operator*(const Complex &other) const;
    Complex operator*(double value) const;
    Complex operator/(const Complex &other) const;
    Complex operator/(double value) const;
    Complex &operator*=(const Complex &other);
     Complex &operator*=(double value);
    Complex &operator/=(const Complex &other);
     Complex &operator/=(double value);
    */

    Complex operator -() const;
    Complex operator +() const;

    Complex &operator ++();
    Complex operator ++(int);
    Complex &operator --();
    Complex operator --(int);

    bool operator ==(const Complex &other) const;

    explicit operator double() const {return norm();}

    double operator()() const;
    void operator()(double real, double imag);
    void operator()(double real);
};


#endif //COMPLEX_HPP_
