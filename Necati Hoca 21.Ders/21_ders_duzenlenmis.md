# 21.DERS|

---

```cpp
    vector vec{ 2,5,7,9,3 };

    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec.operator[](i) << vec[i] << '\n';
    }

```
- Iki gosterimde ayni aslinda.

- std::vector
- std::string
- std::deque
- map
- array

```cpp
    class Darray
{
public:
    Darray(std::size_t size) :msize(size),mp(new int[size])
    {
        std::memset(mp, 0, size * sizeof(int));
    }
    Darray(std::size_t size, int val) :msize(size), mp(new int[size])
    {
        for (size_t i = 0; i < size; i++)
        {
            mp[i] = val;
        }
    }
    ~Darray()
    {
        if (mp)
        {
            std::cout << "Destructor\n";
            delete[] mp;
            msize = 0;
        }
    }
    int& operator[](std::size_t idx)
    {
        return mp[idx];
    }
    const int& operator[](std::size_t idx)const
    {
        return mp[idx];
    }
    std::size_t size()const {
        return msize;
    }

private:
    std::size_t msize;
    int* mp;
};

    Darray x(10,3);
    const Darray cx(10, 20);

    x[3] = 23;  // non - const veri atanabilir
    cx[2] = 11; // cost veri atanamaz.

```
- Bunu da
```cpp
        int& operator[](std::size_t idx)
    {
        return mp[idx];
    }
    const int& operator[](std::size_t idx)const
    {
        return mp[idx];
    }

```
- const overloading ile yapiyorum.

---

- dereferencing
```cpp
    *

```
- member selection arrow
->

overload edilmesi var.

- oyle bir sinif olsun ki
- nesneleri std::string sinifi turunden
- dinamik omurlu nesnelerin hayatlarini kontrol
- edecek pointer'lar gibi davransin.
- sinifimizin ismi string_ptr olsun.

- ptr-> b    (*ptr).b

- Dikkat!
- ok operatoru 2 operand alan bir operator olmasina karsin
- unary operator olarak overload edilir.

ptr->foo()
ptr.operator->()->foo()

```cpp
    template <typename T>
class smartptr
{
public:
    smartptr() = default;
    smartptr(T* p) :mp(p) {}
    ~smartptr()
    {
        if (mp)
            delete mp;

    }
    smartptr(smartptr&& other) :mp(other.mp)
    {
        other.mp = nullptr;
    }
    smartptr& operator=(smartptr&& other)
    {
        delete mp;
        mp = other.mp;
        other.mp = nullptr;
        return *this;
    }

    bool has_object()const {
        return mp != nullptr;
    }
```
T& operator*()
```cpp
    {
        return *mp;
    }
```
T* operator->()
```cpp
    {
        return mp;
    }

private:
    T* mp{ nullptr };

};

int main()
{
    using namespace std;
    {

        smartptr<string> p1(new string{ "selami karakelli" });
        cout << *p1 << '\n';
        smartptr<Mint> p2(new Mint{ 345 });
        cout << *p2 << '\n';
        smartptr<int> p3(new int{ 7564 });
    }

}

```
- C++ generic programlama ile verilene  cpp sonsuz adet bu templateden bizim icin
- olusturabilir.

---

## 21. ders tekrar

```cpp
class Darray {
public:
    Darray(std::size_t size) :msize(size),mp(new int[msize])
    {
        std::memset(mp, 0, msize*sizeof(int));
        std::cout << "Darray(std::size_t size)\n";
    }
    ~Darray()
    {
        delete[] mp;
        std::cout << "Destructor\n";
    }
    int& operator[](std::size_t idx)
    {
        return mp[idx];
    }
    std::size_t size()const {
        return msize;
    }
private:
    std::size_t msize;
    int* mp;

}

    Darray x(10);
    for (size_t i = 0; i < x.size(); i++)
    {
        cout << x[i] << x.operator[](i)<< '\n';
    }
    for (size_t i = 0; i < x.size(); i++)
    {
        x[i] = i;

    }
    for (size_t i = 0; i < x.size(); i++)
    {
        cout << x[i] << '\n';
    }

```

---

```cpp
        int& operator[](std::size_t idx)const
    {
        return mp[idx];
    }

    const Darray x(10);

    for (size_t i = 0; i < 10; i++)
    {
        x[i] = i;
    }
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << x[i] << '\n';
    }

```
- Const olmasina ragmen deger atabiliyorum ?

```cpp
        const int& operator[](std::size_t idx)const
    {
        return mp[idx];
    }
```
- Boyle yaparsam da sadece read-only ...
- o yuzden overload etmem gerek.

---

```cpp
     int& operator[](std::size_t idx)
    {
        return mp[idx];
    }
     int operator[](std::size_t idx)const {
         return mp[idx];
    }
```

---

- overload edince eger sadece
- const nesneler icin const
- non-const olan nesneler icin non-const

- dereferencing
```cpp
*

```
- member selection arrow
->

```cpp
*ptr

```
ptr->foo()
(*ptr).foo()
ptr->mx
(*ptr).mx
a
```cpp
*ptr

```

---

- Dikkat!
- ok operatoru 2 operand alan bir operator olmasina karsin
- unary operator olarak overload edilir.

---

- Global op. olamaz.

```cpp
        std::string* operator->()
    {
        return mp;
    }
```
- Olay su :

- sptr->lenght() mesela length std::string e ait bir fonksiyon degil mi ?
- -evet
- O zaman ben  std::string* yani bir string addresi dondurmem gerek ->

- std::string* operator->() yani -> operatorle bir string addresi dondurmem gerek.

```cpp
    std::string* operator->()
    {
        return mp;  // mp'nin kendisini dondurmem gerek
    }
```
- cout << sptr->length();

---

```cpp
/*
* simdi stringptr sinifini move only
* type yapalim
* yani kopyalamaya kapali tasimaya acik
*/

struct A {

    void foo();
};

struct B {
    B(A);
    void bar();
};

int main()
{
    // most vexing parse

    // burada aslinda b turunden bx degiskeninin olusturmak
    // istiyorum fakat . 'most vexing parse'  Geri donusu
    // b olan bx fonksiyonu olarak tanimliyor.
    B bx(A());

```
- Legal olan yapilar:
```cpp
    {} kullandiginda fonk. tanimi olma ihtimali yok.
    B bx{ A() };
    B bx( A{} );
    B bx{ A{} };
    B bx((A()));  --> oncelik parantezi !!

```
## Type-cast operator functions
tur donusturme operatoru

(target_type)
(int)dval

```cpp
    int x = 5;
    Myclass m;
    x = m;

```
Bunu yapamiyoruz.

```cpp
    /*
    * geri donus degeri yazilmayacak. (kural)
```
- yazilsa idi int operator int()const gibi kendini
- tekrar eden bir yapi olacakti. Bu istenmemis ve kural koyulmus.
```cpp
    */
```
operator int() const
```cpp
    {
        std::cout << "operator int() const\n";
        return 42;
    }

        int x = 5;
    Myclass m;
    x = m;

    std::cout << x; artik legal

```
- conversion ctor
- conversion sequence

- std conv + udc
- udc + std conv
- std conv. + std conv. olmuyor.!!!!

```cpp
         double y;
    y = m;

```
- int icin donusum ekledim fakat double 'da oluyor ?
- BUnu kaldirmak icin explicit eklemek gerek :
explicit operator int() const
```cpp
    {
        std::cout << "operator int() const\n";
        return 42;
    }

    Myclass m;
    int x = static_cast<int>(m);
```
- artik boyle donusum yapacak.

- overload da edilebilir.

- if(expr)
- while(expr)
- do while(expr)
- for(expr)

## function call operator function

```cpp
    Myclass m;
    m();
    //m.operator()();

    void operator()()
    {
        std::cout << "Myclass operator()()\n";
        std::cout << "this: "<< this <<'\n';
    }
Myclass operator()()
```
this: 0000005BDAD6F804

