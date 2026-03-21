# C++ NOT

## Constructor (Kurucu fonksiyon) (ctor)
- free function olamaaz
- static member function olamaz (non-static member)
- ctor ismi sinif ismi ile ayni olmali
- const member function olamaz
- geri donus degeri kavrami yok (void function olamaz.)
- sinifin public/private/protecteec fonksiyonu olabilir.
- Bir sinifin birden fazla ctor'i olabilir
- Yani ctor overload edilebilir.
ctor nitelenmis isimle yani x.Myclass() ptr->Myclass() seklinde cagrilamaz.

## Destructor (Yikici fonksiyon) (dtor)
### lifespan
- free function olamaaz
- static member function olamaz (non-static member)
- const member function olamaz
- geri donus degeri kavrami yok (void function olamaz.)
- dtor sinif ismiyle ayni isim tasimali ama basinda ~ isareti olmali
- bir sinifin sadece bir dtor'i olabilir. Parametre degiskeni olmayacak.
```cpp
   ~Myclass() { }

   class Myclass {
public:
    Myclass() {
        std::cout << "Myclass constructor called!" << std::endl;
    }
};

```
## special member functions
- default ctor
- destructor
- copy constructor
- move constructor
- copy assignment operator
- move assignment operator

```cpp
class Myclass {
public:
    // user - declared constructor
    // default constructor uretilmez
    Myclass() {
        std::cout << "Myclass constructor called!" << std::endl;

    }

};
};

```
Modern C++ ile birlikte herhangi bir fonk.
icin delete bildirimi yapilabilir.
```cpp
void foo(int) = delete;

/*
* MULAKAT SORUSU
* Dongu kullanmadan 1-100 arasi yazdirin.
*/

class Myclass {
public:
    Myclass()
    {
        static int mx = 0;
        std::cout << mx++ << std::endl;
    }
};
int main()
{
    Myclass ar[100];

}

    Myclass m1;        // default initialization
    Myclass m2{};  value init
    Myclass m3(); // function prototype
    Myclass m4(4);    // direct initialization
    Myclass m5{ 5 }; // direct list initialization
    Myclass m6 = 6; // copy initialization

```
ctor'inin sinifin non-static veri elemanlarini
init. etmesi ozel bir sentaks ile belirtilir.

## ctor init list.
- member initializer list deniliyordu.  (mil syntax)

```cpp
class Myclass {
    int mx, my;
};
Myclass::Myclass(): mx(5), my(8)
{
    std::cout << "mx= " << mx << " my=" << my << std::endl;
}
```