# 13. ders

default ctor.
special member functions
default ctor
destructor
copy ctor
move ctor
copy assignment
move assignment
Diğerlerinden ayıran ne ?
Bazı koşullar sağlandığı zaman derleyici tarafından otomatik oluşturulurlar.
- derleyici bunların kodlarını yazabiliyor.
```cpp
implicitly declare ==> default
```

user declared
default ctor
move ctor
move assignment  olmayabiliyor.
	move ctor
	move assignment
Move members of a class (move ctor / move assignment)
copy members of a class (copy ctor / copy assignment)
constructor initializer list
member initializer list
T is a type
```cpp
class Myclass{

	T1 x;
	T2 y;
	T3 z;

};


class MyClass
{
public:
```

	MyClass() : x_(0), d_(3.4)
```cpp
	{

	}
private:
	int x_;
	double d_;

};
```

Böyle init edebiliyorum.
```cpp
int g{};
class MyClass
{
public:
	MyClass() :r{g}
	{

	}
private:
	int &r;
	double d_;

};


class Point {
	public:
		Point() : x_(0), y_(0) {}
		Point(double x, double y) : x_(x), y_(y) {}
private:
	double x_;
	double y_;
};


Burada  hayata geliş sırası 	int mx_;
	int my_; buradaki sıraya göre. Yani mx_ my_den önce init edilecek.
```

	Ve mx_ my_ kullanılarak init edildiği için my_ hayata gelmediği için hata vermez fakat
	UB (undefined behavior) oluşur.) çünkü my_ init edilmeden kullanılmış olur.
	my_ garbage değer alır.
```cpp
class Nec {
public:
	Nec(int x, int y) :my_(x), mx_(my_*x) {}
private:
	int mx_;
	int my_;
};


C-like C++
```

Dil cpp ama alışkanlık c.
```cpp
class MyClass
{
public:

/*
```

Burada  iki farklı yazılımcı var.
Birincisi initializer list kullanmış.
İkincisi ise constructor body içinde atama yapmış.
```cpp
İkincisi istemediğimiz bir yazılımcı yani C-like C++ yazılımcısı.

*/
```

	MyClass() : ax(exp1),bx(exp2)
```cpp
	{
	}
	MyClass()
	{
	// Öncelikle default init etmiş oluyosun. Ardından atama yapıyosun ???
		ax=exp1;
		bx=exp2;
	}

private:
	A ax;
	B bx;

};


class MyClass
{
public:
	Myclass() :mx(5) {}
private:
```

default member init.
```cpp
	int mx = 5;  böyle tanımlayınca derleyici ctoru default olarak yukarıdaki gibi tanımlar.
}


class MyClass
{
public:
	Myclass() :mx(5) {}
private:
```

default member init.
```cpp
	int mx{4} ; geçerli
	int mx = 4; geçerli
	int mx(4); geçersiz



	class Point {
public:
	Point() = default;  // derleyici default ctoru senin yazmanı istiyorum.
private:
	double mx{ .0 }, my{ .0 };

};


class Counter {

};

// zero-const abstraction

int main()
{
	Counter cnt;
}
```

RAII
Resource Acquisition Is Initialization (Kaynak edinimi ilk değer verme yoluyla olur)
special member functions
default ctor
destructor
move ctor
move assignment
copy ctor
copy assignment
Myclass(int) bu türden ctorlar user declared special member function değildir.
yani derleyici tarafından oluşturulamaz.
yani
```cpp
Myclass(int) = default;  bu geçersizdir. !!!!!!!!!!!!!!!!!!!



class Myclass {
public:
	Myclass(); // default constructor
	~Myclass(); // destructor
	Myclass(Myclass& other); // copy constructor
	Myclass(Myclass&& other); // move constructor
	Myclass& operator=(Myclass& other); // copy assignment operator
	Myclass& operator=(Myclass&& other); // move assignment operator
};
```

COPY CTOR
```cpp
Myclass m1; default ctor
Myclass m2 = m1; copy ctor
Myclass m3(m1); copy ctor
Myclass m4{m1}; copy ctor
```

Bir sınıfın copy ctoru bildirilmiş olmak zorunda
not-declared (special member function yok)
user-declared (programcı tarafından bildirilmiş)
```cpp
//user declared

class Myclass {
public:
	Myclass();  // user - declared
	Myclass() = default; // user - declared
	Myclass() = delete; // user - declared
};
```

Derleyicinin bir sınıfın bir special member function'ı nasıl
default edeceği yani onun kodunu nasıl yazacağı belirlidir.
(dilin kuralları var)
Bu kurallara göre derleyici bir sınıfın sp.mem.func.'ını
default ederken dilin kurallarını çiğneyen bir durum oluşursa
	derleyici default etmesi gereken fonksiyonu deleted oalrak bildirir.
