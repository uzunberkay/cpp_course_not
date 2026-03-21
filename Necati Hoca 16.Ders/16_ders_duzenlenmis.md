# 16. DERS

---

## move - only

```cpp
class Myclass
{
    public:
        Myclass(Myclass&&);
        Myclass& operator=(Myclass&&);
}

```
- veya

```cpp
class Myclass
{
    public:
        Myclass(const Myclass&) = delete;
        Myclass& operator=(const Myclass&) = delete;
        Myclass(Myclass&&);
        Myclass& operator=(Myclass&&);
}

```
- Conversion Ctor
Donusturen kurucu islev.
- explicit ctor.
- copy elision
- mandatory copy elision
- temporary materialization
- delegating ctor
- Prvalue class objects

## CONVERSION CTOR
- Tipik olarak tek parametreli
- sinif turunden olmayan bir ifadeyi
- bir gecici nesne olustururaak (PR value)
- sinif turune donusturen bir fonksiyon.

---

```cpp
class Myclass {
public:
    Myclass() = default;
    Myclass(int x) :mx(x) {
        std::cout << "Myclass(int x)  = " << x << '\n';
        std::cout << "This = " << this << '\n';
    }
    Myclass& operator=(const Myclass& other) {
        std::cout << "Myclass::operator=(const Myclass&)\n";
        std::cout << "&other = " << &other << '\n';
        mx = other.mx;
        return *this;

    }

private:
    int mx;
};

int main()
{
    Myclass m;
    m = 12;

}

```
- Burada gecici bir nesne olusutuyor 12 icin.
- Aslinda  m = Myclass(12) ; gibi.
Yani assinda (int x ) 'li ctor calisiyor. Ardindan copy assig. calisiyor.

```cpp
Myclass(int x)  = 12
```
This = 00000040FED3F884
```cpp
Myclass::operator=(const Myclass&)
```
&other = 00000040FED3F884

- Cogunlukla istenmez.

---

## temporary objects

---

```cpp
Myclass m ;

Myclass foo();

```
- Eger bir sinif turunden bir  nesneye ihtiyacimiz varsa

```cpp
// C++17 standardina gore PR value olan sinif ifadelleri
```
- artik dogrudan bir nesne degil
- temporary materialization

- temporary materialization olusmasi zorunlu olan durumlar.

```cpp
Myclass m = Myclass(Myclass(Myclass()));

```
- Bir fonksiyonun parametresi bir sinif turundense ve fonksiyonu bir PR value
- arguman ile cagirirsam burada kopyalama yapilmadan  derleyici PR exp.
- dogrudan fonksiyonun parametre degiskenine olusturmak icn kullanicak. Yani bu
- PR value fonksiyonun parametre degiskenini init etmek icin kullanilacak.
- Sadece bir kere ctor cagiracak.

- Dikkat otomatik omurlu bir nesne
- bir fonk.un return ifadesi oluursa
- derleyici burada
- L value to X value
dcnusumu yapmak zorunda.

- Bu ders silindi sistemden ? 2:0:0 da falan kalmistim.