
#ifndef WORKER_HPP_
#define WORKER_HPP_
#include "Employee.hpp"

namespace com::anadoluisuzu::company {
    class Worker : public Employee {
    private:
        double m_feePerHour{};
        int m_hourPerDay{};
    public:
        double feePerHour() const {return m_feePerHour;}
        Worker &feePerHour(double fee);
        int hourPerDay() const {return m_hourPerDay;}
        Worker &hourPerDay(int hour);

        double calculateInsurancePayment() const override;
    };
}


#endif //WORKER_HPP_
