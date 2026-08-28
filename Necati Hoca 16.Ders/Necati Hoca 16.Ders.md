# 16. DERS

===============
move - only
```cpp
class Myclass
{
	public:
		Myclass(Myclass&&);
		Myclass& operator=(Myclass&&);
}
```

veya
```cpp
class Myclass
{
	public:
		Myclass(const Myclass&) = delete;
		Myclass& operator=(const Myclass&) = delete;
		Myclass(Myclass&&);
		Myclass& operator=(Myclass&&);
}
```

Conversion Ctor
	Dönüştüren kurucu işlev.
```cpp
explicit ctor.
```

copy elision
mandatory copy elision
temporary materialization
delegating ctor
Prvalue class objects
CONVERSION CTOR
	Tipik olarak tek parametreli
		sınıf türünden olmayan bir ifadeyi
			bir geçici nesne olustururaak (PR value)
				sınıf türüne dönüştüren bir fonksiyon.
================
```cpp
class Myclass {
public:
	Myclass() = default;
	Myclass(int x) :mx(x) {
		std::cout << "Myclass(int x)  = " << x << '\n';
		std::cout << "This = " << this << '\n';
	}
	Myclass& operator=(const Myclass& other) {
		std::cout << "Myclass::operator=(const Myclass&)\n";
		std::cout << "&other = " << &other << '\n';
		mx = other.mx;
		return *this;

	}


private:
	int mx;
};

int main()
{
	Myclass m;
	m = 12;


}
```

Burada geçici bir nesne olusutuyor 12 için.
```cpp
Aslında  m = Myclass(12) ; gibi.
```

Yani asşında (int x ) 'li ctor çalışıyor. Ardından copy assig. çalışıyor.
Myclass(int x)  = 12
```cpp
This = 00000040FED3F884
Myclass::operator=(const Myclass&)
&other = 00000040FED3F884
```

Çoğunlukla istenmez.
=============================
temporary objects
=========
```cpp
Myclass m ;

Myclass foo();
```

Eğer bir sınıf türünden bir  nesneye ihtiyacımız varsa
```cpp
// C++17 standardına göre PR value olan sınıf ifadelleri
```

artık doğrudan bir nesne değil
temporary materialization
temporary materialization olusması zorunlu olan durumlar.
```cpp
Myclass m = Myclass(Myclass(Myclass()));
```

Bir fonksiyonun parametresi bir sınıf türündense ve fonksiyonu bir PR value
argüman ile çağırırsam burada kopyalama yapılmadan  derleyici PR exp.
doğrudan fonksiyonun parametre değişkenine olusturmak içn kullanıcak. Yani bu
PR value fonksiyonun parametre değişkenini init etmek için kullanılacak.
Sadece bir kere ctor çağıracak.
Dikkat otomatik ömürlü bir nesne
bir fonk.un return ifadesi oluursa
derleyici burada
L value to X value
dçnüşümü yapmak zorunda.
Bu ders silindi sistemden ? 2:0:0 da falan kalmıştım.
