#include "Worker.hpp"

namespace com::anadoluisuzu::company {

    Worker &Worker::feePerHour(double fee)
    {
        m_feePerHour = fee;

        return *this;
    }

    Worker &Worker::hourPerDay(int hour)
    {
        m_hourPerDay = hour;

        return *this;
    }

    double Worker::calculateInsurancePayment() const
    {
        return m_feePerHour * m_hourPerDay * 30;
    }

}