/*----------------------------------------------------------------------------------------------------------------------
    Bir sınıfın static ve non-static veri elemanları olabilir. non-static veri elemanları her nesne için ayrıca yaratılır.
    Bu sebeple bu veri elemanlarına sınıf dışından referans, nesne veya pointer ile erişilebilir. Sınıfın static bir
    veri elemanı toplamda bir tanedir. Bu elemana sınıf dışından sınıf ismi ve :: (scope resolution operator) ile
    erişilebilir. Sınıfın static veri elemanları sınıf dışında tanımlanmalıdır. Sınıfın static bir veri elemanına erişim
    için bir nesne yaratılmış olması gerekmez. Sınıfın static veri elemanları static ömürlü nesnelerdir ve dolayısıyla
    tanımlamada değer verilmezse (initiliazation) türe özgü sıfır değerini (default value) alır.

    Bir sınıfın static ve non-static fonksiyonları olabilir. static fonksiyonlar sınıf bildirimi içerisinde static
    anahtar sözcüğü ile bildirilirler. static fonksiyon sınıf dışında tanımlanacaksa tanımlamada static anahtar sözcüğü
    yazılmaz. Yazılması durumunda error oluşur. static fonksiyon da istenirse sınıf içerisinde tanımlanabilir. Bu durumda
    yine inline olarak tanımlanmış olur. Sınıfın static fonksiyonlarına sınıf dışından sınıf ismi ve :: ile erişilir.
    Sınıfın non-static fonksiyonlarına sınıf dışından referans, nesne veya pointer ile erişilebilir.

    Sınıfın non-static fonksiyonları içerisinde sınıfın non-static veri elemanlarına doğrudan erişilebilir ve non-static
    fonksiyonları doğrudan çağrılabilir. Non-static fonksiyon içerisinde doğrudan kullanılan veri elemanı non-static
    fonksiyonun doğrudan ya da dolaylı olarak çağrıldığı nesnenin veri elemanı olur. Sınıfın non-static bir fonksiyonu
    içerisinde yine sınıfın non-static fonksiyonları doğrudan çağrılabilir. Bu durumda doğrudan çağrılan fonksiyon
    çağıran fonksiyona ilişkin nesne için çağrılmış olur. Sınıfın non-static bir fonksiyonu içerisinde static bir veri
    elemanına doğrudan erişilebilir, static bir fonksiyon doğrudan çağrılabilir.

    Anahtar Notlar: Aşağı seviyede non-static fonksiyon kavramı yoktur. Bu durumda non-static fonksiyonlara aşağı seviye
    ait oldukları sınıf türünden +1 tane adres parametresi geçirilir. Bu gizlice geçirilen adrese non-statici fonksiyonların
    tanımlanmasında ihtiyaç olabilir. İleride göreceğimiz "this pointer" ile bu gizli geçirilen adrese  fonksiyon içerisinde
    erişilebilir. Hatta bu durum fonksiyona "this geçirmek" olarak da söylenir. Sınıfın static fonksiyonlarına this
    geçirilmez

    Sınıfın static fonskiyonları içerisinde sınıfın non-static elemanlarına (veri elemanı veya fonksiyon) doğrudan
    erişilemez. Sınıfın static bir fonksiyonu içerisinde o sınıfın static veri elemanlarına doğrudan erişilebilir ve
    static fonksiyonları doğrudan çağrılabilir

    Anahtar Notlar: Bir sınıfı kullanan kodlara genel olarak "müşteri kodlar (client codes)" denir. Sınıfın kodlarına ise
    "hizmet veren kod (server code)" denir.

    Anahtar Notlar: Sınıfların organizasyonu genel olarak sınıf bildirimleri bir header dosyada, sınıfa ilişkin tanımlamalar
    bir .cpp dosyasında (implementation file) olacak şekilde yapılır ve müşteri kodlar sınıfın header dosyasını include
    ederek sınıf bildirimini derleme modülüne vermiş olur
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "Sensor.hpp"

int main()
{
    std::cout << "Number of open sensors:" << Sensor::count << '\n';

    Sensor s1{}, s2{};

    s1.set("weather sensor", "192.156.34.67", 50500);
    s2.set("Rain sensor", "192.156.35.67", 50501);
    s1.open();
    s2.open();

    std::cout << "Number of open sensors:" << Sensor::count << '\n';

    std::cout << s1.name << ", " << s1.host << ":" << s1.port << '\n';
    std::cout << s2.name << ", " << s2.host << ":" << s2.port << '\n';

    Sensor::resetCount();

    std::cout << "Number of open sensors:" << Sensor::count << '\n';

    return 0;
}