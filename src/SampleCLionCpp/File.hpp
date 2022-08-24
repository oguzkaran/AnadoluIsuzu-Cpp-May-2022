/*----------------------------------------------------------------------------------------------------------------------
    File Name       : File.hpp
    Author          : Oğuz Karan
    Last Update     : 24th Aug 2022
    Platform        : All
    Version         : 2.0.0

    Header file for File class that is used for file operations

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef FILE_HPP_
#define FILE_HPP_

#include <iostream>
#include <cstdio>

namespace org::csystem::io::file {
    enum class Whence {
        SeekSet, SeekCur, SeekEnd
    };

    class File {
        friend std::ostream &operator<<(std::ostream &os, const File &f);
    private:
        std::FILE *m_f;
    public:
        File() : m_f{}
        {}

        File(const File &) = delete;

        File &operator=(const File &) = delete;

        File(File &&r) noexcept;

        File &operator=(File &&r) noexcept;

        ~File();

    public:
        bool open(const char *name, const char *mode, bool closeIfOpen = true);

        void close();

        int seek(long offset, Whence whence);

        int seekSet();

        int seekEnd();

        int getc();

        int putc(int ch);

        void write(const char *str);

        File &operator<<(const char *str);
        //TODO: std::size_t write(const void *buf, std::size_t size, std::size_t count);
        //TODO: std::size_t read(void *buf, std::size_t size, std::size_t count);

        void swap(File &other);
    };

#endif //FILE_HPP_
}