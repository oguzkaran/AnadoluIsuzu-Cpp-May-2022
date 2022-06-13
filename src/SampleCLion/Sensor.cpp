#include <iostream>
#include <cstring>
#include "Sensor.hpp"

std::size_t Sensor::count;

void Sensor::resetCount()
{
    std::cout << "All open sensors closed\n";
    count = 0;
}

void Sensor::set(const char *n, const char *h, std::uint16_t p)
{
    setName(n);
    setHost(h);
    setPort(p);
}

void Sensor::setName(const char *n)
{
    std::strcpy(name, n);
}

void Sensor::setHost(const char *h)
{
    std::strcpy(host, h);
}

void Sensor::setPort(std::uint16_t p)
{
    port = p;
}


void Sensor::open()
{
    std::cout << name << " opened\n";
    ++count;
}


void Sensor::close()
{
    std::cout << name << " closed\n";
    --count;
}

