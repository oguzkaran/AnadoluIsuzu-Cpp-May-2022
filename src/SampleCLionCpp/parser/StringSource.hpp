
#ifndef STRINGSOURCE_HPP_
#define STRINGSOURCE_HPP_

#include <string>
#include "ISource.hpp"

class StringSource : ISource {
private:
    std::string m_str;
    std::size_t m_idx;
public:
    explicit StringSource(std::string str) : m_str{std::move(str)}, m_idx{}
    {}
    int nextChar() override;
};


#endif //STRINGSOURCE_HPP_
