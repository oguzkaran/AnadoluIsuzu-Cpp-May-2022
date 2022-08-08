/*----------------------------------------------------------------------------------------------------------------------
   Bir exception nesnesinin yeniden fırlatılması
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include "csd/utility.hpp"

std::string getRandomString(std::size_t n)
{
    using org::csystem::util::random::randomInt;
    using org::csystem::util::random::randomBool;
    using std::string;
    using std::out_of_range;
    using std::to_string;

    string str;

    if (n == 0 || str.max_size() < n)
        throw out_of_range{"Invalid Argument: " + to_string(static_cast<unsigned long>(n))};

    for (size_t i{}; i < n; ++i)
        str += static_cast<char>(randomInt(0, 25) + (randomBool() ? 'A' : 'a'));

    return str;
}

double csd_log10(double a)
{
    if (a == 0)
        throw std::invalid_argument{"UNDEFINED"};

    if (a < 0)
        throw std::invalid_argument{"INDETERMINATE"};

    return std::log10(a);
}


void doWork()
{
    using std::cout;
    using std::cin;

    try {
        double a;
        int n;

        cout << "Input a number:";
        cout.flush();
        cin >> a;

        cout << "Input a count:";
        cout.flush();
        cin >> n;

        auto result{csd_log10(a)};

        cout << "log10(" << a << ") = " << result << '\n';

        auto str{getRandomString(n)};

        cout << "Generated Password:" << str << '\n';
    }
    catch (std::invalid_argument &ex) {
        cout << "Invalid Argument in doWork:" << ex.what() << '\n';
        throw;
    }

    cout << "doWork ends!...\n";
}

int main()
{
    using namespace std;

    int count;

    cout << "Input count:";
    cout.flush();
    cin >> count;

    for (int i{}; i < count; ++i) {
        try {
            doWork();
        }
        catch (const std::out_of_range &ex) {
            cout << "Out of range in main: " << ex.what() << '\n';
        }
        catch (std::invalid_argument &ex) {
            cout << "Invalid Argument in main:" << ex.what() << '\n';
        }

        cout << "Thanks!...\n";
    }

    return 0;
}
