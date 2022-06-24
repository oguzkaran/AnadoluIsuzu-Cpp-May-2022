#include <iostream>
#include <cstring>
#include "Sensor.hpp"

std::size_t Sensor::ms_count;

Sensor::Sensor(const char *name, const char *host, std::uint16_t port, bool open) : m_port{port}
{
    if (open)
        ++ms_count;

    setName(name);
    setHost(host);
}

void Sensor::resetCount()
{
    std::cout << "All open sensors closed\n";
    ms_count = 0;
}

void Sensor::set(const char *n, const char *h, std::uint16_t p)
{
    setName(n);
    setHost(h);
    setPort(p);
}

void Sensor::setName(const char *n)
{
    //...
    std::strcpy(m_name, n);
}

void Sensor::setHost(const char *h)
{
    //...
    std::strcpy(m_host, h);
}

void Sensor::setPort(std::uint16_t p)
{
    m_port = p < 1024 || p > 65535 ? 1024 : p;
}


void Sensor::open()
{
    std::cout << m_name << " opened\n";
    ++ms_count;
}


void Sensor::close()
{
    std::cout << m_name << " closed\n";
    --ms_count;
}

