# 19. DERS
## OPERATOR OVERLOADING

---

## Friend declarations

- Myclass bir sinif olsun.
- Anahtar sozcuk.
- Normalde diger kodlar sinifimizdaki sadece public bolumundeki
isimleri kullanabiliyolar.
- Sinifin private ve protected bolumlerine erisim yok.(Erisim kontrolune tabii.)
- Fakat friend bildirimiyle bir sinif bazi kodlara private bolume
- erisim hakki veriyor.
- Belirli kodlar ?

- i)Bir global fonksiyon icin friend bildirimi yapmak. (en cok kullanilan)
- ii) Bir baska sinifin bir uye fonksiyonu icin friend bildirimi yapmak (cok seyrek)
- iii) bir sinifin tum kodlari icin friend bildirimi yapmak. (2. en cok kull.)

- neler yok ?

A sinifi B sinifina friendlik vermis olsun

```cpp
class A{
    friend class B;
}

```
B A ya erisir fakat . A B ye ulasamaz.

```cpp
class A{
    friend class B;
}
class B{
    friend class C
}
class C{

}

```
- Arkadaslik bildirimi gecirgen degil.  B - C ye A - B ye friendlik verdi diye
dolayisiyla C - A ya ulasabilir denmez. Ulasamaz.
(Babaniizin ya da dedeinizin arkadaslari sizin arkadasiniz midir ?)

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

---

```cpp
class Nec
{

public :

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
- burada Nec classi icin gecerli oluyor.

OPERATOR Overloading
- nedir ve ne ise yarar ?
- neden var ?

```cpp
struct Nec{

};

```
m1+m2
!m
++m

```cpp
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

- pointer - like classes

- bir operator fonksiyonu
global bir fonksiyon
bir sinifin non-static uye fonksiyonu olacak
- bir operator fonksiyonu bir sinifin static uye fonksiyonu olamaz.

- operandlardan en az birinin bir sinifi turunden ya da bir enum turden olmasi gerekiyor.
- olmayan bir operatorum yuklemesi olmaz

- overload edilemeyen operatorler var
```cpp
    scope resolution operator        ::
```
member selection dot			.
- sizeof operator
ternary operator				? :
pointer to memnber func			.*
- typeid
- alignof
- static_cast
- const_cast
- reinterpet_cast
- dynamic_cast

- bazi operatorler icin yalnizca uye operator fonksiyonu olusturulabilir.
- (global operator fonksiyonu olamaz)

- atama operator fonksiyonlari
- [] operator fonksiyonu
- -> operator fonksiyonu
- () operator fonksiyonu
- type-cast operator functions;

- - operator fonksiyonlari  isimlendirilmesi -
- operator+
- operator<
- operator=
- operator==
- operator!=
- operator->
- operator()

- isimleriyle cagrilabilirler ;

```cpp
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
- ayni sey.
```cpp
    cout << "hello world!\n";
    operator<<(cout, "hello world!\n");
```
- ayni sey.

-------------
- biri haricinde varsayilan arguman alamazlar.
(/function call op)
- bu mekanizmada operatorlerin "arity"si degistirilemez.
- unary operatorler un op. olarak
- binary operatorler binary op. olarak
- overload edilmek zorunda

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
- ucu de ayni...

- dilin tanimladigi operator onceligi degistirilemez.

- operator fonksiyonlari da overload edilebilir (function overloading)

----------------

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
--------------------------------------------------------------------
