# Necati Hoca 38.Ders

```cpp
explicit speciialization (full specialization)
```

exlicit speciialization
```cpp
template <typename T , typename U , typename int N>
class Myclass {};





int main()
{
	Myclass<int, double, 5> m;


}

template <typename T , typename U , typename int N>
class Myclass
{
public:
	void foo()
	{
		std::cout << "foo\n";
	}
};

template <>
class Myclass <int, double, 5>
{
public:
	void bar()
	{
		std::cout << "bar\n";
	}
	void baz()
	{
		std::cout << "baz\n";
	}

};



int main()
{
	Myclass<int, double, 5> m;
	m.bar();
	m.baz();

	Myclass<int, int, 7> m2;
	m2.foo();


}
```

bar
baz
foo
TMP temlate meta programming
```cpp
templatelerle kod yazma.
```

 compile-time recursion
```cpp
 template<std::size_t N>
struct Factorial
{
	const static std::size_t value = N > 1 ? N * Factorial < N - 1>::value : 1;
};

```

---

```cpp
template<int N>
struct A:A<N-1>
{
	A() {
		std::cout << N << "\n";
	}
};

template<>
struct A<0>
{

};
int main()
{

	struct A<20> a;

}



template <typename T, typename U>
struct Myclass {
```

	static void foo()
```cpp
	{
		std::cout << "Myclass foo\n";
	}
};
template<typename T>
struct Myclass<T,T>
{
```

	static void bar()
```cpp
	{
		std::cout << "Myclass<T,T> bar\n";
	}
};


int main()
{

	Myclass<int, int>::bar();
	Myclass<int, double>::foo();
```

Myclass<T,T> bar
Myclass foo
variable template
```cpp
template <typename T>
constexpr T pi = T(3.1415926535897932385L);

int main()
{
```

	pi<double>
```cpp
}


template <std::size_t base , std::size_t exp>
constexpr std::size_t power = (base * power<base, exp - 1>);
template <std::size_t base>
constexpr size_t power<base, 0> = 1;


int main()
{
	constexpr auto result = power<2, 10>;


}
```

1024
---

alias template
```cpp
template <typename T,std::size_t SIZE>
using Arr = T[SIZE];



int main()
{

	Arr<int, 5> x;
	int x[5];

}

template <typename T>
using gset = std::set<T, std::greater<T>>;



int main()
{

	gset<int> xx;

}
```

member function pointer
object pointers
function pointers
```cpp
class Myclass {
public:
	void foo(int);
};

int main()
{

	void(*fp)(int) = &Myclass::foo; // pointer to member function) =

}
```

Bu yanlış çünkü üye fonksiyon pointer'ları normal fonksiyon pointer'larından farklıdır.
Üye fonksiyon pointer'ları, sınıfın bir nesnesine ihtiyaç duyarlar ve bu nedenle normal fonksiyon pointer'larından farklı şekilde tanımlanır ve kullanılırlar.
Aslında Myclass* ve int parametre gerek.
```cpp
//.*
// ->*
m.*fp(5); // pointer to member function çağırma

class Myclass {
public:
	int foo(int x)
	{
		std::cout << "Myclass::foo(int) called with x = " << x << '\n';
		std::cout << "this pointer: " << this << '\n';
		return x * x;
	}
};

int main()
{

	int (Myclass:: * ptrToMemberFunction)(int) = &Myclass::foo;
	Myclass obj;
	std::cout << "&obj: " << &obj << '\n';

	(obj.*ptrToMemberFunction)(5);


}
```

&obj: 0000000586AFF9F4
```cpp
Myclass::foo(int) called with x = 5
```

this pointer: 0000000586AFF9F4
