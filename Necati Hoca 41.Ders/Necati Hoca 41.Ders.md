# 41. ders

## Variadic Templateler

```cpp
void func(...);
```

parameter pack
```cpp
template <typename ...Types>
class A{};
```

n tane   tempalte parametresine sahip olabilir.
```cpp
template <int ...NS>
```

n tane template non-tyhpe parametresine sahip olabilir.
```cpp
template<tempalte<typnemae>class ...T>
class C{};
```

n tane template tempalte parametreye sahip olabilir..
---

```cpp
template <typename ...Types>
class A {};




int main()
{


	A<int, double, long> a1;
```

	parametre paketidne 3 tane tür olascak
```cpp
	A < int, int> a2;
```

	parametre paketidne 2 tane tür olascak
```cpp
	A<std::string> a3;
```

	parametre paketidne 1 tane tür olascak
```cpp
	A<> a4;
```

	parametre paketidne  tür olmyacak
```cpp
}
```

---

---

```cpp
template <int ...NS>
class A {};




int main()
{


	A<2, 4, 5> a1;
	A < 3, 9> a2;
	A<134> a3;
	A<> a4;

}

```

---

```cpp
template parameter pack
```

function parameter pack
---

```cpp
template <typename ...TS> type parameter pack
void func(TS ...args) func parameter pack
{

}




int main()
{


	func(1, 2, 3, 4, 5);
	func(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	func(1, 2, 'a', "naber", 3.14, 1.f);

}
```

---

```cpp
sizeof(expr)
sizeof...(expr)  variadic sizeof operatoru


```

---

```cpp
template <typename ...Types>
int foo(int,Types&& ...args)
{
	std::cout << __FUNCSIG__ << "\n";
	return 42;
}




int main()
{
	int x{};
	double dval{};
	foo(x, 3.4, 'A', dval);
}
int __cdecl foo<double,char,double&>(int,double &&,char &&,double &)

```

---

```cpp
// pack expansion



template <typename ...TS>
class Nec {};

template <typename ...TS>
class Myclass {

	Nec<TS...> mnec;
};



```

---

```cpp
struct A {
	void foo();
};
struct B {
	void bar();
};
struct C {
	void baz();
};


template <typename ...TS>
class Der : public TS...{};





int main()
{
	Der<A, B, C> d;
	d.foo();


}


```

---

fonksiyon şablonları
recursive pack expansion
fold expression
recursive pack expansion
initializer list expansion
```cpp
if cxpr
```

fold expression
---
