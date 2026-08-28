# Necati Hoca 29.Ders

```cpp
#include<iostream>
#include<ostream>


class Car {

public:
	void start(){
		std::cout << "Car start\n";
	}
	void stop() {
		std::cout << "Car stop !\n";
	}
	void run()
	{
		std::cout << "Car run!\n";
	}
};

void car_game(Car& car)
{
	car.start();
	car.run();
	car.stop();
}

class Audi:public Car{};
class Bmw:public Car{};
class Volvo:public Car{};
class Honda:public Car{};
class Toyota:public Car{};

int main()
{
	Audi audi;
	Bmw bmw;
	Volvo volvo;

	car_game(audi);
	car_game(bmw);
	car_game(volvo);
	return 0;
}
```

Car start
Car run!
Car stop !
Car start
Car run!
Car stop !
Car start
Car run!
Car stop !
Audi Bmw Volvo gibi türetilmis sınıfları base sınıfın yönetildiği bir
fonksiyonda veya işlevde kullanabiliyorum.
taban sınıfın öyle bir fonksiyonu ki
	türemiş sınıflara hem bir interface
		hemde implementasyon verir.
Airplane
fly
taban sınıfın öyle bir fonksiyonu ki
	türemiş sınıflara hem bir interface
		hemde 'default' verir
Airplane
land
taban sınıfın öyle bir fonksiyonu ki
	türemiş sınıflara hem bir interface
		imğlemtasyonu türemiş sınıflara bırakıyor.
polymorphic class
abbstract class( soyut sınıf )
override
```cpp
	void start(){  // start 1. kategori
		std::cout << "Car start\n";
	}
```

2. kategorideki fonksiyonlar için 'virtual' eklenir.
	virtual void run()
```cpp
	{
		std::cout << "Car run!\n";
	}
```

1den fazla kategoride barındırıyorsa class 'polymorphic class ' olur.
3. kategori fonksiyonlar için  'pure virtual function'
```cpp
virtual void stop() = 0;
```

'Soyut olmak icin 3. kategoriden olmak zorunda'
contextual ketword
bağlamsal anahtar sözcük
```cpp
class Car {
public:
	void start()
	{
		std::cout << "car has just started !\n";
	}
	virtual void run();
	virtual void stop() = 0; // pure virtual function
};


/*
* Somut sınıf diyebilir miyiz ElecetricCar için .
* Cevap evet.
* Çünkü taban sınıfın pure virtual func.'ni override etti.
```

---

```cpp
*/
class ElectricCar :public Car {
public:
	void stop()override;
};

```

---

Soyut sınıflardan nesne olusturamazsın
Dikkat!!!
Türemiş sınıf
	taban sınıfın sanal fonksiyonu ile
		aynı isme aynı imzaya sahip
			fakat geri dönüş türü farklı olan bir fonksiyon bildiremez.
				ancak bunun önemli bir istisnası
					covariance  - covariant
-
static binding (early binding)
dynamic binding (late binding)
---

```cpp
class Car {
public:
	void start()
	{
		std::cout << "car has just started!\n";
	}
	void run()
	{
		std::cout << "car is running now!\n";
	}
};
class Peugeot :public Car {
public:
	void start()
	{
		std::cout << "Peugeot has just started!\n";
	}
	void run()
	{
		std::cout << "Peugeot is running now!\n";
	}
};

class Opel :public Car {
public:
	void start()
	{
		std::cout << "Opel has just started!\n";
	}
	void run()
	{
		std::cout << "Opel is running now!\n";
	}
};

void game_car(Car& c)
{
	c.start();
	c.run();
}


int main()
{
	Peugeot p;
	Opel op;
	game_car(p);
	game_car(op);


	return 0;
}
```

car has just started!
car is running now!
car has just started!
car is running now!
---

	virtual void start()
```cpp
	{
		std::cout << "car has just started!\n";
	}
```

	virtual void run()
```cpp
	{
		std::cout << "car is running now!\n";
	}
```

	Peugeot has just started!
Peugeot is running now!
Opel has just started!
Opel is running now!
virtual dispatcj / sanal gönderim.
---

```cpp
--
class Car {
public:
```

	virtual void start()
```cpp
	{
		std::cout << "car has just started!\n";
	}
```

	virtual void run()
```cpp
	{
		std::cout << "car is running now!\n";
	}
```

	virtual void stop()
```cpp
	{
		std::cout << "car has stopped!\n";
	}
};
class Peugeot :public Car {
public:
	void start()
	{
		std::cout << "Peugeot has just started!\n";
	}
	void run()
	{
		std::cout << "Peugeot is running now!\n";
	}
	void stop()
	{
		std::cout << "Peugeot has stopped!\n";
	}
};

class Opel :public Car {
public:
	void start()
	{
		std::cout << "Opel has just started!\n";
	}
	void run()
	{
		std::cout << "Opel is running now!\n";
	}
	void stop()
	{
		std::cout << "Opel has stopped!\n";
	}
};

void game_car(Car& c)
{
	c.start();
	c.run();
}


int main()
{
	Peugeot p;
	Opel op;
	game_car(p);
	game_car(op);


	return 0;
}
--

class Base {
public:
	virtual int foo(unsigned int);
	int bar(int);
};

class Der :public Base {
public:
	int bar(int);  // !
};

```

---

```cpp
	int foo(int)override;
	int bar(int);
```

	bu override ekleyerek derleyiciye bu fonksiyonun override oldugunu söylüyosun
bu da hata yapmanı önler.
---

Bir taban sınıfın bir sanal fonksiyonunu override eden türemiş sınıf fonksiyonu
virtual anahtar sözcüğünü kullanmasa da  sanal bir fonksiyondur.
```cpp
class Base {
public:
	virtual int foo( int);
};

class Der :public Base {
public:
	int foo(int)override;  // burada istersen virtual kullan kullanma.
};

```

---

```cpp
class Base {
public:
	virtual void foo() {
		std::cout << "Base::foo()\n";
	}
};

class Der :public Base {
public:
	void foo()override
	{
		std::cout << "Der::foo()\n";
	}
};

class NecDer :public Der {
public:
	void foo()override
	{
		std::cout << "NecDer::foo()\n";
	}
};

	Der myder;
	NecDer mynecder;

	Base* baseptr = &myder;
	baseptr->foo();
	baseptr = &mynecder;
	baseptr->foo();
```

Der::foo()
NecDer::foo()
Eğer Necder ve der deki fooyu silsek basedeki foo çalışacaktı.
---

virtual dispatch hangi durumlarda devreye girer.
virtual dispatch hangi durumlarda devreye girmez.
1. taban sınıf nesnesi ile sanal fonksiyon çağrılırsa
virtual dispatch devreye girmez.
Dikkat!
taban sınıfın ctor'ı içinde yapılan sanal fonksiyon çağrıları
için virtual dispatch uygulanmaz.
Taban sınıfın dtor'ı içinde yapılan sanal fonksiyon
çağrıları için 'virtual dispatch' uygulanmaz!
çağrılan taban sınıf fonksiyonudur.
2.
<<<<<<< HEAD
---

Tekrar dinliyorum.
```cpp
class Car {
public:
	void start()
	{
		std::cout << "Car has just started!\n";
	}
	void run()
	{
		std::cout << "Car is running now \n";
	}
	void stop()
	{
		std::cout << "Car has stopped! \n";
	}

};

class Audi : public Car {

};

class Bmw : public Car {

};
class Volvo : public Car {

};

void car_game(Car& car)
{
	car.start();
	car.run();
	car.stop();
}

int main()
{
	Audi audi;
	Bmw bmw;
	Volvo volvo;

	car_game(audi);
	car_game(bmw);
	car_game(volvo);


	return 0;
}
```

Car has just started!
Car is running now
Car has stopped!
Car has just started!
Car is running now
Car has stopped!
Car has just started!
Car is running now
Car has stopped!
Her sınıf için Car sınıfı çalıştı.
taban sınıfın öyle bir fonksiyonu ki
	türemiş sınıflara hem bir interface
		hem  de implentasyon verir.
		 Galiba virutal
Airplane
	fly   Her uçak uçar sizde uçacaksınız istersen kendi kodunla istersen benim kodla uç.
taban sınıfın öyle bir fonksiyonu ki
	türemiş sınıflara hem bir interface
		hem de "default" implentasyon verir.
```cpp
		Galiba virtual void foo()=0; gibi bir şey.
```

taban sınıfın öyle bir fonksiyonu ki
	türemiş sınıflara yalnızca  bir interface veriyor.
		imğlentasyonu  türemiş sınıfa bırakıyo.
	polymorphic class
	abstract class (soyut sınıf)  3. klasmanda en az 1 fonk olursa
	override
```cpp
class Car {
public:
	void start()  // 1. kategori
	{
		std::cout << "Car has just started!\n";
	}
```

	virtual void run()  // 2.kategori.  sizinde run fonksiyonunuz olcak.
	eğer ovveride ederseniz onu kullanırsınız etmezseniz benimkini kullanırsınız.
```cpp
	{
		std::cout << "Car is running now \n";
	}
	virtual void stop() = 0;  //  pure virtual function  sap sanal
	// 3. kategori Paşa paşa bu fonksiyonu sen yazacaksın.



class Skoda :public Car {

public:
	void run()override;
};
};
```

Dikkat!
Türemiş sınıf  taban sınıfın sanal fonksiyonuyla
aynı isme aynı imzaya sahip fakat geri dönüş türü farklı olan bir
fonksiyon bildiremez.
Ancak bunun önemli bir istisnası var.
	covariamce - covariant
1:0:0
=======
```cpp
class Base {
public:
```

	virtual void foo()
```cpp
	{
		std::cout << "Base::foo\n";
	}
};

class Der : public Base {
private:
	void foo()override
	{
		std::cout << "Der:foo()\n";
	}

```

---

```cpp
class Car {
public:
    void start()
    {
        std::cout << "Car has just started!\n ";
    }
    void run()
    {
        std::cout << "car is running now!\n";
    }
};

class Peugeot :public Car {
public:
    void start()
    {
        std::cout << "Peugeot has just started!\n ";
    }
    void run()
    {
        std::cout << " Peugeot is running now!\n";
    }
};

class Opel :public Car {
public:
    void start()
    {
        std::cout << "Opel has just started!\n ";
    }
    void run()
    {
        std::cout << " Opel is running now!\n";
    }
};


void car_game(Car& carref)
{
    carref.start();
    carref.run();
}

int main()
{
    Peugeot p;
    Opel op;
    car_game(p);
    car_game(op);
```

	Car has just started!
 car is running now!
Car has just started!
 car is running now!
```cpp
 class Car {
public:
```

    virtual oid start()
```cpp
    {
        std::cout << "Car has just started!\n ";
    }
```

    virtual void run()
```cpp
    {
        std::cout << "car is running now!\n";
    }
};
```

    base sınıfdaki fonksiyonları "VIRTUAL" yaparsak
	Peugeot has just started!
  Peugeot is running now!
Opel has just started!
  Opel is running now!
  tabiii türetilmiş sınıfdakileri de override eklemek önemli.
```cpp
}
```

 bir taban sınıfın  bir sanal fonksiyonunu
 override eden türemiş  sınıf fonksi,yopnu
 virtuaşll anahtar sözcüğünü kullanmasa da  da sanal bir  fonksiyondur.
 Virtual dispatch hangi durumlarda devreye girer
 Virtual dispatch hangi durumlarda devreye girmez
Çağrının pointer veya referans ile yapılması gerekiyor.
Virtual fonksiyon base sınıfın public kısmında olmak zorunda değil.
Private kısımda da olabilir.
```cpp
class Base {
private:
```

	virtual void foo()
```cpp
	{
		std::cout << "Base::foo\n";
	}
public:
	void bar();
};


class Der :public Base {

	void foo()override
	{
		std::cout << "Der::foo\n";
	}

};

void Base::bar()
{
	Base* basep = new Der;

	basep->foo();
}


int main()
{
	Base b;
	b.bar();

	return 0;
}
```

Der::foo
Virtual dispach oluyor.
---

global fonklar ve sınıfın static fonkları virtual olamaz.
Dikkat!
Taban sınıfın ctor'i içinde yapılan sanal
fonksiyon çağrıları için virtual dispatch uygulanmaz!
çağrılan taban sınıfın fonksiyonudur!!!
```cpp
class Base {
public:
	Base()
	{
		std::cout << "Base default ctor \n";
		foo();
	}
```

	virtual void foo()
```cpp
	{
		std::cout << "Base::foo\n";
	}
};
Base* basep = new Der;
```

Base default ctor
Base::foo
DTOR'da da olmaz.
Taban sınıfın dtor'i içinde yapılan sanal
fonksiyon çağrıları için virtual dispatch uygulanmaz!
çağrılan taban sınıfın fonksiyonudur!!!
