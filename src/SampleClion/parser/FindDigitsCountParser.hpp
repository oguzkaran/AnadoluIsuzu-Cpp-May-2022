#ifndef FINDDIGITSCOUNTPARSER_HPP_
#define FINDDIGITSCOUNTPARSER_HPP_

#include "ISource.hpp"
#include "Parser.hpp"


namespace org::csystem::parser {
    namespace isuzuparser = com::anadoluisuzu::parser;

    class FindDigitsCountParser : public isuzuparser::Parser {
    public:
        explicit FindDigitsCountParser(isuzuparser::ISource &source) : Parser{source}
        {}
        void parse() override;
    };
}


#endif //FINDDIGITSCOUNTPARSER_HPP_
