
#include "StringSource.hpp"

int StringSource::nextChar()
{
    return m_idx == m_str.size() ? -1 : m_str[m_idx++];
}
