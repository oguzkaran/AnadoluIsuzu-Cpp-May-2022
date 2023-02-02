/*----------------------------------------------------------------------------------------------------------------------
    Yazılımda test süreçleri ürün geliştirmenin önemli bir aşamasını oluşturmaktadır. Bazı yazılımlarda yazılımların
    herşeyiyle doğru olması kritik öneme sahip olabilir. Bazı yazılımların hata toleransı olabilir. Gerektiğinde
    sonradan düzeltilebilir,

    Eskiden yazılım geliştirmede test süreçleri lüks olarak değerlendiriliyordu. Bu nedenle yazlnızca büyük firmalar
    test bölümleri barındırıyorlardı. Ancak günümüzde yazılımda kalite (software quality) bilinci çok daha fazla artmış ve
    test süreçleri çok daha bilinir hale gelmiştir

    Yazılımda test süreçleri için çeşitli stratejiler kullanılabilmektedir. Ancak test işlemi en aşağı düzeyde
    programcının kendi yazdığı kodları test etmesi ile başlar. Buna "birim testi (nunit testing)" denir. Programcı genel
    olarak yazmış olduğu bir fonksiyonun doğru çalışıp çalışmadığını test eder (etmelidir). İşte bu durumda bu fonksiyon
    "birim" olarak düşünülür. Bir yazılımda aslında parçalar bir araya getirilir. Yani fonksiyonlar çağrılarak yazılım
    geliştirilir. Bu bir araya getirme işlemi sonucunda genellikle bu parçalar yeniden test edilir. Buna da
    "entegrasyon testi (integration testing)" denir. Yazılımın önemli parçalarına "modül" de denilmektedir. Modüller de
    ayrı ayrı test edilebilir. Buna da "modül tesi (module testing)" denir. Nihayet tüm ürün oluşturulur ve ürün bir
    bütün olarak test edilir. Genellikle bu testelere "kabul testleri (acceptance testing)" denir. Ürün bütün olarak
    önce kurumun test bölümleri tarafından test edilir. Genellikle bu testlere "alfa testi (alpha testing)" denir. Sonra
    ürün seçilmiş bazı son kullanıcılara dağıtılır ve gerçek hayat testine sokulur. Buna genellikle "beta tesi (beta testing)"
    denir.

    Birim testi konusunda pratikte genel olarak şu 3 yaklaşımdan biri uygulanır:
    - Hiç birim testi yapmamak: Bu durum yazılım geliştirmede tavsiye edilmese de bir takım özel durumlardan dolayı
    uygulanabilmektediri. Örneğin geliştirici ekibin azlığı, projenin deadline'ının kısa olması, rakip firmalardan önce
    ürünü çıkarma kaygısı vb. durumlarda karşılaşılabilmektedir.

    - Katı katıya birim testleri yapmak: Bu durumda neredeyse her fonksiyon test edilir. Fonksiyonun basit ya da karmaşık
    olması durumlarına bakılmaz. Bu durumda zaman kaybı oluşmaması için test ekiplerinin ayrı olması gerekebilir. Şüphesiz
    herhangi bir zaman sıkıntısı yoksa da uygulanabilir

    - Gereken fonksiyonlar için birim testleri yapmak: Aslında görünürde en ideal durum mbu olmaktadır. Görece basit olan
    fonksiyonlar test edilmez. Bu durumda hangi fonksiyonların test edileceğinin, hangilerinin test edilmesi gerekmediğinin
    belirlenmesi önemlidir. Bu da geliştiriciler ve yöneticiler açısından tecrübe gerektirebilir.

    Birim test kavramı (aslında genel olarak test kavramı) C ya da C++ standartlarıne ilişkin değildir. Dolayısıyla bir
    birimi test etmek için kullanılan araçlar "third party" olarak geliştirilir. Aslında bu araçların temel amacı birim
    testini programcı için mümkün olduğıunda otomatize etmektir. Bu araçlar her zaman yapılması gereken kodlamayı programcıya
    bırakmaz. Bu durumda programcı için önemli olan uygun test senaryolarını belirlemek ve yazmaktır. Bu senaryolar için
    çok genel durumlar söylenemez. Test edilecek birimin ne olduğuna göre senaryolar çeşitlilik gösterebilir. C ve C++ için
    bir çok birim testi aracı bulunmaktadır. Bu anlamda firmalar duruma göre bir ya da daha fazla birim testi aracı tercih
    edebilirler. Bazı firmalar kendi test araçlarını yazabilmektedirler
----------------------------------------------------------------------------------------------------------------------*/
//#define NDEBUG

#include <iostream>
#include <cstdlib>
#include "csd/utility.hpp"
#include "File.hpp"

int main()
{
    using namespace std;
    using org::csystem::io::file::File;

    File f;

    auto status{f.open("test.dat", "r")};

    if (!status) {
        cerr << "Can not open file!...\n";
        std::exit(EXIT_FAILURE);
    }

    int ch;

    while ((ch = f.read()) != EOF)
        cout << static_cast<char>(ch);

    cout << '\n';

    CSD_VERIFY(f.seekSet() == 0);

    while ((ch = f.read()) != EOF)
        cout << static_cast<char>(ch);

    cout << '\n';

    return 0;
}

