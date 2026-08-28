# 23. Ders

---

```cpp
using declartion;  --> using std::cout;
using namespace directive  --> using namespace std;
```

ADL lookup
```cpp
-using declartion;-
```

1) hiç kullanmak
	2) dar kapsamlı kullanmak
```cpp
	namespace nec {
	void foo()
	{
		std::cout << "nec::foo called\n";
	}
}

namespace erg {
	using nec::foo;
}

namespace fer {
	using erg::foo;
}
int main()
{
	using std::cout;
```

nec::foo called
## Using Namespace Directive

```cpp
namespace nec {
	int x;
}
namespace erg {
	using namespace nec;
}

using namespace erg;
int main()
{
	erg::x = 456;
	std::cout << ::x;

```

---

ADL ARgument Dependent Lookup
(Argümana bağlı arama)
Koenig lookup
Andrew Koenig
bir fonksiyon çağrısı ifadesi
 nitelenmemiş bir isim ile yapılırsa
   söz konusu isim
	normal isim arama dışında
	  fonksiyona gönderilen argüman(lar)ın
	     ilişkin olduğu namespace'te de aranır.
```cpp
foo(expr);

namespace nec {
	int x;
	class data{};
	enum color{White , Yellow , Red , Brown,Blue,Black};
	void foo(int);
	void bar(data);
	void bom(color);
}

int main()
{
	nec::data x;
	bar(x);  // x'in türü nec namespace'ine ait data sınıfı
	// bar sınıfı o zaman nec namespace'inde de aranacak.
	bom(nec::Blue);  // aynı şekilde

	return 0;
}



namespace nec {
	class Data {};

	void foo(Data)
	{
		std::cout << "nec::foo called\n";
	}
}

void foo(nec::Data)
{
	std::cout << "::foo called\n";
}

int main()
{
	nec::Data d;
	foo(d);
	/*
	* ambiguity.
	* Sebep ?
	* foo yu ararken 2 namespace de ariyor.
```

---

```cpp
	*/

	return 0;
}


```

---

```cpp
	// burada adl var mi ? var xd
	std::cout << "hello world" << '\n';

		operator<<(std::cout, " hello world with operator<< ") << '\n';
```

---

```cpp
	std::vector<int> vec(100);
	sort(begin(vec), end(vec));
```

ADL'ye en güzel örneklerden
```cpp
normalde std::begin(vec) , std::end(vec) olması gerekirken ADL sayesinde
```

std namespace'inde arama yapılıyor.(vec sayesinde)
```cpp
Peki sort neden std::sort olarak çağrılmıyor ?
```

Çünkü begin ve end fonksiyonları ADL sayesinde çağrılabiliyor.
sort fonksiyonuda begin ve end fonksiyonlarını parametre aldığı için
ADL sayesinde sort fonksiyonu da std namespace'inde aranıyor.
---

```cpp
namespace nec {

	class Myclass
	{
	public:
		Myclass() = default;
		~Myclass() {
			std::cout << "Destructor\n";
		}
		friend void swap(Myclass&, Myclass&);

	private:
		int mx{};
	};

	void swap(Myclass& a, Myclass& b)
	{
		std::cout << "nec::Swap\n";
		int temp{ a.mx };
		a.mx = b.mx;
		b.mx = temp;

	}


}

int main()
{
	nec::Myclass obj1, obj2;

	std::swap(obj1, obj2);
	swap(obj1, obj2);
}

```

---

```cpp
UNNAMED NAMESPACE --- 1:45:00


namespace {
	className {
		//...
	};

	int x = 10;
}

className  sadece bu dosyada geçerli. internal linkage.
```

dışarı açılmasını istemiyorsak unnamed namespace içine koyarız.
```cpp
namespace nec {
	namespace {
		int x;
	}
}

int main()
{
	nec::x = 4;
}
```

içerideki unnamed namespacede derleyici kendisi isim verir.
xfsafs gibi sallıyorum.
```cpp
namespace nec {
	namespace xfsafs{
		int x;
	}
	using namespace xfsafs;
}
```

gibi bir tanım yaptığı için nec::x olarak erişilebiliyor.
inline namespace
anahtar kelimeler overload ediliyor aslında.
bir anahtar kelimenin birden fazla anlamı olabilir.
örneğin static.
---

```cpp
namespace nec {
	namespace erg {
		int x;
	}
}

int main()
{
	nec::erg::x = 5;
}
```

Normalde böyle erişiyoruz.
eğer ben direkt nec::x olarak erişmek istersem ne yaparım ?
```cpp
eski yöntem using namespace erg; nec içine yazılırdı.
namespace nec {
	namespace erg {
		int x;
	}
	using namespace erg;
}
```

bir de inline namespace var. eğer erg inline namespace ise
```cpp
namespace nec {
	inline namespace erg {
		int x;
	}
}
nec::x = 5; olarak erişilir.
```

ama neden inline namespace kullanılır ?
çünkü inline namespace ler versiyonlama için kullanılır.
```cpp
namespace nec {

	inline namespace ver1 {
		class Data{};
	}
	namespace ver2 {
		class Data {};
	}
}
```

Örneğin ver1 deki Data sınıfını kullansın isterseniz  inline yaparsınız.
Bir süre sonra ver2 yi kullanmak isterseniz inline ı kaldırırsınız. ve ver2yi
inline yaparsınız.
---

```cpp
namespace alias (takma ad)
```

isim alanı eş ismi
```cpp
namespace mylib_pro_gen {

	namespace progren_constant {
		constexpr int val = 1;
	}
}

{
	// normalde
	mylib_pro_gen::progren_constant::val; // şeklinde erişilir.
}

```

---

```cpp
	// namespace alias ile
	namespace constant = mylib_pro_gen::progren_constant;
	constant::val;
```

---
