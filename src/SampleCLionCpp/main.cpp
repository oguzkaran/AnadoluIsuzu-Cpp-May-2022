/*----------------------------------------------------------------------------------------------------------------------
    string sınıfının iki tane iterator alan append üye fonksiyonu
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include "csd/utility.hpp"

template <typename T, std::size_t N>
std::ostream &operator <<(std::ostream &os, const std::array<T, N> &a)
{
    for_each(a.begin(), a.end(), [](const auto &r) {std::cout << r << ' ';});

    return os;
}

int main()
{
    using namespace std;
    using org::csystem::util::random::randomChar;

    constexpr std::size_t N = 10;

    array<char, N> a{};
    string s{"Text:"};
    generate(begin(a), end(a), randomChar);
    s.append(cbegin(a), cend(a));

    cout << a << '\n';
    cout << s << '\n';

    return 0;
}

