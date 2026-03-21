# 17. DERS

---

## Delegating ctor

- birden fazla ctor var ve bu ctor'larin ortak bir kodu var.

## Siniflarin static veri elemanlari  ve static uye fonksiyonlari

---

```cpp
//myclass.h
class Myclass {

    static int mx;
};

// myclass.c
int Myclass::mx = 10;

//myclass.h
class Myclass {
    int mx{};
    static int x;
    static int y;
    static int z;
};

// myclass.c

int main()
{

    using namespace std;

    constexpr auto sz = sizeof(Myclass);

    cout << sz;

}

```
- Cevap : 4 ;

global degiskenler yersne
siniflarin static veri elemanlari kullaniyoruz (bazen)

```cpp
class Myclass {
public:
    static int s;
};

int Myclass::s;

int main()
{

    Myclass m1, m2, m3;
    m1.s = 5;
    m2.s++;
    m3.s *= 2;
    std::cout << "  S  =  " << Myclass::s << '\n';
}
```
S  =  12
- Yani Myclass sinifinin elemanlarinin ortak bir global degiskeniymis gibi...

---

```cpp
class Myclass {

public:
    static int ms;
    static int g;
};
int Myclass::g = 21;
int g = 10;

int Myclass::ms = g;

int main()
{
    /*
    * !!! BU BIR MULAKAT SORUSU !!!
    * MS CIKTISI NEDIR ?
    * Cevap : 21.
    * Isim aramasi ilk class scope'da yapiliyormus.
    * o yuzden classdaki g yi aliyor.
    * int Myclass::ms = ::g; yapsaydik , :: ile global g yi alacaktik.
    */
    std::cout << "MS = " << Myclass::ms << '\n';
}

```

---

## Siniflarin static uye fonksiyonlari

- Sinifin genel fonksiyonudur. Yani this falan kullanilamaz.

- 1) ctor/dtor static uye fonk. olamaz
- 2) operator fonksiyonlari (special / non special) static uye fonksiyon olamaz.
- 3) Sanal fonksiyonlar static olamazlar.

```cpp
[
        class Fighter {
    public:
        Fighter(const std::string& name):name_(name)
        {
            fighters.push_back(this);
        }
        ~Fighter()
        {
            std::erase(fighters, this);
        }
        void ask_help();
    private:
        std::string name_;
        inline static std::vector<Fighter*> fighters;

    };

    int main()
    {
        Fighter f1("necati");
        Fighter f2("furkan");
        Fighter f3("gizem");
        Fighter f4("ogulcan");

        f3.ask_help();

    }
    ]

```
- scope leakage (kapsam sizintisi) idientiifiers

- bir isim yalnizca o ismin kullanildigi kod alaninda bilinsin disinda bilinmesin.

