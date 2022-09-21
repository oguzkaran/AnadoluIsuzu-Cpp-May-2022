/*----------------------------------------------------------------------------------------------------------------------
    Yukarıdaki örnek aşağıdaki gibi "Lambda ifadeleri (lambda expressions)" kullanılarak yazılabilir. Lambda ifadeleri
    C++11 ile dile katılmış ve her standartta ayrı özellikler eklenmiştir. Lambda ifadeleri bir closure belirtir. Yani
    aslında derleyici lambda ifadesini gördüğünde uygun bir "functor" yazar. Aşağıdaki örnekte generate_n algoritmasında
    verilen lambda ifadesi için derleyici yaklaşık olarak aşağıdaki gibi bir sınıf yazar:
        class xyz_ {
        public:
            std::string operator()() const
            {
                using org::csystem::util::random::randomString;
                using org::csystem::util::random::randomInt;

                return randomString(randomInt(5, 10));
            }

        };

    generate_n çağrısı da yaklaşık olarak şu şekilde yapılır:
        generate_n(back_inserter(texts), count, xyz_{});
    for_each algoritmasında verilen lambda ifadesi için derleyici yaklaşık olarak aşağıdaki gibi bir sınıf yazar:

        class abc_ {
        public:
            void operator()(const std::string &s) const
            {
                std::cout << s << ' ';
            }
        };
    for_each çağrısı da yaklaşık olarak şu şekilde yapılır:
        for_each(begin(texts), end(texts), abc_{});

    copy_if algoritmasında verilen lambda ifadesi için derleyici yaklaşık olarak aşağıdaki gibi bir sınıf yazar:
        class tuv_ {
        private:
            int m_threshold;
        public:
            tuv_(int threshold) : m_threshold{threshold}
            {}
            bool operator()(const std::string &s) const
            {
                return s.length() > m_threshold;
            }
        };
     copy_if çağrısı da yaklaşık olarak şu şekilde yapılır:
        copy_if(begin(texts), end(texts), front_inserter(result), tuv_{threshold});
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include "csd/utility.hpp"

int main()
{
    using namespace std;
    using org::csystem::util::random::randomString;
    using org::csystem::util::random::randomInt;

    vector<string> texts;
    list<string> result;

    int count, threshold;

    cout << "Input threshold and count:";
    cout.flush();
    cin >> threshold >> count;

    generate_n(back_inserter(texts), count, []{return randomString(randomInt(5, 10));});

    auto f = [](const auto &s) {cout << s << ' ';};

    for_each(begin(texts), end(texts), f);
    cout << '\n';

    copy_if(begin(texts), end(texts), front_inserter(result), [threshold](const auto &s) {return s.length() > threshold;});

    for_each(begin(result), end(result), f);
    cout << '\n';

    return 0;
}

