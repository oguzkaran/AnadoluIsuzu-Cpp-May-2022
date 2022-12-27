#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "Employee.hpp"

#include <string>

namespace com::anadoluisuzu::company {
    class Manager : public Employee {
    private:
        double m_salary{};
        std::string m_department;
        //...
    public:
        double salary() const {return m_salary;}
        Manager &salary(double s);
        std::string department() const {return m_department;}
        Manager &department(const std::string &d);

        double calculateInsurancePayment() const override;
    };
}

#endif //MANAGER_HPP_
