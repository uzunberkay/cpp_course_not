# CPP COURSE NOTE

===================
```cpp
	const int ival = 5;
	auto x = ival;
	/*
	* Auto tür çıkarımı, değişkenin türünü sağdaki ifadenin türüne göre belirler.
	* Burada constluk düşüyor. auto -> int geliyor.
	*/

int foo(int a); // int(int) ==> int(*)(int)



int main()
{
	auto fp = &foo;

}
```

==========================
```cpp
    double d[3]{};
```

	double(*
```cpp
	auto r = d;  // burada & olmadığı için array decay oluyor ve auto r 'nin tipi double* oluyor
```

	===
```cpp
	    double d[3]{};

	auto& r = d;  // burada & olduğu için r bir referans ve dizinin kendisi oluyor.
	// r'nin türü double(&)[3] oluyor.
```

	===========================
```cpp
	auto r = foo;  // Burada function pointer'a decay oluyor. int(*r)(int) oluyor.
	auto& r2 = foo; // Burada ise function reference oluyor. int(&r2)(int) oluyor.
```

	===========================
```cpp
6. Ders --------------------------------
```

move semantics
---

perfect forwarding
R value reference
```cpp
Myclass& r = obj; // l value reference
Myclass&& r2 = Myclass(); // r value reference
auto && ur = Myclass();  Universal reference


    int x = 23;
    int&& r = x;
```

	geçersiz. Çünkü r value referansa sadece r value atanabilir. L value atanamaz.
```cpp
	int&& r2 = 23; // geçerli. Çünkü 23 bir r value'dur.
```

	Dikkat!
	bir değişkeninn data type'ı ile
	o değişkenin oluşturduğu ifadenin
	value categorisi
	farklı kavramlardır.
	değişken isimlerinin oluşturduğu ifadeler her zaman l value exp.
```cpp
	// fonksiyon çağrı ifadelerinin value kategorileri

int foo();

int main()
{
```

	foo() // ifadesinin value cat. PR value
```cpp
}

// fonksiyon çağrı ifadelerinin value kategorileri

int foo();
int& bar();

int main()
{
	foo(); // ifadesinin value cat. PR value
	bar(); // ifadesinin value cat. L value
}
```

Buradaki ayıran şey referans döndüren fonksiyonun çağrısı olmasıdır.
==
```cpp
#include <iostream>


class Myclass {};
Myclass foo();
Myclass& bar();
Myclass&& baz();

int main()
{
	foo(); // ifadesini value cat. PR value
	bar(); // ifadesini lvalue cat. L lvalue
	baz(); // ifadesini xvalue cat. X value

}
```

Fonksiyonların varsayılan argüman alması
default arguments
```cpp
#include <iostream>


void foo(int x, int y);


int main()
{

	foo(1, 2);
	// call parameter

}

nden böyle bir araç var =
```

bunu kullanmanın çalışma zamanına ilave bir maliyeti var mı ?  yok.
```cpp
foo(x,y);
foo(x,y,0);





#include <iostream>



int foo(int x = 1 , int y = 2, int z = 3)
{
	std::cout << x << " " << y << " " << z << std::endl;
	return 0;
}


int main()
{
	foo(20,40, 60);
	foo(20, 40);

}
```

20 40 60
20 40 3
```cpp
foo();  = 1 , 2, 3

foo(1,,4) ;  bu kesinlikle olmaz.

#include <iostream>


int g = 56;
int foo(int* =&g);


int main()
{
	foo();
	int x = 23;
	foo(&x);

}

int foo(int* p)
{
	std::cout << *p << std::endl;
	return 0;
}


foo(); // 56
foo(&x); // 23 çıktısını veriyor.


int foo(int = 0 , int = 0);
int bar(int = foo());
int baz(int = bar());
```

Böyle kullanabiliyorum.
```cpp
#include <iostream>

int g = 56;

void foo(int = ++g);


int main()
{

	foo();
	foo();
	foo();


}

void foo(int x )
{
	std::cout << x << std::endl;
}
```

57
58
59
```cpp
// eren.h
void foo(int, int, int = 0);


// necati.c
// #include "eren.h"

void foo(int, int = 0, int);


// Kümülatif olarak birleşiyor.
```

type conversion (tür dönüşümü)
=================================
```cpp
implicit conversion  -> örtülü tür dönüşümü
explicit conversion  -> açık tür dönüşümü
```

type cast
(target-type)
(int)dval
(double)ival
(char*)&ival
```cpp
1) static_cast<target-type>(expression)
```

	const_cast
```cpp
		const T* ==> T*

				reinterpret_cast
```

dynamic_cast
standard - conversions
---

```cpp
int ==> double
enum ==> int
int* ==> void*
```

user -defined conversions
---

Dilde olmayan tür dönüşümleri ama kullanıcı tanımlı tür dönüşümleri
```cpp
#include <iostream>


struct Nec {
	int x, y, z;
	Nec(int);
	operator int()const;
};

int main()
{

	Nec mynec{};
	int x = mynec;
	mynec = 3;



}
```

=========================================================================================
```cpp
	/*
	*  Static cast örneği
	* Static_cast ile tür dönüşümü yapılır.
	* double ->int
	* int -> double gibi.
	*/
	double dval{ 1.23 };
	int ival{ static_cast<int>(dval) };

	/*
	* const_cast örneği
	* const_cast ile const - nonconst  ve
	* nonconst const dönüşümleri yapılır.
```

---

```cpp
	*/
	const int* cptr{ &ival };
	int* iptr{ const_cast<int*>(cptr) };

	/*
	*	reinterpret_cast örneği
	*	reinterpret_cast ile farklı addres türlerinde dönüşümler yapılır
	*  const int* -> int* gibi.
	*	const double* -> double*
	*/
	int* nptr = nullptr;
	double* pdval{ reinterpret_cast<double*>(nptr) };

	/*
	* örneğin double* -> int e çevirmek için önce int* e ardından
	* int e çevirmek gerekiyor.
	*/

	int sval{ reinterpret_cast<int>(reinterpret_cast<int*>(pdval)) };


	std::cout << sval;  // çıktı 0 çünkü nptr nullptr nullptr inte dönüşünce 0 olur




	int i1 = 5, i2 = 3;
	(double)i1 / i2;  //  c de böyle

	static_cast<double>(i1) / i2; // c++ ta böyle


		// const cast  const T*  ====> T*

	int x = 10;
	const int* ptr = &x;
	std::cout << *ptr << std::endl;
	int* p = const_cast<int*>(ptr);
	*p = 20;
	std::cout << *ptr << std::endl;
```

char *   unsigned char *  ==>  signed char *  dönüşebiliyo
unsigned int* == > int* dönüşebiliyo
```cpp
	int x = 10;
	char* p = reinterpret_cast<char*>(&x);
```

(target type)
```cpp
static_cast<double>(x)  ; // x i T türünden double a çeviriyor.

T herhangi bir tür  olmak üzere;
const T*  ==> T* dönüşümü const cast ile yapılır.
const char * x = &a;
char* p = const_cast<char*>(x);
++*p;
```

!!! FARKLI IKI ADDRES TURU ARASINDAKI DONUSUMLERDE REINTERPRET CAST KULLANILIR.
Myclass *
char  *
BİR DONUSUM OPERATORU KULLANARAK 2 DONUSUM YAPAMAZSIN.
char*
```cpp
const Myclass mx ;

reinterpret_cast<char*>(const_cast<Myclass*>(&mx));

const
constexpr C++ 11
//consteval C++ 20
```

Constant expression
variables
functions
Const bir ifadenin oluşturduğu ifade bir constant expression mıdır?
A evet
B hayır
C hiçbiri
Cevap C hiçbiri.
Aşağıda iki örnek var.
```cpp
int foo();

int main()
{

	// const cast  const T*  ====> T*

	const int x = foo();

	int ar[x]{};


}
```

Burada hata veriyor.
```cpp
	const int x = 5;

	int ar[x]{};
```

	burada hata yok.
```cpp
	const int x = 10;
	const int y = 20;
	const int z = x + y * 3;

	int a[z]{};
```

	X ve y sabit olduğu için z  bir constant expression oluyor.
```cpp
	Eğer bir değileni constexpr anahtar sözcüüğü (specifier) ile tanımlarsak.
```

a) const bir değişken oluşturmuş oluruz.
```cpp
b) constexpr bir tür değildir.
Örneğin constexpr int diye bir tür yoktur.
```

Constexpr ile tanımlanan değişkenin türü cons T dir. (T bir tür olmak üzere.)
```cpp
		(constexpr int y = 10;  // Y nin türü const int ' dir.)
int foo();

int main()
{

	// const cast  const T*  ====> T*

	const int x = 10;
	const int y = foo();

const iken böyle tanımlayabiliyorum. Yani foo çağrısı ile y nin değeri belirleniyor.
```

fakat foo değeri bir const ifade değil.
```cpp
constexpr int y = foo();
```

Fakat böyle tanımladığımda hata veriyor. Çünkü foo bir const expr değil.
Bildirim geçersiz olacak.
Constexpr ile tanımlanan değişkenin bir const expr olmasını garanti altına alıyor.
```cpp
constexpr int x = 10;   bu geçerli.  const int türü. Fakat artı olarak ilk değer veren ifadenin
const expr olmasını da garanti altına alıyor.


ÖRneğin constexpr int diye bir tür yoktur.

bir constexpr değişken örtülü olarak 'inline' değişkendir. // Şimdilik ilgilenmiyoruz.
```

Bir başlık dosyasında tanımlanması ODR'ı çiğnemez.
```cpp
ODR (One Definition Rule)




constexpr olan bir fonksiyon constexpr olmayan bir fonksiyona göre ne fark ediyor ?



int square(int x) {
	return x * x;
}
constexpr int cube(int x)
{
	return x * x * x;
}
```

Constexpr olmayan bir fonksiyonu
```cpp
	int i = 5;
	int ar[square(i)];
	bu şekilde yani constexpr olması gereken yerde kullanamayız.

		const int i = 5;
	int arr1[cube(i)];
```

	bu şekilde kullanabiliyorum.
	Bir constexpt fonksiyon
	a) belirli koşullar sağlandığında geri dönüş değeri derleme zamanında elde edilecek bir fonksiyondur.
```cpp
	b) eğer bir constexpr fonksiyona yapılan çağrıda fonksiyona gönderilen argümanlar
```

		- sabit ifadesi olabilir
		- sabit ifadesi olmayabilir.
	sama sabit ifadesi ise fonksiyonun geri dönüş değeri
	eğer fonksiyon çağrı ifadesi sabit ifadesi gereken bağlamda kullanılmış ise
	- derleme zamanında elde edilebilir.
```cpp
!!! constexpr C++ 11 ile gelmişti.



```

---

```cpp
#include <iostream>																			|
```

																							|
```cpp
constexpr int factorial(int n)																|
{																							|
	return n < 2 ? 1 : n * factorial(n - 1);												|
}																							|
constexpr bool is_prime(int x)																|
{																							|
	if (x < 2) return false;																|
	if (x % 2 == 0) return x == 2;															|
	if (x % 3 == 0) return x == 3;															|
	if (x % 5 == 0) return x == 5;															|
```

																							|
```cpp
	for (int i = 7; i * i <= x; i += 2)														|
	{																						|
		if (x % i == 0) return false;														|
	}																						|
	return true;																			|
}																							|
int main()																					|
{																							|
```

																							|
```cpp
	constexpr bool b = is_prime(31);														|
	std::cout << "19001 is prime: " << std::boolalpha << b << '\n';							|
}																							|
-------------------------------------------------------------------------------------------	|


C++ 11 ile geldi.

enum types

unscoped enums (modern C++ öncesi vardı halen var)
scoped enums (C++ 11)


enum Color{



};

enum class Color
{


};

enum class is not a class
enum class is "scoped enums"


/*
* Complete type (tamamlanmış - eksi olmayan)
* incomplete type (tamamlanmamış - eksik - )
*/

struct Nec;  // incomplete type

struct Nec
{
	int x, y;   // complete type
};


struct Nec;
typedef Nec Erg;
Nec foo(Nec);
Nec* bar(Nec*);


int main()
{


	Nec* p1 = nullptr;
	Nec* p2 = bar(p1);


}
```

Eğer incompletype
işinizi görüyorsa
```cpp
// forward declaration
struct Nec;


// forward declaration
struct Nec;


int main()
{

	/*
	*  Eğer struct ile tanımlazsam ptr ' yi .
	* Derleyici Nec ismini arayacak ve bulamayacak.
	* 2 seçenek var ya yukarıdaki gibi struct Nec; forward declaration yapacağım ,
	* ya da  struct Nec* ptr olarak tanımlayacağım.
	*/
	struct Nec* ptr = nullptr;


Forwarding declarationun büyük 3 günahı xd --
```

1) underlying type derleyeciye bağlı taşınabilirlik
```cpp
forward declaration yeterli olmuyor.
```

2) enum türlerinden aritmetik türlere
örtülü dönüşüm olması
3) enumaratorlerin scope (kapsam)
ona sahip olan enum türünün kapsamı ile
```cpp
enum Nec{x,y,z};
enum Erg{a,b,c};
```

böyle problem yok.
---

```cpp
enum Nec{x,y,z};
enum Erg{a,b,x}; ama böyle tanımlayamıyoruz.
('x': yeniden tanımlama; önceki tanım 'numaralandırıcı' idi).


enum class Color{White,Yellow,Red,Brown,Brown,Blue,Black};
```

Eğer böyle tanımlarsak
```cpp
Color::Yellow; kullanabiliyoruz ve birden fazla aynı isimde enumarator kullanabiliriz.

auto sc = Color::White;

	using enum Color;
	auto sc = Color::White;
	auto sc2 = Brown;
```

	nitelenmemiş isim kullanabiliyorum.
```cpp
using enum Color;

using Color::Red;

auto
```

decltype
declaration type
Bir türün (type) kullanıldığı
tüm bağlamlarda
decltype specifier ile oluışturulan bir tür kullanılabilir.
decltype ile oluşturulan yapı
	hangi tür anlamına gelecek
1) operand olan ifadenimn bir isim formunda olması
```cpp
	decltype(x)
	decltype(m.x)
	decltype(p->a)
	decltype(x)
```

2) operand olan ifadenmin bir isim formunda olmaması
```cpp
	decltype(x+ 5);
	decltype(+i);
	decltype(a*b);
	decltype(foo());
```

	decltype((x))
---

```cpp
	int x = 5;
	decltype(x) y = 10;  // y -> int

	const int x = 5;
	decltype(x) y = 10;  // y -> const int  ! ! ! CONST INT TURDUR.

	int x = 5;
	int& r1 = x;
	int&& r2 = 96;

	decltype(r1) a{ x };  // a --> int&

	decltype(r2) a{ 23 };  // a --> int&&

	=========================== BURADA KALDIM ===========================
	decltype(expr)
```

	diklkat!
	decltype operandı eğer bir isim formunda olmayan bir ifade ise
	decltype ile elde edilen türü ne olduğu
	operandı olan ifadenin "value category"
	Pr value	T
	L value		T&
	X value		T&&
```cpp
	int x = 5;
	decltype(x + 3);  // x+3 'ün value cat. pr oldugu için int

	int x = 5;
	int* ptr = &x;

	decltype(*ptr) // L value oldugu için.  int&;

	int ar[20]{};
```

	decltype(ar[47])  int&  lvalue oldugu için
```cpp
------------------------------	8.ders ------------------------------
	int x = 10;

	int* ptr = &x;
	decltype(*ptr);  // int&


	//decltype(x);	// int
	//decltype((x)); // int&
```

	FUNCTION OVERLOADING
---

Fonksiyonların yüklenmesi
1) birden fazla fonksiyonun ismi aynı olacak
2) aynı isimli fonksiyonlar aynı scope'ta (kapsamda) olacak.
3) Aynı isimli fonksiyonların imzaları (signature) farklı olacak.
	fonkisyonun geri dönüş türü haricindeki parametrik yapısı
```cpp
	int foo(int,int);
	double bar(int,int);

int foo(int);




int main()
{
	int foo(int, int);

}
```

Burada function overloadinng var mı ?
Cevap : Hayır. Bu iki fonksiyonun kapsamları farklı.
```cpp
int foo(int);
int foo(int);
```

İki fonkun da imzası aynıysa bu geçerlidir fakat function overloading değildir.
Bu duruma function redeclaration denir. (fonksiyonu yeniden belirtme)
```cpp
// redeclaration

int foo(int);
int foo(int);

// geçersiz kod olur. İmza aynı dönüş farklı

int foo(int);
double foo(int);

typedef int Mint;

void foo(int);
void foo(Mint);
```

FO mu ? Hayır redeclaration.
```cpp
void foo(int);
void foo(const int);
```

Bu da redeclaration.
```cpp
void f(char);
void f(signed char);
void f(unsigned char);
3 adet function overload var .   char -> signed char -> unsigned char farklı türler.


void fo(int);
void fo(int,int = 0); F.O var.


void fo(int* p );
void fo(int p[10]);
void fo(int p[]);
```

Burası da redeclaration.
---

```cpp
void foo(int(*p)[10]);
void foo(int(*p)[11]);
void foo(int(*p)[12]);
```

3 adet FO var. Dizilere pointer oldugu için hepsinin addresi yani imzası farklı. FO oluyor.
```cpp
int foo(int);
int foo(int*);
int foo(int&);
int foo(int&&);
```

4 farklı FO var.
```cpp
// const overloading
void foo(int*);
void foo(const int*);

void foo(int(int));
void foo(int(*)(int));  FO yok. redeclaration.
```

Funciton typden functin pointer type decay oluyo.
-
function overload resolution
===================================
	- no match
	- ambiguity
a) derleme zamanında   (static binding - early binding)
b) çalışma zamanında.  (dynamic binding - late binding)
FUNCTION OVERLOAD RESOLTION
candiadate func.
	viable function
	Eğer bir tane viable fonk. varsa FOR (Function overload res.) bitti.
	Hiç yoksa no match olacak.
Peki Neco ?
ya birden fazla viable func. varsa
	best match
	best viable
	Argümandan parametreye yapılan dönüşümü derecelendiriyor.
	variadic conversion		en kötüsü
		user-defined conversion
			standart conversion
```cpp
int => double
double => int
int* ==> void*
(unscoped) enum ===> int
```

Bunlar standart conversion.
```cpp
class Nec
{
public:
	operator int()const;

};


int main()
{
	Nec mynec;
	int ival{};
	ival = mynec;

```

---

Normalde Nec'ten int e dönüşüm yok. standart olarak. fakat ,
```cpp
operator int()const; bu tanımla dönüşüm yapmama olanak sağlıyo.
```

Buna da 'user-defined conversion' deniyor.
---

conversion constructor
```cpp
type-cast operator function
```

peki Necati
ya birden fazla viable funciyon için
dçnüşümler std conv. ise ??????
a) exact match (tam uyum)
	T* => const T*
	array decay ile
	function decay ile
b) promotion
	integral promotion
```cpp
	float => double
```

	m
c) conversion
```cpp
void foo(int);
void foo(int&);


int main()
{
	int x = 4;
	foo(x);

}
```

Ambiguiti.
```cpp
void foo(int*)
{
	std::cout << "foo(int*)" << '\n';
}
void foo(const int*)
{
	std::cout << "foo(const int*)\n";
}


int main()
{
	int x = 19;
	foo(&x);

}
```

Bu ambiguiti değil. foo(int*) çalışıyor.
```cpp
void foo(int&);  // l value ref
void foo(int&&); // r value ref

void foo(int&)
{
	std::cout << "int&\n";
}
void foo(int&&)
{

	std::cout << "int&&\n";
}
int&
int&&  çıktılar.


void foo(const int&)
{
	std::cout << "int&\n";
}
void foo(int&&)
{

	std::cout << "int&&\n";
}
```

Böyle olsaydı da r ref i seçecekti. Hani const& a r val bağlanıyo ya normalde. Bu durumda da bağlanıyor ama
&& daha iyi bir ihtimal.
```cpp
class Myclass{};

void foo(Myclass&)		// non const l value ref
{
	std::cout << "Myclass&\n";
}
void foo(const Myclass&)	// const l value ref
{
	std::cout << "const Myclass&\n";
}
void foo(Myclass&&)		// R value ref
{
	std::cout << "Myclass&&\n";
}


	Myclass x;
	const Myclass y;
	foo(x);
	foo(y);
	foo(std::move(x));
```

	Çıktı :
	Myclass&
```cpp
	const Myclass&
```

	Myclass&&
```cpp
void foo(int)
{
	std::cout << "int\n";
}
void foo(int&)
{
	std::cout << "int&\n";
}


int main()
{
	foo(12);
	int x{};

	foo(x);  // ambiguity


}
```

bir overload seçilebilmesi için
(ambiguity olmaması için)
en az bir parametrede diğerlerine üstünlük sağlamalı
diğer parametrelerde diğer overloadlardan daha kötü olmayacak.
```cpp
auto&& için çıkarım kuralları

auto&& x = 10; // int&& x = 10;

C++ dilinde refrence to reference yoktur.
```

ancak öyle bağlamlar var ki
reference to reference
reference collapsing
T& &	T&
T& &&	T&
T&& &	T&
T&& &&  T&&
```cpp
	int y = 22;
	auto&& x = y; // int& x = y;


C++ dilinde type alias declaration

	// typedef int Word;
	using Word = int;

	typedef  int inta10[10];
	// b using inta10 = int[10];


	typedef int& iref;
	typedef int&& irefref;


```

## Siniflar-

```cpp
class Data {
	// class members
};
// data members
//		non-static data members
//		static data members
// member functions
// member types / type members / nested type


/*
* free function
* global func
* stand-alone func.
*/
void foo();

class Data {
	void foo(int);  // non-static member function
	static void bar(); // statiic member function
};
```

Dikkat!
```cpp
C++ dilinde C'de olmayan
```

ayrı bir kapsam kategorisi vardır
scope categories in C
file scope
block scope
funcyion prototype scope
function scope
```cpp
scope categories in C++
namespace scope
```

block scope
funcyion prototype scope
function scope
```cpp
class scope


class scope'taki isimler
```

	ancak
	aşağıdaki operatörlerin sağ operandı  olarak kullanıldıklarında
	name-lookup ile class definition içinde aranırlar.
	x.a  member selection dot op.nün sağ operandı olan a ismi
```cpp
	ptr->b member selection arrowop.nün sağ operandı olan a ismi
```

	:: (scope resolution operator)  Myclass::c
Kod derlenirken derleyici :
name lookup
	context control
		access control  (erişim kontrolü public , private vs.)
public
protected
private
OOP
superclass		sub class
parentclass		child class
baseclass		derived class
```cpp
class Myclass {
public:
	void foo();
	void foo(int);
	void foo(double);
};


void Myclass::foo()
{
	std::cout << "Myclass::foo()\n";
}

void Myclass::foo(int)
{
	std::cout << "Myclass::foo(int)\n";
}

void Myclass::foo(double)
{
	std::cout << "Myclass::foo(double)\n";
}
int main()
{
	Myclass m;
	m.foo();
	m.foo(1);
	m.foo(1.2);




}
```

Çıktı :
Myclass::foo()
Myclass::foo(int)
Myclass::foo(double)
```cpp
class Myclass {

	// classın içinde tanımlanması inline function
	void foo()
	{

	}
};

class Date {
public:
	void set(int d, int m, int y)  // non const member function
	{
		md = d;
		mm = m;
		my = y;
	}
	void print()const;  // const member function
	int get_month()const
	{
		return mm;
	}

private:
	int md, mm, my;
}

	void set(/*Date* /int d, int m, int y)
	{
		md = d;
		mm = m;
		my = y;
	}
	void print(/*const Date*/)const;  // const member function
```

	gibi düşün.
1) const bir üye fonksiyon içinde sınıfın
non-static veri elemanlarını değiştirmeye yönelik kodlar geçersizdir.
2) const bir sınıf nesnesi için sınıfın non-const üye fonksiyonlarına çağrı yapmak geçersizdir.
