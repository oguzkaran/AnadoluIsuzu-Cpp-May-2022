/*----------------------------------------------------------------------------------------------------------------------
   [] operatörü ile ilgili indeksteki karakter değiştirilebilir
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "csd/utility.hpp"

int main(int argc, char **argv)
{
    using namespace std;
    using namespace org::csystem::util::random;

    auto s{randomString(randomInt(5, 10))};

    cout << s << '\n';

    auto ch{randomChar()};

    cout << "Character:" << ch << '\n';

    for (size_t i{}; i < s.size(); ++i)
        s[i] ^= ch;

    cout << s << '\n';

    for (size_t i{}; i < s.size(); ++i)
        s[i] ^= ch;

    cout << s << '\n';

    return 0;
}


