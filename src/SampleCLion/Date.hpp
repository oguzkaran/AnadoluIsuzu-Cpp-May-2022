#ifndef DATE_HPP_
#define DATE_HPP_

#include <cstdio>
#include <cstdlib>

class Date {
private:
    char m_dateStr[11]{}; //dd/MM/yyyy
public:
    Date();
    Date(int day, int month, int year);
public:
    int getDay() const {return static_cast<int>(std::strtol(m_dateStr, nullptr, 10));}
    int getMonth() const {return static_cast<int>(std::strtol(m_dateStr + 3 , nullptr, 10));}
    int getYear() const {return static_cast<int>(std::strtol(m_dateStr + 6, nullptr, 10));}

    void setDay(int day);
    void setMonth(int month);
    void setYear(int day);
    void print() const;
};


#endif //DATE_HPP_
