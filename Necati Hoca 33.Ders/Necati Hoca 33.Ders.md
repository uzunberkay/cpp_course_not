# 33

---

```cpp
class Device{
public:
	virtual ~Device() = default;  // polymorphic base class
};


#include<iostream>


class Device{
public:
	virtual ~Device() = default;  // polymorphic base class
	void turn_on(){
		m_onflag = true;
		std::cout << "Device is turned on.\n" ;
	}
	void turn_off(){
		m_onflag = false;
		std::cout << "Device is turned off.\n" ;
	}

	bool is_on() const {
		return m_onflag;
	}
private:

	bool m_onflag{};

};

class Scanner: public Device{

public:
	void scan()
	{
		if(is_on())
			std::cout << "Scanning document...\n";
		else
			std::cout << "Scanner is off. Please turn it on first.\n";
	}
};
class Printer: public Device{

public:
	void print()
	{
		if(is_on())
			std::cout << "Printing document...\n";
		else
			std::cout << "Printer cannot print the device is off\n";
	}
};

class Combo: public Scanner, public Printer{
};

int main(){

	Combo myCombo;
	myCombo.turn_on();
	myCombo.print();
	myCombo.scan();
	myCombo.turn_off();
	myCombo.print();
	myCombo.scan();
	return 0;
}

```

---

virtual inheritance
virtual function
virtual despatch
pure virtual function
virtual destructor
virtual constructor idiom
devirtualization optimization
```cpp
// device is virtual Base now
class Device {
public:
	virtual ~Device() = default;  // polymorphic base class
	void turn_on() {
		m_onflag = true;
		std::cout << "Device is turned on.\n";
	}
	void turn_off() {
		m_onflag = false;
		std::cout << "Device is turned off.\n";
	}

	bool is_on() const {
		return m_onflag;
	}
private:

	bool m_onflag{};

};

class Scanner : virtual  public Device {

public:
	void scan()
	{
		if (is_on())
			std::cout << "Scanning document...\n";
		else
			std::cout << "Scanner is off. Please turn it on first.\n";
	}
};
class Printer : virtual public Device {

public:
	void print()
	{
		if (is_on())
			std::cout << "Printing document...\n";
		else
			std::cout << "Printer cannot print the device is off\n";
	}
};

class Combo :public Scanner, public Printer {


};

int main()
{

	/*
	* Artık virtual inheritance sayesinde Device sınıfının tek bir örneği var ve Combo sınıfı bu tek örneği kullanıyor.
	* yani iki sınıf da Device sınıfını kalıtım alıyor ama virtual inheritance sayesinde tek bir Device örneği var ve Combo sınıfı bu tek örneği kullanıyor.
	* ortak fonksiyonlar da tek bir Device örneği üzerinden çağrılıyor.
	*/
	Combo mycombo;
	mycombo.turn_on();
	mycombo.print();
	mycombo.scan();


	return 0;
}






class Base{};

class Der :public Base {};

class NecDer :public Der {};

// direct Base class
// indirect Base class
```

ctor init list ile
yalnızca doğrudan taban sınıfın ctor'ina çağrı yapılabilir.
dolaylı taban sınıfın ctor'ina çağrı yapılamaz.
```cpp
class Base{
public:
	Base(const char* p)
	{
		std::cout << "Base(const char* p) called with p = " << p << '\n';
	}

};

class DerX : virtual public Base {
	public:
```

		DerX() :Base("called by DerX ctor\n")
```cpp
	{

	}
};

class DerY : virtual public Base {
public:
```

	DerY() :Base("called by DerY ctor\n")
```cpp
	{

	}
};

class Mder :public DerX, public DerY {
public:
```

	Mder():Base("called by Mder ctor\n")
```cpp
	{
	}

};

class NecDer :public Mder {
public:
```

	NecDer() :Base("called by NecDer ctor\n")
```cpp
	{
	}

};


// direct Base class
// indirect Base class

int main(){

	DerX d1;
	DerY d2;
	Mder d3;
	NecDer d4;

	return 0;
}


```

---

```cpp
Generic programming in C++
```

öyle bir kod olsun ki bu kod
 birden fazla data-type  için kullanılabilsin.
```cpp
void c_generic_swap(void* p1, void* p2,size_t sz)
{
	char* pp1 = (char*)p1;
	char* pp2 = (char*)p2;
	while (sz--)
	{
		char *temp = *pp1;
		*pp1 = *pp2;
		*pp2 = temp;
		++pp1, ++pp2;
	}
}
```

c de generic swap fonksiyonu
Cppde
derleme zamanında derleyiciye kod yazdırmak.
derleyicinin kod yazmasını sağlayan kod formuna
```cpp
	template denir.
```

generic code
meta code
```cpp
template öyle bir kod ki varlık nedeni
```

  derleyiciye kod yazdırmaktır.
```cpp
  function template (fonksiyon şablonu) C++98
  class template (sınıf şablonu)	 C++98

  variable template (değişken şablonu) C++14
  alias template (tür eş isim şablonu) C++11
  concept template (kavram şablonu) C++20


  template instantiate

  template specialization
   template kodda üretilen  kodun kendisi

// template parameters
// type parameters
// non - type parameters
// template template parameters

template <std::size_t N>
class bitset {

};





template <typename T>
void swap(T &x, T &y){
	T temp(std::move(x));
	x = std::move(y);
	y = std::move(temp);
}
	double a = 2.3, b = 5.4;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
```

x
derleyicinin derleme zamanında
bir template'ten bir kodu oluşturabilmesi için
```cpp
template parametrelerine karşılık kullanılacak template argumanlarının
```

ne ya da neler olacağını bilmesi gerekir.
```cpp
explicit template argument(s)
deduction (çıkarım)
	template argument deduction (şablon argüman çıkarımı)
	CTAD (class template argument deduction)


template <typename T = int>
class Myclass{};

int main(){


	Myclass <> obj1; // default template argument kullanımı

	return 0;
}



template instantiation  == > template specialization
```

implcit instantiation
```cpp
explicit instantiation



explicit(full) specialization
```

derleyiciye bir template specialization için
kodun kendisini vermek
partial specialization
Exception handling
hata
geleneksel hata işleme yöntemleri
error
    programming errors
	kod çalışma zamanında işini yapamıyor
	çünkü kod yanlış yazılmış.
	runtime errors
```cpp
	assertions(doğrulama)
```

	static assertions(derleme zamanında doğrulama)
	dynamic asserions(çalışma zamanında doğrulama)
çağrılan bir fonksiyon (beklenmeyen nedenler ile )
işini yapamayacağını (başarısız olacağını) anlarsa
ne yapacak ?
kendisini çağıran kodu bu durumdan haberdar edecek.
1) geri dönüş değeri ile iletilmesi
2)  int foo(,int* perror)
3) global bir hata değişkenini set etmek
 - Geleneksel hata yönetme metotlarının dezavantajları
 -
try
throw
catch
try block
biz bir hata olusması durumunda işlemek istiyorsak o kodu try bloğu içine koyuyoruz.
```cpp
throw statement;



try{

	f1();
}
catch(???)
{
}
```

çağrılan bir fonksiyon  beklenmeyen nedenlerle işiin yapamayacağını anlarsa
ne yapacak ?
kendsiini çağıran kodu bu durumdan haberdar edecek.
1) geri dönüş değeri ile iletilmesi
```cpp
	int remove(const char* p);
```

2) int foo(,int *perror)
3) global bir hata değişkenini set etmek  errno.h 'daki errno gibi
Geleneksel hata yönetme metotlarının dezavantajları
```cpp
int x = do_something();
if(x == ?)
{
	// error handling code
}
```

try
```cpp
		throw statement; // hata fırlatmak.
```

catch
try block hata olusabilecekw bir kod bloğu
catch block ise o hatayı yakalayarak işlemek için kullanılır.
