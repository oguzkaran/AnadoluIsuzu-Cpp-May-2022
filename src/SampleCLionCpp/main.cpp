/*----------------------------------------------------------------------------------------------------------------------
    Bir referansın ve bir pointer'ın iki tane türü vardır: static, dynamic
    - static type: Referansın ya da göstericinin bildirildiği ya da tanımlandığı türdür. Değişmez. Derleme zamanına
    ilişkindir. Referansın ya da pointer'ın türü dendiğinde static tür anlaşılır.

    - dynamic type: Bir referansın ya da göstericinin içerisinde bulunan adrese ilişkin bellekte yaratılmış olan gerçek
    nesnenin türüdür. Değişebilir. Çalışma zamanına ilişkindir
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>

class A {
    //...
private:
    int m_x;
public:
    A(int x) : m_x{x}
    {}

    A(const A&r) : m_x{r.m_x}
    {
        std::cout << "Copy ctor of A\n";
    }

    A &operator=(const A &r)
    {
        m_x = r.m_x;
        std::cout << "Copy assignment operator function of A\n";

        return *this;
    }

    int x() const {return m_x;}
    void x(int value) {m_x = value;}
    //...
};


class B : public A {
private:
    int m_y;
public:
    B(int x, int y) : A{x}, m_y{y}
    {}
    B(const B&r) : A{r}, m_y{r.m_y}
    {
        std::cout << "Copy ctor of B\n";
    }

    B &operator=(const B &r)
    {
        x(r.x());
        m_y = r.m_y;
        std::cout << "Copy assignment operator function of B\n";

        return *this;
    }

    int y() const {return m_y;}
    void y(int value) {m_y = value;}
    //...
};

int main()
{
    using namespace std;

    B b{10, 20};

    A *p = &b;
    A &r = b;

    return 0;
}

