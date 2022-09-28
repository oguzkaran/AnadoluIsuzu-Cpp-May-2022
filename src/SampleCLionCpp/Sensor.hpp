#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include <iostream>
#include <string>
#include <cstdint>
#include <cstddef>

namespace AnadoluIsuzu {
    class Sensor {
        friend std::ostream &operator<<(std::ostream &os, const Sensor &s);
    private:
        static std::size_t ms_count;
        std::string m_name;
        std::string m_host;
        std::uint16_t m_port;
        bool m_open;
    public:
        Sensor(const char *name, const char *host, std::uint16_t port, bool open = true);

    public:
        static std::size_t getCount()
        { return ms_count; }

        std::uint16_t getPort() const
        { return m_port; }

        std::string getName() const
        { return m_name; }

        std::string getHost() const
        { return m_host; }

        bool isOpen() const
        { return m_open; }

        void set(const char *n, const char *h, std::uint16_t p);

        void setName(const char *n);

        void setHost(const char *h);

        void setPort(std::uint16_t p);

    public:
        static void resetCount();

        void open();

        void close();
    };
}


#endif //SENSOR_HPP_
