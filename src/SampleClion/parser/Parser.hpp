#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "IParser.hpp"
#include "ISource.hpp"

namespace com::anadoluisuzu::parser {
    class Parser : public IParser {
    protected:
        ISource *source;
        explicit Parser(ISource &source) : source{&source}
        {}
    };
}


#endif //PARSER_HPP_
