#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include <cstdint>
#include <cstddef>

class Sensor {
public:
    static std::size_t count;
    char name[256];
    char host[16];
    std::uint16_t port;
public:
    static void resetCount();
    void set(const char *n, const char *h, std::uint16_t p);
    void setName(const char *n);
    void setHost(const char *h);
    void setPort(std::uint16_t p);
    void open();
    void close();
};


#endif //SENSOR_HPP_
