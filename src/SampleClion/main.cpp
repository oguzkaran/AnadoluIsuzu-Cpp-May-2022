/*----------------------------------------------------------------------------------------------------------------------
    Mutex (mutual exclusion) bir kritik bölgeye yalnızca tek bir thread'in girebilmesini sağlayan senkronizasyon nesneleridir.
    Mutex, C++'da mutex sınıfı ile temsil edilir. mutex sınıfı mutex header'i içerisinde bildirilmiştir. mutex ile
    kritik bölge oluşturmak için ilgili thread'lerde kullanılabilecek bir mutex nesnesi yaratılır. kritik kod aşağıdaki
    biçimde senkronize edilebilir:
        g_mutex.lock();
        <kritik bölge>
        g_mnutex.unlock();
    lock fonksiyonu çağrıldığında (mutex için lock yapıldığında) kritik koda giren thread mutex'in sahipliğini devralır
    (got ownership of mutex)

    Aşağıdaki örneği inceleyiniz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include "csd/utility.hpp"

std::vector<int> g_values;
std::mutex g_mutex;

int main()
{
    using namespace std;
    using org::csystem::util::random::randomInt;

    auto f = [](size_t n) {
        for (size_t i{}; i < n; ++i) {
            g_mutex.lock();
            g_values.push_back(randomInt(0, 99));
            g_mutex.unlock();
        }
    };

    thread t1{f, 1000000};
    thread t2{f, 2000000};
    thread t3{f, 3000000};

    t1.join();
    t2.join();
    t3.join();

    cout << "Size = " << g_values.size() << '\n';

    return 0;
}

