#ifndef STDINUTILITY_HPP_
#define STDINUTILITY_HPP_

#include <string>

namespace com::anadoluisuzu::util {
    int getInt(const std::string &prompt, const char *promptEnd = "", bool flush = true);
    double getDouble(const std::string &prompt, const char *promptEnd = "", bool flush = true);
}

#endif //STDINUTILITY_HPP_
