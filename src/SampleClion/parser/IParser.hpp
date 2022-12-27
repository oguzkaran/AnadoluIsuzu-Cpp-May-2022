#ifndef IPARSER_HPP_
#define IPARSER_HPP_

namespace com::anadoluisuzu::parser {
    struct IParser {
        virtual void parse() = 0;
        virtual ~IParser() = default;
    };
}


#endif //IPARSER_HPP_
