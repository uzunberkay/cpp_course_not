# Necati Hoca 40.Ders


---

```cpp
template<typename T>
constexpr std::size_t SZ = sizeof(T)

template<>
constexpr  std::size_t SZ<void> = 0;





```

---

```cpp
class Myclass {};

void foo(Myclass&)
{
	std::cout << "Myclass&\n";
}


void foo(const Myclass&)
{
	std::cout << "const Myclass&\n";
}


void foo(Myclass&&)
{
	std::cout << "Myclass&&\n";
}


void foo(const Myclass&&)
{
	std::cout << "const Myclass&&\n";
}


int main()
{
	Myclass m;
	const Myclass cm;


	foo(m);
	foo(cm);


	foo(std::move(m));
	foo(std::move(cm));





}
```

Myclass&
```cpp
const Myclass&
```

Myclass&&
```cpp
const Myclass&&



void call_foo(Myclass& mr)
{
	foo(mr);
}


void call_foo(Myclass&& mr)
{
	foo(std::move(mr));
}

void call_foo(const Myclass& mr)
{
	foo(mr);
}
void call_foo(const Myclass&& mr)
{
	foo(std::move(mr));
}
```

1:04 de kaldım
---

```cpp
template <typename T>
void call_foo(T&& x)
{
	foo(std::forward<T>(t));
}
```

perfect forwarding
---

```cpp
std::move ile
std::forwad arasındaki fark

static_cast<T&&>(arg) -> move


forward
if(arg is an L value )
```

	arg
```cpp
else
static_cast<T&&>(arg)
```

 1:35
---

---

---

---

---

---

---

---

---

-
---

---

---

---

---

---

---

---

---

---

---

---

---

---

---


```cpp
template<typename T>
void foo(T)
{
	std::cout << " foo(T) overload\n";
}
template <typename T>
void foo(T*)
{
	std::cout << "foo(T*) overload\<n";
}


int main()
{

	int* ptr = nullptr;
	foo(ptr);
}
```

foo(T*) overload
---

```cpp
 template<typename T>
void foo(T(*) (T))
{
	std::cout << "necati\n";
}
template <typename T>
void foo(T*)
{
	std::cout << "foo(T*) overload\n";
}

int bar(int)
{
	return 1;
}


int main()
{
	foo(bar);
}
```

necati
perfect forwading ( mükemmel  gönderim)
```cpp
class Myclass {};
void foo(Myclass&);

// void call_foo(???)

int main()
{
	//foo(arg);
	// call_foo(arg);
}
```

aslında bu.
Yani sen foo yu çağırmak yerine call_foo ile çağrıyorsun.
Buna perfect forwarding deniyor.
Peki neden ?
```cpp
class Myclass {};
void foo(Myclass&)
{
	std::cout << " Myclass& foo\n";
}
void foo(const Myclass&)
{
	std::cout << " const Myclass& foo\n";
}
void foo(Myclass&&)
{
	std::cout << " Myclass&& foo\n";
}
void foo(const Myclass&&)
{
	std::cout << " const Myclass&& foo\n";
}

void call_foo(Myclass& mr)
{
	foo(mr);
}
void call_foo(const Myclass& mr)
{
	foo(mr);
}
void call_foo( Myclass&& mr)
{
	foo(std::move(mr));
}
void call_foo(const Myclass&& mr)
{
	foo(std::move(mr));
}

int main()
{
	Myclass m;
	const Myclass cm;

	foo(m); // Myclass& foo
	call_foo(m);
	foo(cm); // const Myclass& foo
	call_foo(cm);
	foo(std::move(m)); // Myclass&& foo;
	call_foo(std::move(m));
	foo(std::move(cm)); // const Myclass&& foo;
	call_foo(std::move(cm));
}
```

 Myclass& foo
 Myclass& foo
```cpp
 const Myclass& foo
 const Myclass& foo
```

 Myclass&& foo
 Myclass&& foo
```cpp
 const Myclass&& foo
 const Myclass&& foo
}


//forwading reference
// universal reference
template<typename T>
void call_foo(T&& arg)
{
	foo(std::forward<T>(arg));
}
```

Buna perfect forwading'i gerçekleştirdi.
```cpp
class Myclass {};
template<typename T>
void foo(T&&)
{
	/*
	* referans collapsingden ötürü ben buraya gelen değişkenin l value r value oldugunu bulabilirim.
	* argumanın const olup olmadıgını da anlayabilirim.
	*/
}
template <typename T>
void bar(const T&)
{
	/*
	* ben buraya gönderdiğim argümanın l veya r value oldugunu sorgulayabilir miyim ?
	* - kesinlikle hayır.
	* const olup olmadıgını sınayabilir miyim ?
	* - kesinlikle hayır.
	*/
}


class Myclass {};
template<typename T>
void foo(T&&)
{
	if constexpr (std::is_reference_v<T>)
	{
		std::cout << "Bana gelen l value arg  ";
	}
	else
	{
		std::cout << "Bana gelen r value arg  ";
	}
	if constexpr (std::is_const_v < std::remove_reference_t<T>>)
	{
		std::cout << "constum\n";
	}
	else
	{
		std::cout << "non constum\n";
	}
}
	Myclass m;
	const Myclass cm;

	foo(m);
	foo(cm);
	foo(std::move(m));
	foo(std::move(cm));
```

Bana gelen l value arg  non constum
Bana gelen l value arg  constum
Bana gelen r value arg  non constum
Bana gelen r value arg  constum
```cpp
template <typename T>
void call_foo(T&& r) {
	foo(std::forward<T>(r));  // koşullu bir value kategori dönüşüm fonk.
}
std::move ile
std::forward
```

arasındakiş fark
```cpp
	static_cast<T&&>(arg)  move.


	if arg is an  L value
```

		arg
```cpp
	else
	static_cast<T&&>(arg)


template<typname T>
class Vector{

public:
void push_back(const T&);
void push_back(T&&);

template <typename ...Args>
void emplace_back(Args&& ... args
{
	new(address)T(std::forward<Args>(args)...)
}

};
```

perfect forwarding en tipik örneği
konteynırların nesneyi kopyalayarak ya da taşıyarak oluşturmak yerine
sen bana argümanları gönder ben o argümanları kullanarak sağladığın bellek alanında
nesneyi construct edeyim....
```cpp
auto return type


class Myclass {};

// auto return type
auto foo()
{

	return Myclass{};
}

// trailing return type
auto bar() ->Myclass
{
	return Myclass{};
}
// decltype(auto) return type
```

decltype(auto) baz()
```cpp
{
	return Myclass{};
}

```

---

```cpp
auto bar() -> int*(*) (int*, int*)
{

}
```

böyle kullanılabilir.
```cpp
int ar[10];
auto bom() -> int(&)[10]
{
	return ar;
}
```
