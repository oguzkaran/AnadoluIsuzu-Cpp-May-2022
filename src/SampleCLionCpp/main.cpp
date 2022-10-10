/*----------------------------------------------------------------------------------------------------------------------
    [[deprecated]] attribute'u ile işaretlenmiş bir fonksiyon kullanıldığında derleyicinin bir teşhiş mesajı vermesi
    sağlanabilir
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "csd/utility.hpp"

int main()
{
    using namespace std;
    using org::csystem::util::random::randomInt;

    for (int i = 0; i < 10; ++i)
        randomInt(0, 100);

    cout << '\n';


    return 0;
}
