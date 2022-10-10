#include <iostream>
#include <cstdlib>
#include "csd/errorutility.hpp"

namespace org::csystem::util::error {
    void exitFail(const std::string &msg)
    {
        using std::cerr;
        using std::exit;

        cerr << msg << '\n';
        exit(EXIT_FAILURE);
    }
}
