# |28. DERS*|

|*********|
```cpp
	string str;
	cout << "Bir yazi girin : ";
	getline(cin,str);
	print(str);
	reverse(str.begin(), str.end()); // terrs çevir
	print(str);
	sort(str.begin(), str.end());  // sırala
	print(str);
```

---

```cpp
	mt19937 eng;
	for (size_t i = 0; i < 10; i++)
	{
		shuffle(str.begin(), str.end(), eng); // karıştır
	}
```

---

INHERITENCE
	runtime polymorphism
OOP
	Car					BMW
	parent	class    - child class
	super	class	 - subclass
base class ( taban sınıf )
	derived class ()
		derivation
```cpp
single inheritance    CAR -> VOLVO
multi-level inheritance	CAR -> VOLVO -> VOLVO S90
```

eski kodların daha sonradan yazılacak kodları kullanabilmesi
public inheritance   diğer dillerdeki kalıtım...
private inheritance
protected inheritance
!!!!!!!!!	Base class incomplete type olamaz.	!!!!!!!!!
```cpp
class Car {

};

class Mercedes :public Car {  public kalıtımı
```

eğer yazılmaz ise private...
```cpp
};

```

---

```cpp
class Base {
	//...
};

class Der :public Base {
	//...
};

	//upcasting
	Der myder;
	Base mybase = myder;
```

---

```cpp
class Car {
public:
	void start();
	void run();
	void stop();
};

class Mercedes :public Car {
public:
	void open_sunroof();
	void main_tain();
};


void cargame(Car& car);

int main()
{
	Mercedes mrc;
	mrc.run();
	mrc.open_sunroof();

	return 0;
}
```

---

Taban sınıfın private bölümü kalıtımda türemiş sınıflara kapalıdır.
```cpp
class Base {
private:
	void foo();
protected:
	void bar();
public:
	void baz();
};

class Der : public Base {
	void derfunc()
	{
		baz();	// public
		foo();  // private  ulaşamıyorum
		bar();	// protected ulaşabiliyorum
	}
};
```

---

Der sınıfı Base sınıfından kalıtım ile elde edilmiş.
Der sınıfının Member sınıfı türünden bir elemanı var.
```cpp
Der my ;
Base->Member->Der

class A {
public:
	A()
	{
		cout << "A ctor \n";
	}
};
class B {
public:
	B()
	{
		cout << "B ctor \n";
	}
};
class Base {
public:
	Base()
	{
		cout << "Base ctor\n";
	}
};

class Der :public Base {
public:
	Der()
	{
		cout << "Der ctor \n";
	}
	A ax;
	B bx;
};
```

Base ctor
A ctor
B ctor
Der ctor
```cpp
dtorlarda tam tersi.    Der dtor -> B dtor -> A dtor -> Base ctor
```

---

```cpp
class Base {
public:
	Base()
	{
		cout << "Base def. ctor\n";
	}
	Base(int) { cout << "Base(int)\n"; }
	Base(int, int) { cout << "Base(int,int)\n"; }
};

class Der :public Base {
public:


};

Der myder;
```

Burada Der için def. ctor çalışacak ve Base içinde.
Eğer base sınıftaki def. ctoru silersek derleyici Der sınıfındaki def.
ctoru deleted eder.
```cpp
	Der myder;
	Base* baseptr = &myder;
	Base& baseref = myder;
	Base mybase = myder; // valid code
```

	Bunlar geçerli fakat çok kullanılmayacak. Sakıncaları var.
---

```cpp
class Base {
public:
	int x;
};

class Der :public Base {



};


int main()
{
	Der m;

	m.x;  // ilk der'e bakıcak eğer x i bulursa arama bitecek.
	// Türetilmiş class'da x  yoksa base sınıfa bakacak.
```

---

```cpp
class Base {
public:
	void foo(int, int);
};

class Der :public Base {

public:
	void foo(int x)
	{
		//foo(2,5);  // legal değil.
		//foo(2);  // legal kendimi çağırırım
		Base::foo(3,2); // legal Base'deki foo yu çağırıyorum.
	}

};
int main()
{
	Der m;
	return 0;
}
```

---

```cpp
class Base {
public:
	Base() {
		cout << "Base def. ctor \n";
	}
	Base(const Base&) {
		cout << "Base copy. ctor \n";
	}
};

class Der :public Base {

public:


};
int main()
{
	Der m;
	Der m2 = m;
	return 0;
}
```

Türetilmiş sınıfta copy ctor yazmadığımızda derleyici bizim yerimize
Der(const Der& oth):Base(oth)  yazıyor yani Base'in copy ctorunu kullanıyoruz.
Fakat biz kendimiz bir copy ctor yazmak istediğimizde tüm sorumluluk bize geçiyor
```cpp
class Der :public Base {

public:
	Der() = default;
	Der(const Der&)
	{

	}

};
```

Böyle yazdığımızı düşünürsek (ki en büyük hatalardan birisiymiş)
Base def. ctor
Base def. ctor Base sınıfın def. ctoru çağırılır. Bizim copy ctoru çağırmamız gerekiyor.
---

```cpp
	Base(Base&& oth)
	{
		cout << "Move ctor\n";
	}

class Der :public Base {

public:
	Der() = default;


};
	Der m;
	Der m2 = move(m);
```

	Base def. ctor
Move ctor
Copy ctor'da olduğu gibi eğer move ctor yazacaksak derleyicinin yazdığı geçerli olmayacak.
Eğer base move ctoru çağırmazsak def. ctor çağrılır otomatik olarak.
