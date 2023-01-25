#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#define NDEBUG

#include <cstddef>
#include <cstring>
#include <cassert>

template <typename T>
class Vector {
private:
    static constexpr std::size_t ms_default_capacity = 10;
    T *m_p;
    std::size_t m_idx;
    std::size_t m_capacity;
private:
    void change_capacity(std::size_t capacity);
public:
    Vector();
    explicit Vector(std::size_t initialCapacity);
    [[nodiscard]] std::size_t capacity() const {return m_capacity;}
    [[nodiscard]] std::size_t size() const {return m_idx;}
    //...
    void push_back(const T &t);

    //...
};

template <typename T>
Vector<T>::Vector() : m_p{new T[ms_default_capacity]}, m_idx{}, m_capacity{ms_default_capacity}
{
}

template <typename T>
Vector<T>::Vector(std::size_t initialCapacity) : m_p{new T[initialCapacity]}, m_idx{}, m_capacity{initialCapacity}
{
}


template <typename T>
void Vector<T>::change_capacity(std::size_t capacity)
{
    assert(capacity > m_capacity);

    auto p = new T[capacity];
    auto temp = m_p;

    std::memcpy(p, m_p, capacity * sizeof(T));
    m_capacity = capacity;

    delete [] temp;
}

template <typename T>
void Vector<T>::push_back(const T &t)
{
    if (m_idx == m_capacity)
        change_capacity(m_capacity * 2);

    m_p[m_idx++] = t;
}

#endif //VECTOR_HPP_
