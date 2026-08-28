# 30.ders			|

---

car.h
```cpp
#pragma once

#include<iostream>
#include<string>
#include<random>

class Car {
public:
	virtual void start() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual Car* clone() = 0;
};

class Peugeot :public Car {
public:
	void start()override
	{
		std::cout << "Peugeot has just started!\n";
	}
	void run()override
	{
		std::cout << "Peugeot is running now!\n";
	}
	void stop()override
	{
		std::cout << "Peugeot has stopped!\n";
	}
	virtual Car* clone()override {
		return new Peugeot(*this);
	}
};

class Opel :public Car {
public:
	void start()override
	{
		std::cout << "Opel has just started!\n";
	}
	void run()override
	{
		std::cout << "Opel is running now!\n";
	}
	void stop()override
	{
		std::cout << "Opel has stopped!\n";
	}
	virtual Car* clone()override {
		return new Opel(*this);
	}
};


class Audi :public Car {
public:
	void start()override
	{
		std::cout << "Audi has just started!\n";
	}
	void run()override
	{
		std::cout << "Audi is running now!\n";
	}
	void stop()override
	{
		std::cout << "Audi has stopped!\n";
	}
	virtual Car* clone()override {
		return new Audi(*this);
	}
};
class Honda :public Car {
public:
	void start()override
	{
		std::cout << "Honda has just started!\n";
	}
	void run()override
	{
		std::cout << "Honda is running now!\n";
	}
	void stop()override
	{
		std::cout << "Honda has stopped!\n";
	}
	virtual Car* clone()override {
		return new Honda(*this);
	}
};

class Mercedes :public Car {
public:
	void start()override
	{
		std::cout << "Mercedes has just started!\n";
	}
	void run()override
	{
		std::cout << "Mercedes is running now!\n";
	}
	void stop()override
	{
		std::cout << "Mercedes has stopped!\n";
	}
	virtual Car* clone()override {
		return new Mercedes(*this);
	}
};

class Volvo :public Car {
public:
	void start()override
	{
		std::cout << "Volvo has just started!\n";
	}
	void run()override
	{
		std::cout << "Volvo is running now!\n";
	}
	void stop()override
	{
		std::cout << "Volvo has stopped!\n";
	}
	virtual Car* clone()override {
		return new Volvo(*this);
	}
};

class Toyota :public Car {
public:
	void start()override
	{
		std::cout << "Toyota has just started!\n";
	}
	void run()override
	{
		std::cout << "Toyota is running now!\n";
	}
	void stop()override
	{
		std::cout << "Toyota has stopped!\n";
	}
	virtual Car* clone()override {
		return new Toyota(*this);
	}
};

class HondaCivic :public Honda {
public:
	void start()override
	{
		std::cout << "HondaCivic has just started!\n";
	}
	//void run()override
	//{
	//	std::cout << "HondaCivic is running now!\n";
	//}
	void stop()override
	{
		std::cout << "HondaCivic has stopped!\n";
	}
	virtual Car* clone()override {
		return new HondaCivic(*this);
	}
};
```

inline Car* create_random_car()
```cpp
{
	static std::mt19937 eng;
	static std::uniform_int_distribution dist(0, 7);
	switch (dist(eng)) {
	case 0: std::cout << "Peugeot case\n"; return new Peugeot;
	case 1: std::cout << "Opel case\n"; return new Opel;
	case 2: std::cout << "Audi case\n"; return new Audi;
	case 3: std::cout << "Honda case\n"; return new Honda;
	case 4: std::cout << "Mercedes case\n"; return new Mercedes;
	case 5: std::cout << "Volvo case\n"; return new Volvo;
	case 6: std::cout << "Toyota case\n"; return new Toyota;
	case 7: std::cout << "HondaCivic case\n"; return new HondaCivic;

	default: return nullptr;

	}
}
```

---

polimorfik sınıfların
	destructor'lari
		ya public virtual
			ya da
				orıtected non-virtual olmalı
Herb Sutter
virtual ctor idiom
virtual dtor
virtual friend
virtualization of free functions
TEkrar izliyorums.
CTOR sanal olamaz.
 polimorfik sınıfların
	destructor'ları
		ya public virtual
			ya da
				protected non-virtual
					olmalı !
Herb Sutter.
```cpp
	Base* baseptr = new Der;


	delete baseptr;  // ub

class Base
{
public:
```

	virtual void foo()
```cpp
	{
		std::cout << "Base::foo()\n";
	}
	virtual ~Base() {
		std::cout << "Base destructor \n";
	}
};
```

eğer dtoru virtual yapmazsak ub oluyor.
virtual constructor
virtual destructor
virtual friend
virtualiation of free functions
virtual dispatch ilave maliyeti
a) işlem sayısı
b) kullanulan bellek alanı
Dikkat!!!
```cpp
C++ standartı hiçbir zaman implen



```

---

```cpp
void car_game(Car* carptr)
{
	std::cout << *carptr << '\n';
	carptr->start();
	carptr->run();
	carptr->stop();

}

int main()
{

	for (size_t i = 0; i < 10; i++)
	{
		car_game(create_random_car());
		(void)getchar();
	}

	return 0;
}
```

---

Sınıf hiyerarşisi içindeki tüm sınıflar için
derleyicinin oluşturduğu kod runtime'ın başında
bir veri yapısı (virtual function table)
her türemiş sınıf nesnesinin içindeki
	vptryi
	, ilgili sınıfın sanal fonksiyon tablosunun  addresi ile init ediyor.
	virtual function table for Mercedes
	0
	1		&Mercedes::start
	2		&Mercedes::run
	3		&Mercedes::stop
	virtual function table for Audi
	0
	1		&Audi::start
	2		&Audi::run
	3		&Audi::stop
işlem maliyeti
	her sınıf için bir sanal fonksiyon tablosu oluşturulacak.
```cpp
	carptr->run()
	carptr->vptr[2]
```

Kalıtım tek alternatifimiz değil.
Generic programlama
	CRTP  curiously recurring template pattern
	closed hierarchy
```cpp
std::variant
```

type-erasure
öyle durumlar var ki
	derleyidci
		bir sanal fonksiyon çağırısı söz konusu olmasına karşın
			derleme zamanında
				hangi fonksiyonun çağrılacağını
					anlayabiliyor.
final
	sınıf içinde yapılan using bildirimi
```cpp
using word = int ;

using std::cout
using namespace std::placeholders;

using enum Color;

using Color::Blue;
```

inherited constructor
final class ,  öyle bir sınıf ki o kalıtımda taban sınıf olarak kullanılamaz.
final override
