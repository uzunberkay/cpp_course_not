
# 15. DERS

## Move members

- move ctor  
- move assignment  

Bu fonklar copy ctor ve copy assignmentin bir overloadi.

```cpp
class Myclass{

public:
    Myclass(const Myclass& other); // copy ctor
    Myclass(Myclass&&);  // move ctor

    Myclass& operator=(const Myclass& other); // copy assignment
    Myclass& operator=(Myclass&& other);      // move assignment

}
````

---

## Dikkat

std::move fonksiyonu misnomer yanlış isimlendirilmiş.

aldığı argümanı

L value de olsa R value da olsa

R value ya dönüştürüyor.

```
move(expr)   X value
static_cast<T&&>(expr)
```

move doesn't move...

```
Myclass x;

x -> l value
move(x) -> X value ==> R value
```

---

```cpp
class Myclass {

public:
    Myclass() = default;
    Myclass(const Myclass&) {
        std::cout << "copy ctor\n";
    }
    Myclass(Myclass&&)
    {
        std::cout << "move ctor\n";
    }
};

void foo(const Myclass&)
{
    std::cout << "foo(const Myclass&)\n";
}
void foo(const Myclass&&)
{
    std::cout << "foo(const Myclass&&)\n";
}

int main()
{

    Myclass m;
    foo(m);
    foo(std::move(m));

}
```

```
foo(const Myclass&)
foo(const Myclass&&)
```

Çıktı bu şekilde.

```
foo(static_cast<Myclass&&>(m)); foo(const Myclass&&)
```

bu şekilde de yazabilirim.

---

```cpp
class Myclass {

public:
    Myclass() = default;
    Myclass(const Myclass&) {
        std::cout << "copy ctor\n";
    }
    Myclass(Myclass&&)
    {
        std::cout << "move ctor\n";
    }
    Myclass& operator=(const Myclass&)
    {
        std::cout << "copy assignment\n";
        return *this;
    }
    Myclass& operator=(Myclass&&)
    {
        std::cout << "move assignment\n";
        return *this;
    }
};

void foo(const Myclass&)
{
    std::cout << "foo(const Myclass&)\n";
}
void foo(const Myclass&&)
{
    std::cout << "foo(const Myclass&&)\n";
}

int main()
{

    Myclass m1, m2;
    m1 = m2;
    m1 = std::move(m2);
}
```

```
copy assignment
move assignment
```

çıktısını verir.

---

```cpp
class Myclass {
public:
	Myclass() = default;
	Myclass(const Myclass&)
	{
		std::cout << "copy ctor\n";
	}
};

int main()
{	
	Myclass m1;
	Myclass m2 = std::move(m1);
}
```

burada const' a r ve l value de bağlanabildiği için problem olmuyor.

movedan copye düimek fallback deniyor

---

```cpp
class String {
public:
    String() :mp{ nullptr }, mlen(0) {}
    String(const char* p) :mlen(std::strlen(p)), mp(static_cast<char*>(std::malloc(mlen + 1)))
    {
        std::strcpy(mp, p);
    }
    String(const String& other) :mlen(other.mlen), mp(static_cast<char*>(std::malloc(mlen+1)))
    {
        std::cout << "Copy ctor\n";
        std::strcpy(mp, other.mp);
    }
    String& operator=(const String& other)
    {
        std::cout << "Copy assignment \n";
          if (this != &other)
        {
            mlen = other.mlen;
            free(mp);
            mp = static_cast<char*>(std::malloc(mlen + 1));
            std::strcpy(mp, other.mp);

        }
        return *this;
    }

    String (String&& other) : mp(other.mp),mlen(other.mlen) { 
        std::cout << "Move ctor \n";
        other.mp = nullptr;
        other.mlen = 0;
    }
    String& operator=(String&& other)
    {
        std::cout << "Move assignment\n";
        if (this == &other)
            return *this;

        std::free(mp);
        mp = other.mp;
        mlen = other.mlen;

        other.mp = nullptr;
        other.mlen = 0;

        return *this;
    }
    ~String()
    {
        if (mp)
        {
            std::free(mp);
        }
    }
    void makeupper()
    {
        for (int i = 0; mp[i] != '\0'; ++i)
        {
            mp[i] = static_cast<char>(std::toupper(mp[i]));
        }
    }


    void print()const {
        if (!mp)
        {
            std::cout << "()\n";
        }
            
        else
        {
            std::cout << mp << "\n";
        }
        
    }
    std::size_t length() const
    {
        return mlen;
    }
private:
    size_t mlen;
    char* mp;

};
```

---

```cpp
int main()
{
    String s1{ "Necati ergin c++ anlatiyor.\n" };
    String s2 = std::move(s1);

    s2.print();
    std::cout<<s2.length()<<'\n';
    std::cout<<s1.length()<<'\n';
    s1.print();
}
```

---

```
temporary  object   PR value
String();
String{};
```

```cpp
String str;
str = String{ "Bugun hava guzel" };
```

Mesela burada move assignment çalışıyor.

çünkü PR value.

```
m1=m2  copy assignment
m1 = Myclass{"Alicam"}  move assignment
```

```
Myclass foo();
Myclass& bar();
Myclass&& baz();
```

```
m1 = foo();         move assignment
m2 = bar();         copy assignment
m3 = baz();         move assignment
```

```
std::move(myobject)
Myclass{}
foo()
```

Move assignment yapmak için seçenekler.

---

```
L value
R value (Pr value X value)
```

```cpp
String s1{ "Furkan kizilkoca" };
String s2;

String s3 = std::move(s1);
s2 = std::move(s1);
```

```
moved-from state
```

---

standart kütüphane

kendi türleri için

taşınmış durumdaki nesneler için

```
valid state
```

---

```cpp
void Swap(std::string& s1, std::string& s2)
{
    std::string temp = s1;
    s1 = s2;
    s2 = temp;
}
```

Yukarıdaki swap maliyet açısından korkunç olurdu.

Çünkü her yer için tekrar tekrar bellekten yer alloced et
kopyala vs .

---

Bu swqpta ise direkt kaynak çaldıgı için çok daha hızlı olacak.

```cpp
void Swap(std::string& s1, std::string& s2)
{
    std::string temp = std::move(s1);
    s1 = std::move(s2);
    s2 = std::move(temp);
}
```

---

Moved-from-state

geçerli fakat değeri ne belli değil.

```
(ideali değerin belli olmnası / default ctor edilmiş)
```

kendisine atamaa yapılabilir
kendisine ya da kendisinden taşıma yapılabilir.

---

```cpp
class Myclass {
public:
    Myclass() = default;
    Myclass(const Myclass&)
    {
        std::cout << "Copy ctor\n";
    }
    Myclass(Myclass&&)
    {
        std::cout << "Move ctor\n";
    }
    Myclass operator=(const Myclass&)
    {
        std::cout << "Copy assignment\n";
    }
    Myclass operator=(Myclass&&)
    {
        std::cout << "Move assignment\n";
    }
};

void foo(const Myclass& r)
{
    Myclass m = r;
}
void foo(Myclass&& r)
{
    Myclass m = std::move(r);
}
```

```cpp
Myclass m;
foo(m);
foo(Myclass{});
```

```
Copy ctor
Move ctor
```

---

```
default ctor    dtor    copy ctor   copy ass.   move ctor   move ass.
no spm          e       e           e           e           e         e
Nec(int)        h       e           e           e           e         e
Nec()           user d. e           e           e           e         e
~Nec()          e       user dec.   e(!)        e(!)        not d.    not d.
Nec(const Nec&) not d.  e           user d.     e(!)        not d.    not d.
operator=(...)  e       e           e(!)        user dec.   not d.    not d.
Nec(&&)         not d.  e           deleted     deleted     user d.   not d.
operator=(&&)   e       e           deleted     deleted     not d.    user dec.
```

---
