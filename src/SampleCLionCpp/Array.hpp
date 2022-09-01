/*----------------------------------------------------------------------------------------------------------------------
    File Name       : Array.hpp
    Author          : Anadolu Isuzu Software Group
    Last Update     : 1st Sep 2022
    Platform        : All
    Version         : 2.0.0

    Array class

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <string>
#include <stdexcept>
#include <cstddef>

namespace com::anodoluisuzu::util::container {
    template<typename T, std::size_t N>
    class Array {
    public:
        using value_type = T;
        using reference = value_type &;
        using const_reference = const value_type &;
        using size_type = std::size_t;
        //...
    private:
        T m_t[N];

        constexpr void check(size_type pos);

    public:
        constexpr Array() = default;

        constexpr size_type size() const { return N; }

    public:
        constexpr reference operator[](size_type pos);

        constexpr const_reference operator[](size_type pos) const;

        constexpr reference at(size_type pos);

        constexpr const_reference at(size_type pos) const;
        //...
    };

    template<typename T, std::size_t N>
    constexpr void Array<T, N>::check(size_type pos)
    {
        if (pos >= N)
            throw std::out_of_range{"pos out range:" + std::to_string(pos)};
    }

    template<typename T, std::size_t N>
    constexpr typename Array<T, N>::reference Array<T, N>::operator[](Array<T, N>::size_type pos)
    {
        return m_t[pos];
    }

    template<typename T, std::size_t N>
    constexpr typename Array<T, N>::const_reference Array<T, N>::operator[](Array<T, N>::size_type pos) const
    {
        return m_t[pos];
    }

    template<typename T, std::size_t N>
    constexpr typename Array<T, N>::reference Array<T, N>::at(Array<T, N>::size_type pos)
    {
        check(pos);

        return m_t[pos];
    }


    template<typename T, std::size_t N>
    constexpr typename Array<T, N>::const_reference Array<T, N>::at(Array<T, N>::size_type pos) const
    {
        check(pos);

        return m_t[pos];
    }

}

#endif //ARRAY_HPP_
