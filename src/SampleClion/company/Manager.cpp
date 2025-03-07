#include "Manager.hpp"

namespace com::anadoluisuzu::company {
    Manager &Manager::salary(double s)
    {
        m_salary = s;
        return *this;
    }

    Manager &Manager::department(const std::string &d)
    {
        m_department = d;
        return *this;
    }

    double Manager::calculateInsurancePayment() const
    {
        return m_salary * 1.5;
    }
}