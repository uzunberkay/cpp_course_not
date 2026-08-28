# 19. DERS

OPERATOR OVERLOADING
============================
Friend declarations
Myclass bir sınıf olsun.
Anahtar sözcük.
Normalde diğer kodlar sınıfımızdaki sadece public bölümündeki
isimleri kullanabiliyolar.
Sınıfın private ve protected bölümlerine erişim yok.(Erişim kontrolüne tabii.)
Fakat friend bildirimiyle bir sınıf bazı kodlara private bölüme
erişim hakkı veriyor.
Belirli kodlar ?
i)Bir global fonksiyon için friend bildirimi yapmak. (en çok kullanılan)
ii) Bir başka sınıfın bir üye fonksiyonu için friend bildirimi yapmak (çok seyrek)
iii) bir sınıfın tüm kodları için friend bildirimi yapmak. (2. en cok kull.)
neler yok ?
A sınıfı B sınıfına friendlik vermiş olsun
```cpp
class A{
	friend class B;
}
```

B A ya erişir fakat . A B ye ulaşamaz.
```cpp
class A{
	friend class B;
}
class B{
```

	friend class C
```cpp
}
class C{

}
```

Arkadaşlık bildirimi geçirgen değil.  B - C ye A - B ye friendlik verdi diye
dolayısıyla C - A ya ulaşabilir denmez. Ulaşamaz.
(Babanıızın ya da dedeinizin arkadaşları sizin arkadaşınız mıdır ?)
```cpp
class Base
{
	friend class Nec;
};

class Der:public Base
{

};


class Myclass
{
public:
	friend void gfunc(Myclass);
private:
	void foo();
	int x_{};
};
```

===
```cpp
class Nec
{
```

public :
```cpp
	void bar(int);
};

class Myclass
{
public:
	friend void Nec::bar(int);
private:
	void foo();
	int x_{};
};

void Nec::bar(int x)
{
	Myclass m;
	m.x_ = x;
	m.foo();
}
```

====
```cpp
public:
	friend class Nec;
```

	burada Nec classı için geçerli oluyor.
OPERATOR Overloading
nedir ve ne işe yarar ?
neden var ?
```cpp
struct Nec{

};
```

m1+m2
!m
```cpp
++m

operator functions
```

i1 + i2
i > k
m1*m2
runtime cost
```cpp
	using namespace std;

	string str{ "Berkay" };
	str += " uzun";
```

	+= overloading
```cpp
	Date mydate{ 12,5,1998 };
	Date mydate2{ 12,5,1998 };

	if (mydate == mydate2)
```

	== overloading
pointer - like classes
bir operatör fonksiyonu
	global bir fonksiyon
	bir sınıfın non-static üye fonksiyonu olacak
	bir operatör fonksiyonu bir sınıfın static üye fonksiyonu olamaz.
operandlardan en az birinin bir sınıfı türünden ya da bir enum türden olması gerekiyor.
olmayan bir operatörüm yüklemesi olmaz
overload edilemeyen operatörler var
```cpp
	scope resolution operator		::
```

	member selection dot			.
```cpp
	sizeof operator
	ternary operator				? :
```

	pointer to memnber func			.*
	typeid
	alignof
```cpp
	static_cast
```

	const_cast
	reinterpet_cast
	dynamic_cast
bazı operatörler için yalnızca üye operatör fonksiyonu olusturulabilir.
(global operatör fonksiyonu olamaz)
	atama operatör fonksiyonları
	[] operatör fonksiyonu
```cpp
	-> operatör fonksiyonu
```

	() operatör fonksiyonu
```cpp
	type-cast operator functions;
```

## Operatör Fonksiyonları  Isimlendirilmesi

```cpp
	operator+
	operator<
	operator=
	operator==
	operator!=
	operator->
	operator()

	isimleriyle çağrılabilirler ;

		string s1{ "ali" }, s2{ "can" };
	if (s1 == s2)
	{
		cout << "evet esit \n";
	}
	else
	{
		cout << "hayir esit degil!\n";
	}

	if (operator==(s1, s2))
	{
		cout << "evet esit \n";
	}
	else
	{
		cout << "hayir esit degil!\n";

	}
```

	aynı şey.
```cpp
	cout << "hello world!\n";
	operator<<(cout, "hello world!\n");
```

	aynı şey.
---

	biri haricinde varsayılan argüman alamazlar.
	(/function call op)
```cpp
	bu mekanizmada operatorlerin "arity"si değiştirilemez.
unary operatorler un op. olarak
binary operatorler binary op. olarak
```

overload edilmek zorunda
```cpp
Myclass m1,m2;
```

m1 < m2
```cpp
operator<(m1,m2)


	Myclass m1, m2, m3, m4, m5;

	auto b = m2 * m3 + m4 * m5 > m1;
	auto b2 = ((m2 * m3) + (m4 * m5)) > m1;
	auto b3 = m2.operator*(m3).operator+(m4.operator*(m5)).operator>(m1);
```

	üçü de aynı...
	dilin tanımladığı operatör önceliği değiştirilemez.
```cpp
	operator fonksiyonları da overload edilebilir (function overloading)

```

---

```cpp
class Myclass
{
public:
	Myclass operator*(const Myclass&)const;
	Myclass operator+(Myclass&&)const;
	Myclass operator+(int)const;
	Myclass operator+(double)const;
	Myclass operator+(const char*)const;
};



using namespace std;

int main()
{
	Myclass m1, m2;

	auto r1 = m1 + m2; // 1.
	auto r2 = m1 + Myclass{}; // 2
	auto r3 = m1 + 12; // 3
	auto r4 = m1 + 1.2; // 4
	auto r5 = m1 + "nec"; // 5

}
```

---
