# 22. Ders

```cpp
enum class Weekday {
	Sunday, Monday, Tuesday, Wednesday, Thursday,
	Friday, Saturday
};
```

```text
0
```

```cpp
std::ostream& operator<<(std::ostream& os, const Weekday& wd)
{
	constexpr const char* pdays[] = { "Sunday","Monday",
	"Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return os << pdays[static_cast<int>(wd)];
}
```

```cpp
int main()
{

	Weekday wd(Weekday::Friday);

	std::cout << wd;
}
```

```cpp
Weekday& operator++(Weekday& wd)
{
	using enum Weekday;

	wd = (wd == Weekday::Saturday)
		? Weekday::Sunday
		: static_cast<Weekday>(static_cast<int>(wd) + 1);

	return wd;
}

Weekday operator++(Weekday& wd,int)
{
	auto ret = wd;
	++wd;
	return ret;
}
```

```cpp
int main()
{

	Weekday wd(Weekday::Friday);

	std::cout << wd << '\n';

	++wd;
	wd++;
	std::cout << wd << '\n';



}
```

```cpp
Weekday operator++(Weekday& wd,int)
{
	auto ret = wd;
	++wd;
	return ret;
}
Weekday operator--(Weekday& wd,int)
{
	auto ret = wd;
	--wd;
	return ret;
}
```

---

```cpp
class Myclass
{
public:
    Myclass() = default;
    Myclass(int x) : mx{x} {
        std::cout << "Constructor\n";
	}
    ~Myclass() {
        std::cout << "Destructor\n";
    }


private:
    int mx{};
};
```

```cpp
	Myclass m1{ 22 }, m2{ 33 };

    auto val = m1 + m2;
```

Burası geçersiz çünkü + operatörü Myclass için tanımlı değil.

fakat operator()int için tanımlı olsaydı

```cpp
	auto val = m1( ) + m2( );
	    operator int()const {
        return mx;
	}
	auto val = m1.operator int() + m2.operator int(); // int + int olacaktı
```

---

## Reference qualification

```cpp
// reference qualification 
class Myclass
{
public:
    void foo();

private:
    int mx{};
};
```

```cpp
    /*
    * istiyorum ki foo fonksiyonu
	* l value ile cagrildiginda bir sey yapsin
	* r value ile cagrildiginda baska bir sey yapsin
    */
    Myclass m;
    m.foo();
	Myclass().foo();
	std::move(m).foo();
```

```cpp
void foo()&;  // l value referans ile cagirilinca 
```

sadece l valueler için çağrılabilir.

```cpp
void foo()&&; // r value referans ile çağrılabilir.
```

```cpp
// reference qualification 
class Myclass
{
public:
	void foo()&&
	{
		std::cout << "Myclass::foo r value cagrildi" << std::endl;
	}
	void foo()&
	{
		std::cout << "Myclass::foo l value cagrildi" << std::endl;
	}

private:
    int mx{};
};
    Myclass m;
    m.foo();
	Myclass().foo();
	std::move(m).foo();
```

```text
	Myclass::foo l value cagrildi
Myclass::foo r value cagrildi
Myclass::foo r value cagrildi
```

```cpp
	void foo()const&
	{
		std::cout << "Myclass::foo const l value cagrildi" << std::endl;
	}
```

---

## Namespace

namespace (isim alanı) nedir ?

isimler(idenrifiers)

```cpp
// global namespace

// neco namespace
namespace neco {
	int  x = 42;

}
```

Yani aslında global -> neco -> x

`::neco::x  ...  neco::x`

`::` global namespace i temsil eder.

namespace class ve fonksiyonların içinde tanımlanamaz.

```cpp
namespace erg {
	namespace MyNamespace
	{
		namespace a {
			int x = 100;
		}
	}
}
```

Böyle olabilir .

```cpp
erg::MyNamespace::a::x = 200;
```

```cpp
namespace nec {
	int x = 5;
	void foo();
}

namespace nec {
	int y = 10;
	void bar();
}
```

Namespace ler birleştirilebilir. yani kümülatif toplanır.

Farklı header dosyalarında aynı namespace i açıp
değişik şeyler tanımlayabiliriz.
ve sonunda hepsi tek bir namespace altında toplanır.
Kullanacağımız modulü dahil ederek örneğin nec::adc()
nec::spi() gibi kullanabiliriz.

- `std::vector`
- `std::string`
- `std::list`

- nested namespace
- using declaration  using std::cout gibi.
- using directive		using namespace std; gibi.
- ADL (Argument Dependent Lookup)
- inline namespace
- namespace alias
- unnamed namespace
