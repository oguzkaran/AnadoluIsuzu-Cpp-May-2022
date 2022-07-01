/*----------------------------------------------------------------------------------------------------------------------
    İsim Alanları (namespace): İsim alanları isim çakışmasını engellemek için düşünülmüştür.
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "File.hpp"
#include "csd/errorutil.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        csd_exit_fail("Wrong number of arguments");

    File f{};

    if (!f.open(argv[1], "w+t"))
        csd_exit_fail("Can not open file");

    f.write("Anadolu Isuzu"); //<< "C and System Programmers Association\n";

    std::cout << f;

    return 0;
}

