# 21.DERS|

---

```cpp
	vector vec{ 2,5,7,9,3 };

	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec.operator[](i) << vec[i] << '\n';
	}
```

	İki gösterimde aynı aslında.
```cpp
	std::vector
	std::string
	std::deque
```

	map
	array
```cpp
	class Darray
{
public:
	Darray(std::size_t size) :msize(size),mp(new int[size])
	{
		std::memset(mp, 0, size * sizeof(int));
	}
	Darray(std::size_t size, int val) :msize(size), mp(new int[size])
	{
		for (size_t i = 0; i < size; i++)
		{
			mp[i] = val;
		}
	}
```

	~Darray()
```cpp
	{
		if (mp)
		{
			std::cout << "Destructor\n";
			delete[] mp;
			msize = 0;
		}
	}
	int& operator[](std::size_t idx)
	{
		return mp[idx];
	}
	const int& operator[](std::size_t idx)const
	{
		return mp[idx];
	}
	std::size_t size()const {
		return msize;
	}

private:
	std::size_t msize;
	int* mp;
};


	Darray x(10,3);
	const Darray cx(10, 20);

	x[3] = 23;  // non - const veri atanabilir
	cx[2] = 11; // cost veri atanamaz.
```

	Bunu da
```cpp
		int& operator[](std::size_t idx)
	{
		return mp[idx];
	}
	const int& operator[](std::size_t idx)const
	{
		return mp[idx];
	}

	const overloading ile yapıyorum.

```

---

	dereferencing
---

	member selection arrow
```cpp
	->
```

	overload edilmesi var.
	öyle bir sınıf olsun ki
```cpp
	nesneleri std::string sınıfı türünden
```

	dinamik ömürlü nesnelerin hayatlarını kontrol
	edecek pointer'lar gibi davransın.
	sınıfımızın ismi string_ptr olsun.
```cpp
	ptr-> b    (*ptr).b
```

	Dikkat!
```cpp
	ok operatörü 2 operand alan bir operator olmasına karşın
	unary operator olarak overload edilir.

	ptr->foo()
	ptr.operator->()->foo()

	template <typename T>
class smartptr
{
public:
	smartptr() = default;
	smartptr(T* p) :mp(p) {}
```

	~smartptr()
```cpp
	{
		if (mp)
			delete mp;

	}
```

	smartptr(smartptr&& other) :mp(other.mp)
```cpp
	{
		other.mp = nullptr;
	}
	smartptr& operator=(smartptr&& other)
	{
		delete mp;
		mp = other.mp;
		other.mp = nullptr;
		return *this;
	}

	bool has_object()const {
		return mp != nullptr;
	}
	T& operator*()
	{
		return *mp;
	}
	T* operator->()
	{
		return mp;
	}

private:
	T* mp{ nullptr };

};


int main()
{
	using namespace std;
	{


		smartptr<string> p1(new string{ "selami karakelli" });
		cout << *p1 << '\n';
		smartptr<Mint> p2(new Mint{ 345 });
		cout << *p2 << '\n';
		smartptr<int> p3(new int{ 7564 });
	}






}

C++ generic programlama ile verilene  cpp sonsuz adet bu templateden bizim için
```

olusturabilir.
---

21. ders tekrar
```cpp
class Darray {
public:
	Darray(std::size_t size) :msize(size),mp(new int[msize])
	{
		std::memset(mp, 0, msize*sizeof(int));
		std::cout << "Darray(std::size_t size)\n";
	}
```

	~Darray()
```cpp
	{
		delete[] mp;
		std::cout << "Destructor\n";
	}
	int& operator[](std::size_t idx)
	{
		return mp[idx];
	}
	std::size_t size()const {
		return msize;
	}
private:
	std::size_t msize;
	int* mp;

}

	Darray x(10);
	for (size_t i = 0; i < x.size(); i++)
	{
		cout << x[i] << x.operator[](i)<< '\n';
	}
	for (size_t i = 0; i < x.size(); i++)
	{
		x[i] = i;

	}
	for (size_t i = 0; i < x.size(); i++)
	{
		cout << x[i] << '\n';
	}

```

---

```cpp
		int& operator[](std::size_t idx)const
	{
		return mp[idx];
	}


	const Darray x(10);


	for (size_t i = 0; i < 10; i++)
	{
		x[i] = i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << x[i] << '\n';
	}
```

	Const olmasına rağmen değer atabiliyorum ?
```cpp
		const int& operator[](std::size_t idx)const
	{
		return mp[idx];
	}
```

	Böyle yaparsam da sadece read-only ...
	 o yüzden overload etmem gerek.
---

```cpp
	 int& operator[](std::size_t idx)
	{
		return mp[idx];
	}
	 int operator[](std::size_t idx)const {
		 return mp[idx];
	}
```

---

overload edince eğer sadece
```cpp
const nesneler için const
```

non-const olan nesneler için non-const
dereferencing
---

member selection arrow
```cpp
->

*ptr


ptr->foo()
```

	(*ptr).foo()
```cpp
ptr->mx
```

	(*ptr).mx
a
```cpp
*ptr

```

---

	Dikkat!
```cpp
	ok operatörü 2 operand alan bir operator olmasına karşın
	unary operator olarak overload edilir.
```

---

	Global op. olamaz.
```cpp
		std::string* operator->()
	{
		return mp;
	}
```

	Olay şu :
```cpp
	sptr->lenght() mesela length std::string e ait bir fonksiyon değil mi ?
```

	-evet
```cpp
	O zaman ben  std::string* yani bir string addresi döndürmem gerek ->

	std::string* operator->() yani -> operatorle bir string addresi döndürmem gerek.

	std::string* operator->()
	{
		return mp;  // mp'nin kendisini döndürmem gerek
	}
	cout << sptr->length();

```

---

```cpp
/*
* şimdi stringptr sınıfını move only
* type yapalım
* yani kopyalamaya kapalı taşımaya açık
*/




struct A {

	void foo();
};

struct B {
	B(A);
	void bar();
};


int main()
{
	// most vexing parse

	// burada aslında b türünden bx değişkeninin olusturmak
	// istiyorum fakat . 'most vexing parse'  Geri dönüşü
	// b olan bx fonksiyonu olarak tanımlıyor.
	B bx(A());
```

	Legal olan yapılar:
```cpp
	{} kullandığında fonk. tanımı olma ihtimali yok.
	B bx{ A() };
	B bx( A{} );
	B bx{ A{} };
	B bx((A()));  --> öncelik parantezi !!


```

## Type-cast operator functions

tür dönüştürme operatörü
(target_type)
(int)dval
```cpp
	int x = 5;
	Myclass m;
	x = m;
```

	Bunu yapamıyoruz.
```cpp
	/*
	* geri dönüş değeri yazılmayacak. (kural)
	yazılsa idi int operator int()const gibi kendini
```

	tekrar eden bir yapı olacaktı. Bu istenmemiş ve kural koyulmuş.
```cpp
	*/
	operator int() const
	{
		std::cout << "operator int() const\n";
		return 42;
	}

		int x = 5;
	Myclass m;
	x = m;

	std::cout << x; artık legal
```

	conversion ctor
	conversion sequence
	std conv + udc
	udc + std conv
	std conv. + std conv. olmuyor.!!!!
```cpp
	 	double y;
	y = m;

	int için dönüşüm ekledim fakat double 'da oluyor ?
```

	BUnu kaldırmak için explicit eklemek gerek :
```cpp
		explicit operator int() const
	{
		std::cout << "operator int() const\n";
		return 42;
	}

	Myclass m;
	int x = static_cast<int>(m);
```

	artık böyle dönüşüm yapacak.
	overload da edilebilir.
```cpp
if(expr)
while(expr)
```

do while(expr)
```cpp
for(expr)


```

## function call operator function

```cpp
	Myclass m;
	m();
	//m.operator()();

	void operator()()
	{
		std::cout << "Myclass operator()()\n";
		std::cout << "this: "<< this <<'\n';
	}
Myclass operator()()
```

this: 0000005BDAD6F804
