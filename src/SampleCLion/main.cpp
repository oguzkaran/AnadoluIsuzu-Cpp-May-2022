/*----------------------------------------------------------------------------------------------------------------------
    C++'d sınıfların"üye fonksiyonları (member function)" olabilir. Bu fonksiyonlar sınıf içerisinde veya sınıf dışında
    tanımlanabilir. Sınıf içerisinde tanımlanan fonksiyonlar inline tanımlanmış olur. Üye fonksiyonların sınıf dışında
    tanımlanması sınıf ve :: ile yapılır
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>

class Sensor {
    //...
public:
    void open(const char *url);
    void close()
    {
        //...
    }
};

void Sensor::open(const char *url)
{
    //...
}

int main()
{

	return 0;
}
