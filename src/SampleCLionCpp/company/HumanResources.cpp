#include "HumanResources.hpp"
#include <iostream>

namespace com::anadoluisuzu::company {
    void HumanResources::payInsurance(Employee &e)
    {
        using std::cout;

        cout << "Name:" << e.name() << '\n';
        cout << "Citizen Id:" << e.citizenId() << '\n';
        cout << "Address:" << e.address() << '\n';

        //...
    }
}