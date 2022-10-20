#include <iostream>
#include <string>

#include "csd/stdinutility.hpp"

namespace com::anadoluisuzu::util {

    int getInt(const std::string &prompt, const char *promptEnd, bool flush)
    {
        using namespace std;

        int val;
        cout << prompt << promptEnd;
        if (flush)
            cout.flush();

        cin >> val;

        return val;
    }

    double getDouble(const std::string &prompt, const char *promptEnd, bool flush)
    {
        using namespace std;

        double val;
        cout << prompt << promptEnd;
        if (flush)
            cout.flush();

        cin >> val;

        return val;
    }
}