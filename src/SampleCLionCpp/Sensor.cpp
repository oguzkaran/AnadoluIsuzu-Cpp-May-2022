#include <iostream>
#include "Sensor.hpp"

namespace AnadoluIsuzu {
    std::size_t Sensor::ms_count;

    Sensor::Sensor(const char *name, const char *host, std::uint16_t port, bool open)
                    : m_port{port}, m_name{name}, m_host{host}, m_open{open}
    {
        if (open)
            ++ms_count;
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

    void Sensor::setName(const char *name)
    {
        //...
        m_name = name;
    }

    void Sensor::setHost(const char *host)
    {
        //...
        m_host = host;
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
}