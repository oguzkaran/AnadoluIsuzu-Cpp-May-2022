/*----------------------------------------------------------------------------------------------------------------------
    File Name       : File.hpp
    Author          : Oğuz Karan
    Last Update     : 24th Aug 2022
    Platform        : All
    Version         : 3.0.0

    Header file for File class that is used for file operations

    Copyleft (c) 1993 by C and System Programmers Association (CSD)
    All Rights Free
----------------------------------------------------------------------------------------------------------------------*/
#ifndef FILE_HPP_
#define FILE_HPP_

#include <iostream>
#include <cstdio>
#include <memory>
#include <functional>

namespace org::csystem::io::file {
    using Uptrf = std::unique_ptr<std::FILE, std::function<void(FILE *)>>;

    enum class Whence {
        SeekSet, SeekCur, SeekEnd
    };

    class File {
        friend std::ostream &operator<<(std::ostream &os, const File &f);
    private:
        Uptrf m_up;
    public:
        File() : m_up{}
        {}
    public:
        [[nodiscard]] bool open(const char *name, const char *mode, bool closeIfOpen = true);
        void close();
        int seek(long offset, Whence whence);
        int seekSet();
        int seekEnd();
        int read();
        int write(int ch);
        void write(const char *str);
        File &operator<<(const char *str);
        void swap(File &other);
        //TODO: std::size_t write(const void *buf, std::size_t size, std::size_t count);
        //TODO: std::size_t read(void *buf, std::size_t size, std::size_t count);
    };
}

#endif //FILE_HPP_