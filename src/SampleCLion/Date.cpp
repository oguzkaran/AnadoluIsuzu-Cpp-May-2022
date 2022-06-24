#include <iostream>
#include "Date.hpp"

Date::Date()
{
    std::strcpy(m_dateStr, "01/01/1900");
}

Date::Date(int day, int month, int year)
{
    //...
    std::sprintf(m_dateStr, "%02d/%02d/%04d", day, month, year);
    //...
}


void Date::setDay(int day)
{
    //...
    std::sprintf(m_dateStr, "%02d", day);
    m_dateStr[2] = '/';
    //...
}

void Date::setMonth(int month)
{
    //...
    std::sprintf(m_dateStr + 3, "%02d", month);
    m_dateStr[5] = '/';
    //...
}

void Date::setYear(int year)
{
    //...
    std::sprintf(m_dateStr + 6, "%02d", year);

    //...
}

void Date::print() const
{
    std::cout << m_dateStr << '\n';
}