
#ifndef STDINSOURCE_HPP_
#define STDINSOURCE_HPP_
#include "ISource.hpp"

namespace org::csystem::parser {
    namespace isuzuparser = com::anadoluisuzu::parser;
    class StdInSource : public isuzuparser::ISource {
    private:
        int m_count;
    public:
        explicit StdInSource(int count) : m_count{count}
        {}
        int nextChar() override;
    };
}


#endif //STDINSOURCE_HPP_
