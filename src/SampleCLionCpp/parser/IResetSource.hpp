#ifndef IRESETSOURCE_HPP_
#define IRESETSOURCE_HPP_

#include "ISource.hpp"
#include "IReset.hpp"

namespace com::anadoluisuzu::parser {
    struct IResetSource : ISource, IReset {
        ~IResetSource() override = default;
    };
}

#endif //IRESETSOURCE_HPP_
