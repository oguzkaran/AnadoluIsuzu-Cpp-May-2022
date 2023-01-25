/*----------------------------------------------------------------------------------------------------------------------
    Yazılımda test süreçleri ürün geliştirmenin önemli bir aşamasını oluşturmaktadır. Bazı yazılımlarda yazılımların
    herşeyiyle doğru olması kritik öneme sahip olabilir. Bazı yazılımların hata toleransı olabilir. Gerektiğinde
    sonradan düzeltilebilir,

    Eskiden yazılım geliştirmede test süreçleri lüks olarak değerlendiriliyordu. Bu nedenle yazlnızca büyük firmalar
    test bölümleri barındırıyorlardı. Ancak günümüzde yazılımda kalite (software quality) bilinci çok daha fazla artmış ve
    test süreçleri çok daha bilinir hale gelmiştir


----------------------------------------------------------------------------------------------------------------------*/
//#define NDEBUG

#include <iostream>
#include <cstdlib>
#include "csd/utility.hpp"
#include "File.hpp"

int main()
{
    using namespace std;
    using org::csystem::io::file::File;

    File f;

    auto status{f.open("test.dat", "r")};

    if (!status) {
        cerr << "Can not open file!...\n";
        std::exit(EXIT_FAILURE);
    }

    int ch;

    while ((ch = f.read()) != EOF)
        cout << static_cast<char>(ch);

    cout << '\n';

    CSD_VERIFY(f.seekSet() == 0);

    while ((ch = f.read()) != EOF)
        cout << static_cast<char>(ch);

    cout << '\n';

    return 0;
}

