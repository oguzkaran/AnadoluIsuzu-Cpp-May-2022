/*----------------------------------------------------------------------------------------------------------------------
	Overload resolution işlemi 3 aşamada yürütülür. Önce aday fonksiyonlar (candidate functions) bulunur. Aynı faaliyet
	alanı içerisinde bulunan aynı isimli tüm fonksiyonlar aday fonksiyonlardır. Sonra aday fonksiyonların arasından
	uygun (viable) fonksiyonlar seçilir. Her argümandan parametreye otomatik (implicit) tür dönüşümünün mümkün olduğu
	fonksiyonlar uygun fonksiyonlardır. Uygun fonksiyonlar içerisinden en uygun (the most viable) fonksiyon seçilir. En 
	fonksiyon "tüm argüman parametre dönüşümleri" dikkate alındığında diğerlerinden daha iyi dönüştürme sunan ya da
	daha kötü dönüştürme sunmayan fonksiyondur. Böyle tek bir tane fonksiyon varsa o seçilir yoksa error oluşur	
	Dönüşümler aşağıdaki gibi kalitelere ayrılabilir:
	1. Variadic dönüşümler: Kalitesi en düşük olan dönüşümdür.

	2. Programcının tanımladığı dönüşümler: Bu dönüşüm variadic dönüşüm kalitesine göre daha iyidir. C++'da normalde 
	geçerli olmayan tür dönüşümleri bazı fonksiyonların tanımlanması ile geçerli hale gelir. Derleyici bu durumda 
	tanımlanan fonksiyonları çağırarak dönüşümü gerçekleştirir. Bu dönüşümü mümkün kılan fonksiyonlar şunlardır:
	- conversion constructor
	- type-cast operator functions
	Bu fonksiyonlar ileride ele alınacaktır.

	3. Standart Dönüşümler: Bu dönüşümler dilin kurallarına göre implicit olarak yapılabilen dönüşümlerdir. Bu 
	dönüşümün kalitesi programcının tanımladığı dönüşümlerin kalitesinden daha yüksektir. Standart dönüşümler 3(üç)
	ketegoriye ayrılır:
	- Tam uyum (exact match): Argümanın türü ile aktarılacağı parametrenin türü tamamen aynı ise  tam uyum vardır.
	Ancak aşağıdaki durumlar da tam uyum olarak ele alınır:
		- Argüman olan nesne bir sol taraf değeri yani bir nesne ise, parametre değişkenin kopyalanacak değerin bu 
		nesneden alınması. Bu duruma sol taraf değerinden sağ taraf değerine dönüşüm denir
		
		- Fonksiyonun parametre değişkeninin bir "pointer" olması ve fonksiyonun da aynı türden bir dizi ismi
		ile çağrılması

		- Parametre değişkenin bir "function pointer" olması ve fonksiyonun aynı türden bir fonksiyon ismi ile 
		çağrılması.

		- Fonksiyon parametre değişkeninin, "pointer to const" olması ve fonksiyon aynı türden const olmayan bir
		adres ile çağrılması (const qualification conversion)

	- Yükseltme (promotion): Yükseltme aşağıdaki durumları kapsar
		- char, signed char, unsigned char, bool, short, unsigned short türlerinden int türüne yapılan dönüşüm (integral/integer promotion)
		- float türünden double türüne yapılan dönüşüm
		- Bir enum türünden enum türünün ilişkin olduğu tamsayı türüne (underlying type) yapılan dönüşüm.
		- float ve double türlerinden long double türüne yapılan dönüşüm yükseltme dönüşümü değildir

	- Diğer dönüşümler (conversion):
		- Dilin kurallarına göre implicit olarak yapılabilen dönüşümler. Buna göre 5(beş) grup dönüşüm söz konusudur:
			1. Tamsayı türlerine ilişkin dönüşümler. Bir tamsayı türünden veya bir enum türünden başka bir tamsayı 
			türüne yapılan dönüşümler
			2. Gerçek sayı dönüşümleri: Bir gerçek sayı türünden başka bir gerçek sayı türüne yapılan dönüşümler
			3. Gerçek sayı türleri ile tamsayı türleri arasındaki dönüşümler
			4. Adres türlerine ilişkin dönüşümler: Sıfır tamsayı sabitinin herhangi bir türden pointer'a kopyalanması
			için nullptr sabitine dönüştürülmesi. void olmayan bir adresin void bir adrese dönüştürülmesi
			5. bool türüne yapılan dönüşümler: Herhangi bir tamsayı, gerçek sayı, enum veya adres türünden bool
			türüne yapılan dönüşümler
	Kurallara göre tam uyum, yükseltmeden, yükseltme de diğer dönüşümlerden daha kalitelidir

	C++11 ile eklenen sağ taraf (rvalue) referansları için overload ve overload resolution kuralları ayrıca tanımlanmıştır:
	cons T & parametreli ve T && parametreli aynı isimde iki fonksiyon tanımlanabilir. Eğer fonksiyon T türden bir sağ taraf 
	değeri ile çağrılırssa T && parametreli fonksiyon kaliteli kabul edilir. Fonksiyon T türünden bir sol taraf değeri
	ile çağrılırsa const T & parametreli fonksiyon kaliteli kabul edilir.

	Overload edilen fonksiyonların birden fazla 
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>

void foo(int a) = delete;
void foo(double a)
{
	std::cout << a << '\n';
}

int main()
{
	double a = 10;

	foo(10);
	foo(a);	
	foo(10L);
	
	return 0;
}


