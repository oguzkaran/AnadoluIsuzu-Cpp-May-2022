#ifndef ERRORUTILITY_HPP_
#define ERRORUTILITY_HPP_

#include <string>
namespace org::csystem::util::error {
    [[noreturn]] void exitFail(const std::string &msg);
}

#endif //ERRORUTILITY_HPP_
