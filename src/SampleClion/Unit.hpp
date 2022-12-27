/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Unit.hpp
    Author          : Isuzu Group, Oğuz Karan
    Last Update     : 29th Sug 2022
    Platform        : All
    Version         : 1.0.0

    Header file for template Unit class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <iostream>

namespace org::csystem::util {
    template <typename T>
    class Unit {
        template <typename U>
        friend std::ostream &operator <<(std::ostream &os, const Unit<U> &u);
        template <typename U>
        friend std::istream &operator >>(std::istream &is, Unit<U> &u);
    private:
        T m_t;
    public:
        explicit Unit(const T &t = T{}) : m_t{t}
        {}
    public:
        T value() const {return m_t;}
        void value(const T &t) {m_t = t;}
    public:
        explicit operator T() const
        {
            return m_t;
        }
    };

    template <typename U>
    std::ostream &operator <<(std::ostream &os, const Unit<U> &u)
    {
        return os << u.m_t;
    }

    template <typename U>
    std::istream &operator >>(std::istream &is, Unit<U> &u)
    {
        return is >> u.m_t;
    }

    template <typename T>
    using UUnit = Unit<Unit<T>>;
}



#endif //UNIT_HPP_
