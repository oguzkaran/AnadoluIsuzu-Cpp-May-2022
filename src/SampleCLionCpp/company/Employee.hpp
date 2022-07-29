#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <string>
namespace com::anadoluisuzu::company {
    class Employee {
    private:
        std::string m_name;
        std::string m_citizenId;
        std::string m_address;
        //...
    public:
        std::string name() const {return m_name;}
        Employee &name(const std::string &n);
        std::string citizenId() const {return m_citizenId;}
        Employee &citizenId(const std::string &id);
        std::string address() const {return m_address;}
        Employee &address(const std::string &a);
    };
}


#endif //EMPLOYEE_HPP_
