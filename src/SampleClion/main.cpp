/*----------------------------------------------------------------------------------------------------------------------
    Yukarıdaki üretici tüketici probleminin kuyruk kullanılarak çözümü
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <thread>
#include <chrono>
#include <semaphore>
#include <array>
#include "csd/utility.hpp"

constexpr std::size_t queue_size = 10;
std::array<std::size_t, queue_size> g_queue;
std::size_t g_head, g_tail;
std::counting_semaphore<queue_size> g_semProducer{queue_size}, g_semConsumer{0};

void producerThreadCallback(std::size_t n)
{
    using namespace std;
    using org::csystem::util::random::randomInt;
    size_t count{};

    for (;;) {
        g_semProducer.acquire();
        g_queue[g_tail++] = count;
        g_tail %= queue_size;
        g_semConsumer.release();
        ++count;
        this_thread::sleep_for(chrono::microseconds(randomInt(0, 300000)));
        if (count == 100)
            break;
    }
}

void consumerThreadCallback(std::size_t n)
{
    using namespace std;
    using org::csystem::util::random::randomInt;

    size_t val;

    for (;;) {
        g_semConsumer.acquire();
        val = g_queue[g_head++];
        g_head %= queue_size;
        g_semProducer.release();
        cout << val << ' ';
        cout.flush();

        this_thread::sleep_for(chrono::microseconds(randomInt(0, 300000)));
        if (val == 99)
            break;
    }

    cout << '\n';
}

int main()
{
    using namespace std;

    thread t1{producerThreadCallback, 10000};
    thread t2{consumerThreadCallback, 20000};

    t1.join();
    t2.join();

    return 0;
}

