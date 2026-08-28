# 32. Ders

---

VTable for Mercedes
---

0		&type_info object for Mercedes
---

1		&Mercedes::start
---

2		&Mercedes::run
---

public inheritance
private inheritance
protected inheritance
```cpp
class Base {
public:

};

// private inheritance
class Der :  Base {
};
```

Taban sınıfın protected kısımı
türemiş sınıfın protected kısmına aktarılır.
```cpp
class Base {
public:
	void f_public();
protected:

	void f_protected();
private:
	void f_private();

};

class Der :  public Base {
public:
	void foo()
	{
		f_public();
		f_protected();
		//f_private(); // error
	}
};
```

private kalıtımında taban sınıfın public ve protected kısımları
türemiş sınıfın private kısmına aktarılır.
Dikkat!
private kalıtımında "client" kodlar için
is - a - relationship geçerli değildir.
Ancak
türemiş sınıfın üye fonksiyonları içinde
türemiş sınıfın friend'lik verdiği kodlar içinde
is- a - relationship geçerlidir.
private kalıtımı (çok büyük çoğunlukla)
	composition
	    alternatifi olarak kullanılır.
```cpp
class A1 {
	int mx{}, my{};

public:
	void foo();

};

class B1 {
	A1 a1x;
	// B1 sınıfının A1 sınıfı türünden bir üyesi var
};

class A2 {
	int mx{}, my{};
public:
	void foo();

};

class B2 :private A2
{

};

int main()
{
	B1 b1;
	B2 b2;

	// b1.foo(); // error sebebi ise B1 sınıfının A1 nesnesinni fonkusyonlarına erişememesi
	// b2.foo(); // error sebebi ise B2 sınıfının A2 sınıfından türemesi private olduğundan dolayıdır. yani erişim kontrolü
	return 0;
}

```

---

 Peki private kalıtımında geçerli olan
  ancak
     containment/composition'da geçerli olmayan neler var ?
elemanımın protected bölümüne erişemem ancak private
kalıtımında  taban sınıfın protected bölümüne erişebilirim.
```cpp
public inheritance ===> is - a  - relationship
private inheritance ===> is implemented in terms of base class




class Empty
{
public:
	void efoo();
	void ebar();
};

class Nec :Empty
{
	int mx;
	void func()
	{
		efoo();
		ebar();
	}
};


int main()
{

	/*
	* Empty sınıfın boyutu 1 dir.
```

---

```cpp
	*sizeof nec: 4sizeof empty: 1
	* private kalıtımı yaptığım için.
```

---

```cpp
	*/
	std::cout << "sizeof nec: " << sizeof(Nec) <<"sizeof empty: " << sizeof(Empty)<< std::endl;



	--
	class Empty
{
public:
	void efoo();
	void ebar();
};

class Nec
{
	int mx;
	Empty m;
	void func()
	{
		m.efoo();
		m.ebar();
	}
};


int main()
{

	/*
	* Empty sınıfın boyutu 1 dir.
```

---

```cpp
	*sizeof nec: 8sizeof empty: 1
	* Empty m nesnesi olusturuldugu için
	* alignment gereği 3 byte padding ekleniyor.
```

---

```cpp
	*/
	std::cout << "sizeof nec: " << sizeof(Nec) <<"sizeof empty: " << sizeof(Empty)<< std::endl;


```

---

```cpp
C++ dilinde attribute'ler var.
```

[[nodiscard]]
[[maybe_unused]]
[[fallthrough]]
[[likely]]
[[unlikely]]]]
a) bazı durumlarda derleyiciye mesajı vermeye teşvik etmek
b) bazı durumlarda derleyiciye mesajı vermemeye teşvik etmek
c) bazı durumlarda derleyiciye  daha etkin optimizasyon yapma olanağı vermek.
```cpp
// EBO Empty Base Optimization




/*
* public kalıtımında taban sınıfın public bölümüne türemiş sınıfın private bölümünde
* public kalıtımında taban sınıfın protected bölümü türemiş sınıf protected bölümüne
*/


/*
* private kalıtımında taban sınıfın public bölümüne türemiş sınıfın private bölümünde
* private kalıtımında taban sınıfın protected bölümü türemiş sınıf private bölümüne
*/


/*
* protected kalıtımında taban sınıfın public bölümüne türemiş sınıfın protected bölümünde
* protected kalıtımında taban sınıfın protected bölümü türemiş sınıf protected bölümüne
*/
```

private kaltımından taban sınıfın public bölümü
türemiş sınıfın private bölümüne eklendişği için
türemişsınıftan tekrar kalıtım yapıldıgında yeni türetilen sınıf traaban sınıfın private bölümüne erişemez.
Çoklu kalıtım
multiple inh.
```cpp
class Base1 {

};

class Base2 {


};

class Der :public Base1, public Base2 {

};


class Base1 {
public:
	void foo();
};

class Base2 {
public:
	void bar();

};

class Der :public Base1, public Base2 {

};

int main()
{

	Der myder;
	myder.foo();
	myder.bar();
	return 0;
}

```

---

```cpp
class Drawable {
public:
	virtual void draw() = 0;
};

class Printable {
public:
	virtual void print() = 0;
};

class Der : public Drawable, public Printable {
public:
	void draw()override;
	void print()override;
};


void foo(Drawable& dr);
void bar(Printable& pr);


	Der myder;
	foo(myder);
	bar(myder);
```

	 mixin class ....
---

Eğer  birden fazla taban sınıftan
aynı isim gelirse
bu isimlerin aranmasında bir öncelik sonralık ilişkisi yoktur.
A::foo()  // Base1::foo()'u çağırır
B::foo()  // Base2::foo()'u çağırır
Diomand formation
```cpp
// DDD formation

// deathful diamond of derivation
// dradful diamond of derivation

class Base {

};

class Der : public Base {};
class Mer : public Base {};

class Nec:public Der,public Mer{};


class Base {

	int mx{};

};

class Der : public Base {};
class Mer : public Base {};

class Nec:public Der,public Mer{};


	constexpr auto sz1 = sizeof(Base);  // 4
	constexpr auto sz2 = sizeof(Der);  // 4
	constexpr auto sz3 = sizeof(Mer);  // 4
	constexpr auto sz4 = sizeof(Nec);  // 8


class Base {
public:

	void foo();
};

class Der: public Base {
};
class Mer:public Base {
};
class Nec: public Der,public Mer {
};

int main()
{
	Nec mynec;
	mynec.foo();  // Hangi foo çağırılacak ? Der mi Mer mi ?  C++ bunu bilemez. Bu yüzden hata verir. ambuguity (belirsizlik) hatası verir.

	mynec.Der::foo(); olur
	return 0;
}


```

---

	Teklrar
VTable for Mercedes
---

0		&type_info object for Mercedes
---

1		&Mercedes::start
---

2		&Mercedes::run
---

private - protected inheritance
multiple inheritance
```cpp
class Base {
public:
	void f_public();
protected:
	void f_protected();
private:
	void f_private();

};

class Der :public Base {

public:
	void foo()
	{
		f_public();
		f_protected();
	}
};

```

---

```cpp
class Base {
public:
	void f_public();
protected:
	void f_protected();
private:
	void f_private();

};


// private kalıtımında taban sınıfın public ve protected bölümü türemiş sınıfın
// private kısmına ekleniyor.
class Der :private Base {

public:
	void foo()
	{
		f_public();
		f_protected();
	}
};
```

Dikakt!
private kalıtımında "client" kodlar için
is-a-releationship yok
Ancak
türemiş sıbnıfın üye fonksiyonları içinde
türemiş sınıfın friendlik verdiği kodlar içinde
geçerli
privatte kalıtımı (çok bütyük çoğunlukla)
	composition
	alternatifi oalrak kullanılır
Peki,
private kalıtımında geçerli olan
ancak
 containment/composition da geçerli olmayan neler var ?
 elemanımıon protected bölümüne erişemem
 anck private kaltımında taban sınıfın protected bölümüne erişebilirimç.
```cpp
// EBO
// empty base optimization


class Nec
{

};



int main()
{
	std::cout << "sizeof(Nec)= " << sizeof Nec<<'\n';

	return 0;
}
```

1
```cpp
class Empty {

	public:
		void efoo();
		void ebar();
};


class Nec {
	Empty ex;
};





int main()
{
	std::cout << "sizeof(Empty)= " << sizeof Empty <<'\n';
	std::cout << "sizeof(Nec)= " << sizeof Nec<<'\n';

	return 0;
}
```

sizeof(Empty)= 1
sizeof(Nec)= 1
```cpp
int main()
{
	std::cout << "sizeof(Nec)= " << sizeof Nec<<'\n';

	return 0;
}
```

1
```cpp
class Empty {

	public:
		void efoo();
		void ebar();
};


class Nec {
	Empty ex;
	int x;

};





int main()
{
	std::cout << "sizeof(Empty)= " << sizeof Empty <<'\n';
	std::cout << "sizeof(Nec)= " << sizeof Nec<<'\n';

	return 0;
}
```

sizeof(Empty)= 1
sizeof(Nec)= 8
private kalıtımı yaparajk 4 e düşürcem.
```cpp
class Empty {

	public:
		void efoo();
		void ebar();
};


class Nec:private Empty {
	int mx;
	void func()
	{
		efoo();
		ebar();
	}
};





int main()
{
	std::cout << "sizeof(Empty)= " << sizeof Empty <<'\n';
	std::cout << "sizeof(Nec)= " << sizeof Nec<<'\n';

	return 0;
}
```

sizeof(Empty)= 1
sizeof(Nec)= 4
:
```cpp
C++ dilinde attribute
```

[[nodiscard]]
[[fallthrough]]
a) bazı durumlarda derleyiciye uyarı mesajı vermeye teşvik etmek
b) bazı durumlarda derleyiciye uyarı mesajı vermemeye teşvik etmek
c) bazı durumlarda derleyiciye daha etkin optimizasyon yapma olanağıo vermek
---

Restricted polymorphism
Tüm fonksiyonlara değil, yalnızca seçilmiş olanlara (f1) virtual dispatch + Base referansına dönüşüm izni vermek.
Bunu sağlamak için:
Der, Base’den private inheritance ile türetilir
Bu yüzden Der → Base dönüşümü dışarıya kapalıdır
```cpp
Sadece friend void f1(); sayesinde f1 bu dönüşümü yapabilir
```

foo(Base&) fonksiyonu virtual çağrı yapar
f2 ve f3 derleme hatası verir
f2 ve f3 derleme hatası verir
```cpp
#include <iostream>

class Base {
public:
    virtual void vfunc() {
        std::cout << "Base::vfunc\n";
    }

    virtual ~Base() = default;
};

class Der : private Base {
    void vfunc() override {
        std::cout << "Der::vfunc\n";
    }

    // Sadece f1 Base'e dönüşümü yapabilsin
    friend void f1();
};

// Base referansı üzerinden virtual dispatch
void foo(Base& baseref)
{
    baseref.vfunc();
}


// ✔ İzin verilen fonksiyon
void f1()
{
    Der myder;
    foo(myder);   // OK — f1, Der'in friend'i
}


// ✖ İzin verilmeyen fonksiyonlar
void f2()
{
    Der myder;
    // foo(myder);   // DERLEME HATASI:
                     // Base, Der'in private base'i
}

void f3()
{
    Der myder;
    // foo(myder);   // DERLEME HATASI
}


int main()
{
    f1();   // Çalışır, Der::vfunc çağrılır

    // f2(); // açarsan compile error
    // f3();

    return 0;
}

```

---
