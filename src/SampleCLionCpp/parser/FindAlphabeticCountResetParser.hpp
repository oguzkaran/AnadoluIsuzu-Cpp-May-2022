#ifndef FINDALPHABETICCOUNTPARSER_HPP_
#define FINDALPHABETICCOUNTPARSER_HPP_

#include "IResetSource.hpp"
#include "ResetParser.hpp"


namespace org::csystem::parser {
    namespace isuzuparser = com::anadoluisuzu::parser;

    class FindAlphabeticCountResetParser : public isuzuparser::ResetParser {
    public:
        explicit FindAlphabeticCountResetParser(isuzuparser::IResetSource &source) : ResetParser{source}
        {}
        void parse() override;
    };
}


#endif //FINDALPHABETICCOUNTPARSER_HPP_
