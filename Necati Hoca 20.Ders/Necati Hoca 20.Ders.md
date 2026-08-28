# 20. ders

---

yalnızca member op. function olsa idi
global op. function olmasa idi
str + "necati"
neden bir varlığı doğrudan int türü ile
temsil etmek yerşne ayrı bir sınıf türü olusuturp
ona (op. overloading) ağırlıklı bir interface kazandırılaım.
strong type
- istemsiz dönüşümleri engellemek
- işaretli türlerde taşma ub
- işaretli türlerde taşma ub
Dikkat!!
endl bir generic fonksiyon
```cpp
	cout << endl;

	// endl(cout) ...

std::ostream& Mendl(std::ostream& os)
{
	os << '\n';
	os.flush();
	return os;
	// ostream manipulator
}

int main()
{
	using namespace std;


	cout << "ali" << Mendl << "Veli";

}
```

mesela...
```cpp
std::ostream& dashline(std::ostream& os)
{
	return os << "\n -------------------------------------- \n";
}

int main()
{
	using namespace std;


	cout << "ali" << dashline << "Veli" << dashline << "Berkay " << Mendl;

}
```

ali
---

Veli
---

Berkay
```cpp
	friend std::istream& operator>>(std::istream& is, Mint& m)
	{
		return is >> m.mval;

	}



		Mint& operator+=(const Mint& other)
	{
		mval += other.mval;
		return *this;
	}
	Mint m1;
	cout << "Bir sayi girin.";
	cin >> m1;

	Mint m1, m2;
	cout << "Bir sayi girin.";
	cin >> m1 >> m2;
	cout << "M1 = " << m1 << " M2 = " << m2 << "\n";
	m1 += m2;
	cout << m1;
```

	Bir sayi girin.23 45
```cpp
M1 = [23] M2 = [45]
```

[68]
```cpp
	friend Mint operator+(const Mint& lhs, const Mint& rhs)
	{
		return Mint(lhs) += rhs;
	}



	Mint m1{ 3 }, m2{ 4 }, m3{ 5 }, m4{ 6 };

	cout << m1 + m2 + m3 + m4 << '\n';
```

[18]
---

```cpp
class Mint {
public:
	explicit Mint(int val) :mval(val){}
	Mint() = default;
	friend std::ostream& operator<<(std::ostream& os, const Mint& m)
	{

		return os <<'[' << m.mval << ']';
	}
	friend std::istream& operator>>(std::istream& is, Mint& m)
	{
		return is >> m.mval;

	}
	Mint& operator+=(const Mint& other)
	{
		mval += other.mval;
		return *this;
	}
	friend Mint operator+(const Mint& lhs, const Mint& rhs)
	{
		return Mint(lhs) += rhs;
	}

	Mint& operator-=(const Mint& other)
	{
		mval -= other.mval;
		return *this;
	}
	friend Mint operator-(const Mint& lhs, const Mint& rhs)
	{
		return Mint(lhs) -= rhs;
	}
private:
	int mval{};
};
```

---

```cpp
class Mint {
public:
	explicit Mint(int val) :mval(val){}
	Mint() = default;
	friend std::ostream& operator<<(std::ostream& os, const Mint& m)
	{

		return os <<'[' << m.mval << ']';
	}
	friend std::istream& operator>>(std::istream& is, Mint& m)
	{
		return is >> m.mval;

	}
	Mint& operator+=(const Mint& other)
	{
		mval += other.mval;
		return *this;
	}
	friend Mint operator+(const Mint& lhs, const Mint& rhs)
	{
		return Mint(lhs) += rhs;
	}

	Mint& operator-=(const Mint& other)
	{
		mval -= other.mval;
		return *this;
	}
	friend Mint operator-(const Mint& lhs, const Mint& rhs)
	{
		return Mint(lhs) -= rhs;
	}
	friend bool operator<(const Mint& lhs, const Mint& rhs)
	{
		return lhs.mval < rhs.mval;
	}
	friend bool operator>=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs < rhs);
	}
	friend bool operator>(const Mint& lhs, const Mint& rhs)
	{
		return rhs < lhs;
	}
	friend bool operator<=(const Mint& lhs, const Mint& rhs)
	{
		return !(rhs < lhs);
	}
	friend bool operator==(const Mint& lhs, const Mint& rhs)
	{
		return rhs.mval == lhs.mval;
	}
	friend bool operator!=(const Mint& lhs, const Mint& rhs)
	{
		return !(rhs == lhs);
	}

private:
	int mval{};
}


```

---

```cpp
	friend bool operator<(const Mint& lhs, const Mint& rhs)
	{
		return lhs.mval < rhs.mval;
	}
	friend bool operator>=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs < rhs);
	}
	friend bool operator>(const Mint& lhs, const Mint& rhs)
	{
		return rhs < lhs;
	}
	friend bool operator<=(const Mint& lhs, const Mint& rhs)
	{
		return !(rhs < lhs);
	}
	friend bool operator==(const Mint& lhs, const Mint& rhs)
	{
		return rhs.mval == lhs.mval;
	}
	friend bool operator!=(const Mint& lhs, const Mint& rhs)
	{
		return !(rhs == lhs);
	}

C++ 20 ile gelen özellik bunların hepsini şu şekilde tanımlıyor xd
auto operator<=>(const Mint&)const = default;


	cout << boolalpha;
	cout << (Mint(12) == Mint(14)) << '\n';
	cout << (Mint(12) == Mint(12)) << '\n';
```

false
true
bu kadar basit...
```cpp
class Date
{
public:
	Date() = default;
```

	Date(int d, int m, int y) :d_(d), m_(m), y_(y)
```cpp
	{

	}
	auto operator<=>(const Date&)const = default;

private:
	int y_{ 1900 }, m_{ 1 }, d_{ 1 };
};


	cout << boolalpha;
	cout << (Date(3, 5, 1987) < Date(3, 5, 1986));

```

---

```cpp
=====----------------------====----------------===-------==-----=
```

inserter(s)  cout << mydate
```cpp
extractors cin >> mydate;
aritmetik operatorler
```

compound assignment op's
comparison
```cpp
sign operators
```

increment / decrement
```cpp
subscript operator function
```

a[b]
```cpp
*ptr (deref)
ptr->foo()s


```

---

Dersi tekrar izliyorum.
```cpp
	explicit Mint(int ival) :mval(ival)
	{
		/*
		* explicit yapılması implicit dönüşüm yapılmaması için.
		*  Örneğin ;
		* void foo(Mint x)   foo(5) olarak çağrılamıyor artık.
		* Eğer explicit yapmasaydık çağırabilecektik.
		*/
	}

std::ostream& operator<<(std::ostream& os, const Mint& m)
{

	return os << m.getX();
}
Örneğin  artık std::cout << m1; gibi Mint cinsinden direkt yaz-
```

dırabiliyorum.
Bu sanırım class içinde tanımlayamyınca böyle oluyor.
```cpp
	friend std::ostream& operator<<(std::ostream& os,const Mint& m)
	{
		return os << m.mval;
	}
```

	Sınıf içinde tanımlarsam da böyle.
```cpp
	friend std::istream& operator>>(std::istream& is, Mint& r)
	{
		return is >> r.mval;
	}
```

	giriş işlemi yapan da bu.
```cpp
		Mint operator+( const Mint& rhs)
	{
		return Mint(*this) += rhs;
	}

		friend Mint operator+( const Mint& lhs,const Mint& rhs)
	{
		return Mint(lhs) += rhs;
	}
```

	iki şekilde de yazılabilir fakat non-member function olan
	2. tercih edilir.
	1.de sol operand her zaman Mint türünden olmalıdır.
	2.de öyle değildir.
	Zaten member functionlar 1 parametre alır.Diğer parametre this'dir.
```cpp
	m1.operator+(m2) ...
	operator+(m1,m2) ikisinin farkı aslında ?

	<->
	three-way comparasion operator
	spaceship operator


	relational operators
```

	< <= > >=
```cpp
	equality operator
```

	== !=
	a< b
```cpp
	a > b  ==> b<a
	a>=b	==> !(a<b)
	a<=b	==>	!(b<a)
	a!=b	==> !(a==b)


```

---

```cpp
		friend bool operator==(const Mint& lhs, const Mint& rhs)
	{
		return lhs.mval == rhs.mval;
	}
	friend bool operator!=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs == rhs);
	}


	 friend bool operator<(const Mint& lhs, const Mint& rhs)
	 {
		 return lhs.mval < rhs.mval;
	 }
	 friend bool operator>(const Mint& lhs, const Mint& rhs)
	 {
		 return rhs < lhs;
	 }
	 friend bool operator>=(const Mint& lhs, const Mint& rhs)
	 {
		 return !(lhs < rhs);
	 }
	 friend bool operator<=(const Mint& lhs, const Mint& rhs)
	 {
		 return !(rhs < lhs);
	 }
```

---

```cpp
	 Şöyle basit bi şekilde de kuşşanabiliriz ;
	 class Date
{
public:
	Date() = default;
	Date(int d , int m , int y):d_(d),m_(m),y_(y){}

	auto operator<=>(const Date&)const = default;

private:

	int y_{ 1900 }, m_{ 1 }, d_{ 1 };
};

C++20 standartıyla
	cout << boolalpha;
	cout << (Date(12, 07, 87) > Date(12, 07, 97)) << '\n';
	cout << (Date(12, 07, 87) < Date(12, 07, 97)) << '\n';
	cout << (Date(12, 07, 87) != Date(12, 07, 97)) << '\n';
	cout << (Date(12, 07, 87) == Date(12, 07, 97)) << '\n';
	cout << (Date(12, 07, 87) >= Date(12, 07, 97)) << '\n';
	cout << (Date(12, 07, 87) <= Date(12, 07, 97)) << '\n';
```

false
true
true
false
false
true
```cpp
++ op.

	Mint& operator++()
	{
		++mval;
		return *this;
	}
	Mint x{ 333 };
	++x;

x++ için :
	Mint operator++(int)
	{
		Mint temp{ *this };
		++mval;
		return temp;
	}

	Mint x{ 333 };
	++x;
	cout << x;
	x++;
	cout << x;
		friend Mint& operator++(Mint& other)
	{
		++other.mval;
		return other;
	}
	friend Mint operator++(Mint& other,int)
	{
		Mint ret{ other };
		++other;
		return ret;
	}
```

	global yazmak isteyince.
	inserter(s)  cout << mydate
```cpp
	extractors  cin>>mydate;
```

	aritmetik operatörler
	compound assignment op's
	comparison
```cpp
	sign operators
```

	increment/decrement
```cpp
	subscript operator function
```

	a[b]
```cpp
	*ptr   (deref)

	ptr->foo()
```
