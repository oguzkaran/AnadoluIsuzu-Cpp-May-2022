#ifndef STRINGSOURCE_HPP_
#define STRINGSOURCE_HPP_

#include <string>
#include "IResetSource.hpp"

namespace org::csystem::parser {
    namespace isuzuparser = com::anadoluisuzu::parser;

    class StringSource : public isuzuparser::IResetSource {
    private:
        std::string m_str;
        std::size_t m_idx;
    public:
        explicit StringSource(std::string str = "") : m_str{std::move(str)}, m_idx{}
        {}

        StringSource &text(const char *str);

        int nextChar() override;
        void reset() override;
    };
}


#endif //STRINGSOURCE_HPP_
