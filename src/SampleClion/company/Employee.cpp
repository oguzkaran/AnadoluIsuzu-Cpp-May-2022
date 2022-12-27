#include "Employee.hpp"

namespace com::anadoluisuzu::company {
    Employee &Employee::name(const std::string &n)
    {
        m_name = n;

        return *this;
    }

    Employee &Employee::citizenId(const std::string &id)
    {
        m_citizenId = id;

        return *this;
    }

    Employee &Employee::address(const std::string &a)
    {
        m_address = a;

        return *this;
    }
}