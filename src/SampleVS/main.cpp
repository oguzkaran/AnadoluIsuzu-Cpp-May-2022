/*----------------------------------------------------------------------------------------------------------------------
	Bir fonksiyonun geri dönüş değeri sağ taraf referansı olabilir. Bu durum özel bir anlam ifade etmektedir. Böyle 
	fonksiyon çağrıları xvalue kabul edilir. xvalue bu anlamda rvalue biçimindedir. Geri dönüş değeri sağ taraf
	referansı olan fonksiyonlar ileride daha detaylı olarak ele alınacaktır
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>

int&& foo()
{
	return 10;
}

int main()
{	
	int& r = foo(); //error
	int&& r = foo();//geçerli

	return 0;
}


