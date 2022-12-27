#ifndef IRESET_HPP_
#define IRESET_HPP_

namespace com::anadoluisuzu::parser {
    struct IReset {
        virtual void reset() = 0; //Reset işlemine karşılık gelecek
        virtual ~IReset() = default;
    };
}

#endif //IRESET_HPP_
