#ifndef ISOURCE_HPP_
#define ISOURCE_HPP_

namespace com::anadoluisuzu::parser {
    struct ISource {
        virtual int
        nextChar() = 0; //Her çağrıda bir sonraki karakteri döndürür. Eğer artık karakter kalmadıysa -1 değerini döndürür
        virtual ~ISource() = default;
    };
}

#endif //ISOURCE_HPP_
