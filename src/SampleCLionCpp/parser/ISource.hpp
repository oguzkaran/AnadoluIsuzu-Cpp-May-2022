#ifndef ISOURCE_HPP_
#define ISOURCE_HPP_

struct ISource {
    virtual int nextChar() = 0;
    virtual ~ISource() = default;
};

#endif //ISOURCE_HPP_
