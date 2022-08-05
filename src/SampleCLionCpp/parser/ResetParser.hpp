#ifndef RESETPARSER_HPP_
#define RESETPARSER_HPP_

#include "IParser.hpp"
#include "IResetSource.hpp"

namespace com::anadoluisuzu::parser {
    class ResetParser : public IParser {
    protected:
        IResetSource *source;
        explicit ResetParser(IResetSource &source) : source{&source}
        {}
    };
}


#endif //RESETPARSER_HPP_
