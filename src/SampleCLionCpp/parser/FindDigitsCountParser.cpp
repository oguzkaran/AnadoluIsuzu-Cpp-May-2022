#include <iostream>
#include <cctype>

#include "FindDigitsCountParser.hpp"

namespace org::csystem::parser {
    void FindDigitsCountParser::parse()
    {
        using std::cout;
        using std::isdigit;

        auto count{0};
        int ch;

        while ((ch = source->nextChar()) != -1)
            if ((isdigit(ch)))
                ++count;

        cout << "Alphabetic Count: " << count << '\n';
    }
}
