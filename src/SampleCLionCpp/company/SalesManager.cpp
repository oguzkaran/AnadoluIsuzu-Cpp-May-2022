#include "SalesManager.hpp"

namespace com::anadoluisuzu::company {
    double SalesManager::calculateInsurancePayment() const
    {
        return Manager::calculateInsurancePayment() + m_extra;
    }
}

