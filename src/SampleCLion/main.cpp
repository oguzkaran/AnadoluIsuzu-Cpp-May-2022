/*----------------------------------------------------------------------------------------------------------------------
    Operatör fonksiyonları (operator overloading): Sınıf nesnelerinin sanki temel türlermiş gibi birçok operatörle
    kullanılmasına olanak sağlayan mekanizmadır.

    Operatör fonksiyonları dile ilave bir işlevsellik kazandırmaz. Yalnızca okunabaililiği/algılanabilirliği artırır.
    Bir operatör fonksiyonu bazı istisnalar hariç "üye operatör fonskiyonu" veya "global operatör fonksiyonu" olarak
    yazılabilir. Operatör fonksiyonlarının geri dönüş değerleri herhangi bir türden olabilir ancak olması gereken uygun
    türleri vardır. Örneğin + operatör fonksiyonun ayı sınıf türünden bir nesneye dönmesi uygun olur. Benzer biçimde
    < operatörüne ilişkin operatör fonksiyonunun da bool türden bir değer geri dönemsi uygundur.

    Derleyici iki operandlı bir operatör sembolü ile karşılaşırsa şunları yapar:
    1. Önce operandların türlerine bakar
    2. Eğer operandlar temel türlerte ilişkinse (sınıf değilse) küçük tür büyük türe dönüştürlür ve işlemin sonucu büyük
    tür türünden çıkar (int türünden küük olan türler kendi aralarında işleme sokulursa sonuç int türden çıkar)
    3. Eğer operandlardan en az birisi bir sınıf türümndense derleyici bu işlemi yapabilecek bir operatör fonksiyonu
    araştırır. Böylece "candidate functions"'ları belirler.
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>

int main()
{


    return 0;
}

