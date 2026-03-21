# C++ NOT

## Constructor (Kurucu fonksiyon) (ctor)
- free function olamaaz
- static member function olamaz (non-static member)
- ctor ismi s�n�f ismi ile ayn� olmal�
- const member function olamaz
geri d�n�� de�eri kavram� yok (void function olamaz.)
s�n�f�n public/private/protecteec fonksiyonu olabilir.
Bir s�n�f�n birden fazla ctor'� olabilir
- Yani ctor overload edilebilir.
ctor nitelenmi� isimle yani x.Myclass() ptr->Myclass() �eklinde �a�r�lamaz.

## Destructor (Y�k�c� fonksiyon) (dtor)
### lifespan
- free function olamaaz
- static member function olamaz (non-static member)
- const member function olamaz
geri d�n�� de�eri kavram� yok (void function olamaz.)
dtor s�n�f ismiyle ayn� isim ta��mal� ama ba��nda ~ i�areti olmal�
bir s�n�f�n sadece bir dtor'� olabilir. Parametre de�i�keni olmayacak.
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
    // default constructor �retilmez
    Myclass() {
        std::cout << "Myclass constructor called!" << std::endl;

    }

};
};

```
## Modern C++ ile birlikte herhangi bir fonk.
i�in delete bildirimi yap�labilir.
```cpp
void foo(int) = delete;

/*
* MULAKAT SORUSU
* Dongu kullanmadan 1-100 aras� yazd�r�n.
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
ctor'�n�n s�n�f�n non-static veri elemanlar�n�
init. etmesi �zel bir sentaks ile belirtilir.

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