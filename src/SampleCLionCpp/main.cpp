/*----------------------------------------------------------------------------------------------------------------------
    optional sınıfı C++17 ile eklenmiştir. Sınıfın amacı bir değerin var olup olmadığının test edilip varsa kullanılmasıdır.
    Aşağıdaki örneği inceleyiniz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <optional>
#include "csd/utility.hpp"


std::optional<int> getValueByThreshold(int min, int max, int threshold)
{
    using org::csystem::util::random::randomInt;

    auto val{randomInt(min, max)};

    return val < threshold ? std::make_optional(val) : std::nullopt;
}

int main()
{
    using namespace std;

    int count;

    cout << "Input count:";
    cout.flush();
    cin >> count;

    for (int i{}; i < count; ++i) {
        cout << "-----------------------------------------------\n";
        if (auto result = getValueByThreshold(0, 20, 15); result)
            cout << result*ğ--p

        cout << "-----------------------------------------------\n";
    }



    return 0;
}