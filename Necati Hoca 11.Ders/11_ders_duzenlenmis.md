# 11.DERS

```cpp
class Myclass
{
public:
    void foo(); // Myclass*
    void bar() const; // const Myclass*
};

    int getX()const { return mx; }  
    // c-> int getX(const Myclass* this) {return this->mx};

class Myclass
{
public:
    void foo(); // Myclass*
    void bar() const // const Myclass*
    {
        mx = 23;  // parametre geçerken aslında const Myclass* oluyor. O yüzden mx değişkenini değiştiremeyiz.

    }

private:
    int mx_;
};

class Myclass
{
public:
    void foo(); // Myclass*
    void bar() const // const Myclass*
    {
        foo();
        /*
        *  Eğer const bir üye fonksiyon içindeysek, this işaretçisi const Myclass* türündedir.
        * o sebeple const olmayan bir üye fonksiyonu çağırmak istediğimizde derleyici hata verir.
        */

    }

private:
    int mx_;
};

    const Myclass obj; // const Myclass
    obj.bar();
    obj.foo(); // Hata verir çünkü obj const

    Myclass* foo()
    {

        // bu fonk hangi nesne için çağrıldı ise
        // o nesnenin addresini döndürebilir.
        return this;
    }

```

---

```cpp
        Myclass* bar() const
    {
        /*
        * Bu fonksiyon çağrılan nesnenin addresini döndüremez.
        * Sebebi const ile işaretlenmiş olmasıdır.
        * Myclass* ' dan  const Myclass* ' a dönüşüm mümkün değildir.s
        * 
        */
    }
```

---

```cpp
        void func();
    // ben bu fonksiyonu const mı yoksa non-const mı yapmalıyım?
```
## !! ONEMLI SORU

---

```cpp
class Myclass
{
public:
    void func()const
    {
                m_debug_call_count++;
                std::cout << "Debug call count: " << m_debug_call_count << std::endl;
    }

private:
    mutable int m_debug_call_count;
    // mutable anahtar kelimesi, const üye fonksiyonları içinde bile değiştirilebilecek veri üyelerini tanımlamak için kullanılır.
};

```

---

```cpp
class Myclass{};
;
// non-const overload
void foo(Myclass*)
{
    std::cout << "Myclass* called" << std::endl;
}
// const overload
void foo(const Myclass*)
{
    std::cout << "const Myclass* called" << std::endl;
}
int main()                                                                    
{        
    const Myclass obj;
    Myclass obj2;
    foo(&obj);
    foo(&obj2);

}

// ÇIKTI
const Myclass* called
Myclass* called

```

---

```cpp
class Myclass 
{
public:
    void foo();
    void foo()const;
};
```
Burada da bir overload durumu söz konusudur.

---

```cpp
class Myclass 
{
public:
    void foo()
    {
        std::cout << "non-const foo() called" << std::endl;
    }
    void foo()const
    {
        std::cout << "const foo() called" << std::endl;
    }
};

int main()                                                                    
{        
    const Myclass obj;  // const nesne
    obj.foo();

    Myclass obj2; // non-const nesne
    obj2.foo();

}    

const foo() called
non-const foo() called

```
## !! this pointer !!

this-> keyword
```cpp
// this pointer, bir üye fonksiyonun çağrıldığı nesnenin adresini tutan özel bir işaretçidir.

```
this pointerinin olusturdugu ifadenin değer kategorisi
PR value'dur.

Bu da this pointeri atama operatörünün sol tarafında kullanamayacağımız anlamına gelir.

```cpp
class Myclass 
{
public:
    void foo()  // gizli parametre
    {
```
this
```cpp
            // bu fonksiyon hangi nesne için
            // çağrıldı ise o nesnenin adresi

    }

};

void Myclass::foo()
{
    /*
    * İkiside aynı fakat gerekmedikçe this pointer ı kullanmak gereksizdir.
    */
    mx = 5;
    this->mx = 10;
}

/*
* Bu fonksiyon hangi nesne için çağrıldı ise 
* o nesnenin addresini bir free/global fonksiyona göndermek için
*/

```
This kullanımı...

### 1
```cpp
void gfunc(Myclass*);

void Myclass::foo()
{
    gfunc(this);
}

```
### 2
```cpp
void gfunc(Myclass&);

void Myclass::foo()
{
    gfunc(*this);
}

```
### 3

fluent API
```cpp
f.foo().bar();

```
Dikkat bazı özel durumlarda
bir üye fonksiyon hangi nesne için çağrılmış ise
o üye fonksiyonun o nesnenin addresini döndürmesini isteriz.

---

```cpp
    /*
    * Buranın hata olmasının sebebi : 
    * fonksiyon Myclass* döndürüyor fakat
    * this const Myclass* 
    */
    Myclass* foo() const
    {
        return this;
    }

```

---

```cpp
    /*
    * Bu geçerli const Myclass* 
    * dönen const Myclass*
    */
    const Myclass* foo() const
    {
        return this;
    }
```

---

referans döndüren fonksiyonlar için de geçerlidir.

---

ODR ( One Definition Rule ) - Tek Tanım Kuralı)
Bir programda her sınıf, fonksiyon, değişken veya şablonun yalnızca bir tanımı olmalıdır.
```cpp
// Eğer birden fazla tanım varsa, derleyici hata verir.
class Myclass
{
public:
    void foo();
};
```
## !! Declaration değil definition !!
yani
```cpp
int x; 
int x; 
```
hata verir.

```cpp
int foo();
int foo();
```
hata vermez. redeclaration.

```cpp
extern int x;
extern int x; // declaration
```

---

ODR Vialotion

Dikkat
bazı istisnai drumlar söz konusu oldugudnda
ODR violotion olmaz.

token-by-token olursa
birden fazla kaynakta aynı olursa odr vialotion olmaz.

inline fonksiyonlar
inline function ne demek
inline expansion is a compiler optimization

as - if - rule
observable behavior

1) derleyici fonksiyon çağrısının oldugu noktada
çağrıalan fonksiyonun tanımını görmek zorunda

2) Derleyicinin yapacağı analizde i.e yapmanın bir fayda sağlayacağını
görmesi gerekiyor. Yani basit işlemler olması gerekiyor.

```cpp
int Myclass::getX()
{
    return mx; gibi... çok kısa bir işlem yapacak.
}

```
3) derleyici yapabilecek yetenekte olmalı

inline fonksiyonlar
ODR vioalotiona neden olmazlar.

bir sınıfın içinde bir fonksiyonun tanımının
yapılması halinde o fonksiyon inline fonksiyon olur. (Sen inline yazmasan bile)

```cpp
void Myclass::func()
```
diye altta tanımlarsan ODR violotion var.

constepr fonksiyonlar implict inline
örtülü inline ...

neco.h						neco.cpp
```cpp
int foo(int);                    
```