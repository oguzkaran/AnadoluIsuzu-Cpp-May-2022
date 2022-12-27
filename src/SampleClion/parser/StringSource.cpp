
#include "StringSource.hpp"

namespace org::csystem::parser {
    StringSource &StringSource::text(const char *str)
    {
        m_str = str;
        m_idx = 0;
        return *this;
    }

    int StringSource::nextChar()
    {
        return m_idx == m_str.size() ? -1 : m_str[m_idx++];
    }

    void StringSource::reset()
    {
        m_idx = 0;
    }
}
