/*----------------------------------------------------------------------------------------------------------------------
    Bir kesri temsil eden Fraction isimli sınıfı aşağıdaki açıklamalara göre yazınız.
    Açıklamalar:
    + Sınıf Matematikteki  bir kesri temsil ettiğinden pay ve payda değerleri tutulacaktır

    - Sınıfın ilgili set ve get fonksiyonları yazılacaktır

    + Pay'ın sıfırdan farklı, paydanın sıfır olması durumunda tanımsızlığa ilişkin bir mesaj verilecektir, pay ve paydanın
    her ikisinin birden sıfır olması durumunda std::invalid_argument nesnesiuygun mesaj ile fırlatılacaktır

    + Kesir her durumda sadeleşmiş bir biçimde tutulacaktır. Örneğin kesrin pay ve paydası sırasıyla 4 ve 18 olarak
    verildiğinde kesir 2 / 9 olarak tutulacaktır.

    + Kesir negatif ise işaret payda bulunacaktır. Örneğin kesrin pay ve paydası sırasıyla 3 ve -4 olarak verilmişse
    kesir -3 / 4 biçiminde tutulacaktır

    + Kesrin pay ve paydasının ikisinin birden negatif olması durumunda kesir pozitif olarak tutulacaktır

    + Kesrin payının sıfır olması durumunda payda ne olursa olsun 1(bir) yapılacaktır

    + Sınıf için yazılacak public bölüme ilişkin fonksiyonlar proje içerisinde Fraction.hpp dosyasında yazılmıştır

    - Sınıfın kesri 1(bir) artıran ve bir azaltan inc ve dec metotları yazılacaktır

    + Sınıfın public bölümünü değiştirmeden istediğiniz değişikliği ve eklemeleri yapabilirsiniz
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstring>

void csd_swap(int &r1, int &r2)
{
    auto temp{r1};

    r1 = r2;
    r2 = temp;
}

void csd_swap(double &r1, double &r2)
{
    auto temp{r1};

    r1 = r2;
    r2 = temp;
}

void csd_swap(void *p1, void *p2, std::size_t size)
{
    using std::memcpy;

    auto pc1{static_cast<unsigned char *>(p1)};
    auto pc2{static_cast<unsigned char *>(p2)};
    auto pt{new unsigned char[size]};

    memcpy(pt, pc1, size);
    memcpy(pc1, pc2, size);
    memcpy(pc2, pt, size);
}

int main()
{
    using namespace std;

    int a = 10;
    int b = 20;
    double x = 3.4;
    double y = 4.5;

    csd_swap(&a, &b, sizeof(int));
    csd_swap(&x, &y, sizeof(double ));

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "x = " << x << '\n';
    cout << "x = " << y << '\n';

    return 0;
}
