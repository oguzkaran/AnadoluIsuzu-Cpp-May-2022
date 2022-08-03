#include <iostream>
#include "companyApp.hpp"

#include "Manager.hpp"
#include "Worker.hpp"
#include "SalesManager.hpp"
#include "HumanResources.hpp"

namespace com::anadoluisuzu::company {
    static Manager getManager()
    {
        Manager m;

        m.name("Ali");
        m.citizenId("12345678912");
        m.address("Mecidiyeköy");
        m.salary(40000);
        m.department("Pazarlama");

        return m;
    }

    static Worker getWorker()
    {
        Worker w;

        w.name("Veli");
        w.citizenId("12345678914");
        w.address("Şişli");
        w.feePerHour(100);
        w.hourPerDay(8);

        return w;
    }

    static SalesManager getSalesManager()
    {
        SalesManager m;

        m.name("Selami");
        m.citizenId("12345678918");
        m.address("Beylikdüzü");
        m.salary(40000);
        m.department("Pazarlama");
        m.extra(5000);

        return m;
    }

    void runCompanyApp()
    {
        HumanResources hr;
        auto m{getManager()};
        auto sm{getSalesManager()};
        auto w{getWorker()};

        hr.payInsurance(m);
        hr.payInsurance(sm);
        hr.payInsurance(w);
    }
}