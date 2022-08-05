#include <iostream>
#include <cctype>

#include "FindAlphabeticCountResetParser.hpp"

namespace org::csystem::parser {
    void FindAlphabeticCountResetParser::parse()
    {
        using std::cout;
        using std::isalpha;

        auto count{0};
        int ch;
        source->reset();

        while ((ch = source->nextChar()) != -1)
            if ((isalpha(ch)))
                ++count;

        cout << "Alphabetic Count: " << count << '\n';
    }
}
