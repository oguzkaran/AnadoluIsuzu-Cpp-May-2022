/*----------------------------------------------------------------------------------------------------------------------
   Template fonksiyonlar
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "Fraction.hpp"

int main()
{
    using namespace std;
    using org::csystem::math::Fraction;

    Fraction f{10, -4};

    cout << f << '\n';

    for (;;) {
        try {
            cout << "Input a fraction:";
            cout.flush();
            cin >> f;

            cout << f << '\n';

            f.numerator(f.numerator() * 2);
            f.denominator(f.denominator() * 3);
        }
        catch (const invalid_argument &ex) {
            cerr << ex.what() << '\n';
        }

        if (f.numerator() == 0)
            break;
    }

    return 0;
}
