/*----------------------------------------------------------------------------------------------------------------------
    Aşağıdaki örnekte optinal sınıfı bir veri elemanı olarak kullanılmıştır
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "csd/utility.hpp"

class Person {
private:
    std::string m_firstName;
    std::optional<std::string> m_middleName;
    std::string m_familyName;
public:
    Person(std::string firstName, std::optional<std::string> middleName, std::string familyName)
        : m_firstName{std::move(firstName)}, m_middleName{std::move(middleName)}, m_familyName{std::move(familyName)}
    {}

    Person(std::string firstName, std::string familyName) : Person{std::move(firstName), std::nullopt, std::move(familyName)}
    {}


    //...

};

int main()
{
    using namespace std;
    Person p1{"Oguz", "Karan"};
    Person p2{"Ali", "Vefa", "Serce"};

    return 0;
}