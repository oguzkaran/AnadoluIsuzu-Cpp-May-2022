
#ifndef SALESMANAGER_HPP_
#define SALESMANAGER_HPP_

#include "Manager.hpp"

namespace com::anadoluisuzu::company {
    class SalesManager : public Manager {
    private:
        double m_extra;
    public:
        double extra() const {return m_extra;}
        void extra(double amount) {m_extra = amount;}
        double calculateInsurancePayment() const override;
    };
}


#endif //SALESMANAGER_HPP_
