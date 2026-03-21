# 13. ders

## default ctor.

## special member functions

- default ctor
- destructor

- copy ctor
- move ctor
- copy assignment
- move assignment

- Digerlerinden ayiran ne ?
Bazi kosullar saglandigi zaman derleyici tarafindan otomatik olusturulurlar.

- derleyici bunlarin kodlarini yazabiliyor.
- implicitly declare ==> default

- user declared

- default ctor
- move ctor
- move assignment  olmayabiliyor.

- move ctor
- move assignment
- Move members of a class (move ctor / move assignment)
- copy members of a class (copy ctor / copy assignment)

## constructor initializer list
## member initializer list

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
    MyClass() : x_(0), d_(3.4)
    {

    }
private:
    int x_;
    double d_;

};

```
- Boyle init edebiliyorum.

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

```
- Burada  hayata gelis sirasi 	int mx_;
```cpp
    int my_; buradaki siraya gore. Yani mx_ my_den once init edilecek.
```
- Ve mx_ my_ kullanilarak init edildigi icin my_ hayata gelmedigi icin hata vermez fakat
- UB (undefined behavior) olusur.) cunku my_ init edilmeden kullanilmis olur.
- my_ garbage deger alir.
```cpp
class Nec {
public:
    Nec(int x, int y) :my_(x), mx_(my_*x) {}
private:
    int mx_;
    int my_;
};

```
## C-like C++
- Dil cpp ama aliskanlik c.

```cpp
class MyClass
{
public:

/*
```
Burada  iki farkli yazilimci var.
Birincisi initializer list kullanmis.
Ikincisi ise constructor body icinde atama yapmis.
Ikincisi istemedigimiz bir yazilimci yani C-like C++ yazilimcisi.

```cpp
*/
    MyClass() : ax(exp1),bx(exp2)
    {
    }
    MyClass()
    {
    // Oncelikle default init etmis oluyosun. Ardindan atama yapiyosun ???
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
- default member init.
```cpp
    int mx = 5;  boyle tanimlayinca derleyici ctoru default olarak yukaridaki gibi tanimlar.
}

class MyClass
{
public:
    Myclass() :mx(5) {}
private:
```
- default member init.
```cpp
    int mx{4} ; gecerli
    int mx = 4; gecerli
    int mx(4); gecersiz

    class Point {
public:
    Point() = default;  // derleyici default ctoru senin yazmani istiyorum.
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
## RAII
- Resource Acquisition Is Initialization (Kaynak edinimi ilk deger verme yoluyla olur)

## special member functions

- default ctor
- destructor

- move ctor
- move assignment

- copy ctor
- copy assignment

- Myclass(int) bu turden ctorlar user declared special member function degildir.
- yani derleyici tarafindan olusturulamaz.
- yani
```cpp
Myclass(int) = default;  bu gecersizdir. !!!!!!!!!!!!!!!!!!!

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
## COPY CTOR

```cpp
Myclass m1; default ctor
Myclass m2 = m1; copy ctor
Myclass m3(m1); copy ctor
Myclass m4{m1}; copy ctor

```
- Bir sinifin copy ctoru bildirilmis olmak zorunda

- not-declared (special member function yok)
- user-declared (programci tarafindan bildirilmis)

```cpp
//user declared

class Myclass {
public:
    Myclass();  // user - declared
    Myclass() = default; // user - declared
    Myclass() = delete; // user - declared
};

```
Derleyicinin bir sinifin bir special member function'i nasil
- default edecegi yani onun kodunu nasil yazacagi belirlidir.
- (dilin kurallari var)

- Bu kurallara gore derleyici bir sinifin sp.mem.func.'ini
default ederken dilin kurallarini cigneyen bir durum olusursa
- derleyici default etmesi gereken fonksiyonu deleted oalrak bildirir.
