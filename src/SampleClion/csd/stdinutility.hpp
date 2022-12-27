/*----------------------------------------------------------------------------------------------------------------------
    File Name       : stdinutility.hpp
    Author          : Oğuz Karan
    Last Update     : 07th Nov 2022
    Platform        : All
    Version         : 2.0.0

    Header file for common stdin operations

    Copyleft (c) 1993 by  Anadolu Isuzu
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef STDINUTILITY_HPP_
#define STDINUTILITY_HPP_

#include <string>

namespace com::anadoluisuzu::util {

    [[deprecated("use readInt")]]
    [[nodiscard]]
    int getInt(const std::string &prompt, const char *promptEnd = "", bool flush = true);

    [[deprecated("use readDouble")]]
    [[nodiscard]]
    double getDouble(const std::string &prompt, const char *promptEnd = "", bool flush = true);

    [[nodiscard]]
    int readInt(const std::string &prompt, const char *promptEnd = "", bool flush = true);

    [[nodiscard]]
    double readDouble(const std::string &prompt, const char *promptEnd = "", bool flush = true);


}

#endif //STDINUTILITY_HPP_
