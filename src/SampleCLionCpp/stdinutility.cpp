/*----------------------------------------------------------------------------------------------------------------------
    File Name       : stdinutility.cpp
    Author          : Oğuz Karan
    Last Update     : 07th Nov 2022
    Platform        : All
    Version         : 2.0.0

    Implementation file for common stdin operations

    Copyleft (c) 1993 by Anadolu Isuzu
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
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

    int readInt(const std::string &prompt, const char *promptEnd, bool flush)
    {
        using namespace std;

        int val;
        cout << prompt << promptEnd;
        if (flush)
            cout.flush();

        cin >> val;

        return val;
    }

    double readDouble(const std::string &prompt, const char *promptEnd, bool flush)
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