#include <iostream>
#include <cstdlib>
#include "FileSource.hpp"

namespace org::csystem::parser {
    FileSource::FileSource(const char *path)
    {
        if ((m_f = std::fopen(path, "r")) == nullptr) {
            std::cerr << "Can not open file!...\n";
            std::exit(EXIT_FAILURE); //Exception işlemleri konusunda değiştirilecektir
        }
    }

    int FileSource::nextChar()
    {
        auto res{std::fgetc(m_f)};

        return res == EOF ? -1 : res;
    }

    void FileSource::reset()
    {
        std::fseek(m_f, 0, SEEK_SET);
    }
}
