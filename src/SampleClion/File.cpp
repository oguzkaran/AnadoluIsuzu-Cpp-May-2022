/*----------------------------------------------------------------------------------------------------------------------
    File Name       : File.cpp
    Author          : Oğuz Karan
    Last Update     : 24th Aug 2022
    Platform        : All
    Version         : 3.0.0

    Implementation file for File class that is used for file operations

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include "File.hpp"
#include <array>

namespace org::csystem::io::file {

    static std::array<int, 3> g_whence = {SEEK_SET, SEEK_CUR, SEEK_END};
    static auto deleter = [](FILE *f) {
        if (f)
            std::fclose(f) == 0;
    };

    std::ostream &operator<<(std::ostream &os, const File &f)
    {
        if (!f.m_up.get())
            return os;

        int c;

        while ((c = std::fgetc(f.m_up.get())) != EOF)
            os << static_cast<char>(c);

        return os;
    }

    bool File::open(const char *name, const char *mode, bool closeIfOpen)
    {
        if (!closeIfOpen && m_up.get())
            return false;

        m_up.reset();
        auto f = std::fopen(name, mode);
        m_up = Uptrf{f, deleter};

        return f != nullptr;
    }

    void File::close()
    {
        m_up.reset();
    }

    int File::seek(long offset, Whence whence)
    {
        return std::fseek(m_up.get(), offset, static_cast<int>(whence));
    }

    int File::seekSet()
    {
        return seek(0, Whence::SeekSet);
    }

    int File::seekEnd()
    {
        return seek(0, Whence::SeekEnd);
    }

    int File::read()
    {
        return std::fgetc(m_up.get());
    }

    int File::write(int ch)
    {
        return std::fputc(ch, m_up.get());
    }

    void File::write(const char *str)
    {
        for (int i{}; str[i] != '\0'; ++i)
            std::fputc(str[i], m_up.get());
    }

    File &File::operator<<(const char *str)
    {
        write(str);
        return *this;
    }

    void File::swap(File &other)
    {
        m_up.swap(other.m_up);
    }
}