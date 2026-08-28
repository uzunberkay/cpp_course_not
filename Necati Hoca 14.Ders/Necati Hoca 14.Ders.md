# 14. Ders

```cpp
class Nec{
public:
	Nec():ax(),bx(),cx(){}
	~Nec : {cx.~Nec(), bx.~Nec() , ax.~Nec()}
	Nec(const Nec& other);  / /Fighter f1 ;  Fighter f2 = f1; copy ctor.

private:
	A ax;
	B bx;
	C cx;

}

class Myclass {

public:
	Myclass() = default;
	Myclass(const Myclass& other)
	{
		std::cout << "this = " << this << " Other = " << &other << std::endl;
	}
};


int main()
{

	Myclass m1;
	Myclass m2 = m1;
	Myclass m2(m1);
	Myclass m2{m1};

	m2 = m1 copy assignment

}
```

==
Bir sınıfın her zaman copy ctor vardır.
	imlicitly declared
	user declared
	====
```cpp
	class Myclass {

public:
	Myclass(int x = 0, int y = 0, int z = 0) :mx(x), my(y), mz(z){}
	void print()
	{
		std::cout << "x : " << mx << " y : " << my << " mz : " << mz << '\n';
	}
private:
	int mx, my, mz;
};


int main()
{

	Myclass m1(2,3,4);
	Myclass m2 = m1;

	m2.print();

}
```

sen hiç copy ctor yazmasan da derleyici senin için yazıyor aynı parametreleri birbirine
kopyalıyor.
```cpp
Nec(const Nec& oth):mx(oth.mx),my(oth.my),mz(oth.mz){}
```

böyle yazıyo gibi düşün.
Rule of zero  (sıfır kuralı)
	default ctor
	öyle sınıflar var ki (olacak ki)
	kopyalanması istenmeyecek
```cpp
	class Myclass {
    Myclass() = default;
    Myclass(const Myclass&) = delete;
    Myclass& operator=(const Myclass&) = delete;
};
```

handle
```cpp
String str = "Ramazan Kasim Arikan"
```

,
value type
```cpp
x=y
```

memberwise copy
shallow copy
Örneğin bir string değer için copy ctor
tamamen nesneyi kopyalarsa
addreside yani this'ide kopyalar
bu durumda dinamik olarak olusturulan ilk nesne destructor
çalıştığında kopyalanmış nesne de dangling pointer olacaktı.
Bu sebeple copy ctor daha farklı şekilde yapılmalı.
deep copy...
====
```cpp
class String {
public:
    String():mp{nullptr}, mlen(0){}
    String(const char* p) :mlen(std::strlen(p)), mp(static_cast<char*>(std::malloc(mlen + 1)))
    {
        std::strcpy(mp,p);
    }
    void print()const {
        std::cout << mp << "\n"
            ;
    }
```

    ~String()
```cpp
    {
        if (mp)
        {
            std::free(mp);
        }
    }
private:
    size_t mlen;
    char* mp;

};


int main()
{
    String s1{ "Hakan Eryaman" };
    s1.print();

}
```

Eğer copy ctoru derleyiciye bırakırsam yukarıdaki kodda sıkıntı (ub) çıkıyor.
```cpp
    void makeupper()
    {
        for (int i = 0; mp[i] != '\0'; ++i)
        {
            mp[i] = static_cast<char>(std::toupper(mp[i]));
        }
    }
private:
    size_t mlen;
    char* mp;

};

void foo(String s)
{
    s.print();
}


int main()
{
    String s1{ "Hakan Eryaman" };
    String s2 = s1;
    s1.print();
    s1.makeupper();
    s2.print();

}
```

Burada s1 'i büyütüyorum sonra s2yi bastırıyorum.
Hakan Eryaman
HAKAN ERYAMAN
s2 copy ctor ile olusunca direkt addres kopyalandı yanii s1 i değiştirirken s2 de değişmiş oldu
işte bu yüzden ben copy ctoru derleyiciye bırakamam.
String(const String& other) :mlen(other.mlen),mp(other.mp) derleyici böyle yazıyor copy ctoru
===
```cpp
    String(const String& other) :mlen(other.mlen) ,mp(static_cast<char*>(std::malloc(mlen+1))){
        std::strcpy(mp, other.mp);
    }
```

    === Ben böyle tanımlamam gerekli.
=============================================
Copy assignment
```cpp
class Myclass {

public:
	Myclass& operator=(const Myclass& other);
};

	Myclass m1, m2;
	m1 = m2;
```

    Bu durumda kullanılır.
ya user-declared olacak
ya da implicit declared olacak.
```cpp
	Myclass& operator=(const Myclass& other)
	{
		ax = other.ax;
		bx = other.bx;
		cx = other.cx;

		return *this;
	}
```

	derleyici böyle yazıyor.
	Aynı sebeplerden copy assignmentide kendimiz yazıcaz.
```cpp
    String& operator=(const String& other)
    {
        mlen = other.mlen;
        free(mp);
        mp = static_cast<char*>(std::malloc(mlen + 1));
        std::strcpy(mp, other.mp);

        return *this;


    }
```

    böyle yazmak gerekecek.
    destructor
        free resources
    copy ctor
        deep copy
    copy assignment
        free resourves
        deep copy
============================================================
```cpp
Myclass(const Myclass&)-> copy ctor
Myclass(Myclass&&)     -> move ctor
```

overload...
```cpp
Myclass& operator=(const Myclass&)  -> copy assignment
Myclass& operator=(Myclass&&)       -> move assignments
```

============================================================
