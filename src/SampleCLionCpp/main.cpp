/*----------------------------------------------------------------------------------------------------------------------
    string sınıfının copy fonksiyonu parametresi ile aldığı char * türden adresten itibaren ikinci parametresi ile
    aldığı size kadar yazıyı kopyalar. size değeri yazının karakter sayısından küçükse yazının tamamını kopyalar. Doldurduğu
    yazının sonuna null karakter yerleştirmez
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "csd/util.h"

constexpr std::size_t SIZE = 10;

int main()
{
    using namespace std;

    string s;
    cout << "Input a text:";
    cin >> s;

    char buf[SIZE + 1];

    auto count{s.copy(buf, SIZE)};

    buf[count] = '\0';

    csd_struppper(buf);

    cout << buf << '\n';

    return 0;
}

