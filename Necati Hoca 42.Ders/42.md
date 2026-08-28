# 0template <typename ...TS>

```cpp
void Print(const TS& ...args)
{




}



int main() {

	Print(1, 2.3, 9);
	//Print<int, double, int>(const int&, const double&, const int&);

	return 0;
}
```

---

```cpp
template<typename T>
void Print(const T& r)
{
	std::cout << r << '\n';
}


template <typename T , typename ...TS>
void Print(const T& r, const TS& ...args)
{
	Print(r);
	Print(args...);
```

	Yani r yi yazdırıp tekrar parameterelerle çağırıoyprıum ama
	r bir sağa kaymıs oluyor
```cpp
}





int main() {

	int x = 4;
	std::string name{ "Beko" };
	double dval{ 3.976 };

	Print(x, name, dval, 4.5f);


	return 0;
}
```

4
Beko
3.976
4.5
```cpp
std::cout << __FUNCSIG__ << '\n';

void __cdecl Print<int>(const int &)
```

4
```cpp
void __cdecl Print<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >>(const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &)
```

Beko
```cpp
void __cdecl Print<double>(const double &)
```

3.976
```cpp
void __cdecl Print<float>(const float &)
```

4.5
---

```cpp
template<typename ...TS>
void Print(const TS& ...args)
{
	std::initializer_list<int>{(std::cout << args << ' ', 0)...};
	std::cout << '\n';
}

template<typename ...TS>
void foo(TS... args)
{
	Print(args...);
}




int main() {
	foo(1, 2, 3, 4, "manber", 4.5);


	return 0;
}
```

1 2 3 4 manber 4.5
---

```cpp
fold exppressions (min c++ 17 olması gerekior)
```

katlama ifadeleri
p1,p2,p3,p4
p1+p2+p3+p4 ifadesine çevirecek
p1*p2*p3*p4
```cpp
ifadesine çevirecek
```

right fold  p1+(p2+(p3+p4))
left fold	(p1+p2+)p3)+p4
fold over
binary fold
(init+ p1) + p2 ) + p3 +p4)) left fold
p1 + (p2 + (p3 + (p4 + init)) right fold
(args + ...)  ... sagada ise r  solda ise l fold
(... + args)
```cpp
-*------------     -----
template <typename ...TS>
auto sum(Ts ...args)
{
	return (... + args);

}

```

---

```cpp
template <typename ...TS>
constexpr auto sum(TS ...args)
{
	return (... + args);

}




int main() {
	constexpr auto val = sum(3, 4, 5, 6, 6, 7, 8, 9);

	return 0;
}
```

48
```cpp
unary lef fold over comma operator


```

---

```cpp
/*
* C++ 20
* abbreviated template syntax
```

---

```cpp
*/
void foo(auto x)
{

}



constexpr auto sum(const auto& ...args)
{
	return (... + args);
}




int main() {

	constexpr auto val = sum(3, 4, 5, 6, 6, 7, 8, 9);
	return 0;
}
```

48
modern cpp ile auto yerini tutuyormus
---

```cpp
constexpr auto get_last(auto ...args)
{
	return (args, ...);
}



int main() {

	constexpr auto val = get_last(3, 4, 5, 6, 6, 7, 8, 9);
	return 0;
}



```

---

STL
standart template library
```cpp
class template
```

function template
containers
algorithms
iterators
```cpp
template <typename T>
class DynamicArray {

public:
	//void push_back
	//void pop_back
};



int main() {
	DynamicArray<int> x;
	DynamicArray<double> x;
```

container sınıflar - sequence container
vector      dynamic_array
string		dynamic_array
deque		dinamik dizilerin dizisi
list		double link list
```cpp
forward_list single linked list
```

array
---

associative containers
set			2li arama agacı hepsi
multiset
map
multimap
---

unordered assoicative containers
unordered_set
unordered_multiset
unordered_map
unordered_multimap
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

---

---

---
