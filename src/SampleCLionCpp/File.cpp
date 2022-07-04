/*----------------------------------------------------------------------------------------------------------------------
    File Name       : File.cpp
    Author          : Oğuz Karan
    Last Update     : 4th Jul 2022
    Platform        : All
    Version         : 2.0.0

    Implementation file for File class that is used for file operations

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#include "File.hpp"


namespace org::csystem::io::file {

    static int g_whence[] = {SEEK_SET, SEEK_CUR, SEEK_END};


    static inline void closeFileIfOpen(std::FILE *f)
    {
        if (f)
            std::fclose(f);
    }

    std::ostream &operator<<(std::ostream &os, const File &f)
    {
        if (!f.m_f)
            return os;

        int c;

        while ((c = std::fgetc(f.m_f)) != EOF)
            os << static_cast<char>(c);

        return os;
    }

    File::File(File &&r) : m_f{r.m_f}
    {
        r.m_f = nullptr;
    }

    File &File::operator=(File &&r)
    {
        if (this == &r)
            return *this;

        closeFileIfOpen(m_f);
        m_f = r.m_f;
        r.m_f = nullptr;

        return *this;
    }


    File::~File()
    {
        closeFileIfOpen(m_f);
    }

    bool File::open(const char *name, const char *mode, bool closeIfOpen)
    {
        if (!closeIfOpen && m_f)
            return false;

        closeFileIfOpen(m_f);

        return (m_f = std::fopen(name, mode)) != nullptr;
    }

    void File::close()
    {
        closeFileIfOpen(m_f);
    }

    int File::seek(long offset, Whence whence)
    {
        return std::fseek(m_f, offset, static_cast<int>(whence));
    }

    int File::seekSet()
    {
        return seek(0, Whence::SeekSet);
    }

    int File::seekEnd()
    {
        return seek(0, Whence::SeekEnd);
    }

    int File::getc()
    {
        return std::fgetc(m_f);
    }

    int File::putc(int ch)
    {
        return std::fputc(ch, m_f);
    }

    void File::write(const char *str)
    {
        for (int i{}; str[i] != '\0'; ++i)
            std::fputc(str[i], m_f);
    }

    File &File::operator<<(const char *str)
    {
        write(str);
        return *this;
    }
}