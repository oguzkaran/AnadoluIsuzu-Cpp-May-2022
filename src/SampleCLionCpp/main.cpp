/*----------------------------------------------------------------------------------------------------------------------
    Yukarıdaki problem türemiş sınıfın ilgili taban kısmına erişerek çözülebilir. Dikkat edilirse x için erişim ayrıca
    niteliklendirilmiştir. Base referansına ilk değer verme ise static_cast operatörü ile hangi Base kısmının alınacağı
    belirtilerek yapılmıştır
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>

class Base {
protected:
    int x{};
public:
    virtual void foo();
};

void Base::foo()
{
    std::cout << "Base::foo\n";
}

class A : public Base {
    void foo() override;
};

void A::foo()
{
    std::cout << "A::foo\n";
}

class B : public Base {
    void foo() override;
};

void B::foo()
{
    std::cout << "B::foo\n";
}

class C : public A, public B {
public:
    void bar(int a)
    {
        A::x = a;
        B::x = a * a;
    }
};



int main()
{
    using namespace std;

    C c;

    Base &r = static_cast<B &>(c);

    r.foo();

    return 0;
}
