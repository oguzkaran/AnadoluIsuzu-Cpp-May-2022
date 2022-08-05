#include <iostream>
#include <string>

#include "Parser.hpp"
#include "FindAlphabeticCountResetParser.hpp"
#include "StringSource.hpp"
#include "FileSource.hpp"
#include "alphabeticcountapp.hpp"
#include "../csd/utility.hpp"

namespace org::csystem::parser::app {
    using namespace com::anadoluisuzu::parser;

    static IResetSource &getRandomSource(const char *text)
    {
        using org::csystem::util::random::randomInt;
        static StringSource ss{};
        static FileSource fs{"text.txt"};

        switch (randomInt(1, 2)) {
            case 1:
                return ss.text(text);
            default:
                return fs;
        }
    }

    void run()
    {
        using namespace std;
        using namespace org::csystem::parser;

        for (;;) {
            string s{};
            cout << "Input a text:";
            cout.flush();
            cin >> s;

            if (s == "quit")
                break;

            auto &source{getRandomSource(s.c_str())};
            FindAlphabeticCountResetParser parser{source};

            parser.parse();
            cout << "-------------------------------------------------\n";
            parser.parse();
        }
    }
}