#ifndef FILESOURCE_HPP_
#define FILESOURCE_HPP_

#include <cstdio>
#include "IResetSource.hpp"

namespace org::csystem::parser {
    namespace isuzuparser = com::anadoluisuzu::parser;
    class FileSource : public isuzuparser::IResetSource {
    private:
        std::FILE *m_f;
    public:
        explicit FileSource(const char *path);

        int nextChar() override;
        void reset() override;
    };
}


#endif //FILESOURCE_HPP_
