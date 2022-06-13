/*----------------------------------------------------------------------------------------------------------------------
    Aşağıdaki örnekte sınıfın ctor'ları içerisinde veri elemanlarına değerler verilmiştir
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>

class Sample {
public:
    int a;
    int b;

    Sample();
    Sample(int x, int y);
};


Sample::Sample()
{
    std::cout << "I am a default ctor\n";
    a = b = 0;
}

Sample::Sample(int x, int y)
{
    std::cout << "I am a ctor with parameters: int, int\n";
    a = x;
    b = y;
}

int main()
{
    Sample s{};

    std::cout << "s.a = " << s.a << ", s.b = " << s.b << '\n';

    Sample k{10, 20};

    std::cout << "k.a = " << k.a << ", k.b = " << k.b << '\n';


    return 0;
}