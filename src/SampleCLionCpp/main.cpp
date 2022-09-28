/*----------------------------------------------------------------------------------------------------------------------
    Yukarıdaki writeReverse fonksiyonu aşağıdaki gibi reverse iterator kullanılarak ve daha etkin bir biçimde tanımlanabilir.
    Yukarıdaki örnekte fonksiyon stack kullanımını göstermek için yazılmıştır
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>

template <typename T, typename Container>
void writeReverse(const Container &c, const std::string &sep = "", char end = '\n', std::ostream &os = std::cout)
{
    using namespace std;

    for_each(rbegin(c), rend(c), [&os, sep](const auto &e) {os << e << sep;});

    os << end;
}


int main()
{
    using namespace std;

    vector<int> iVec(26);
    list<int> iList(26);
    deque<int> iDeq(26);
    string str(26, ' ');

    iota(begin(iVec), end(iVec), 0);
    iota(begin(iList), end(iList), 0);
    iota(begin(iDeq), end(iDeq), 0);
    iota(begin(str), end(str), 'A');

    writeReverse<int>(iVec, " ");
    writeReverse<int>(iList, " ");
    writeReverse<int>(iDeq,  " ");
    writeReverse<char>(str);

    return 0;
}


