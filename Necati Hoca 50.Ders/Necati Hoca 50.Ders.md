# stD::list

konumunu bildiğiniz herhangi bir yerden
neresi olursa olsun ekleme yapmayı constant time a çekiyor
ve silme işleminide
```cpp
 std::list
```

 <list>
```cpp
 template<typename T,typename A = std::allocator<T>>
class List {

};


```

---

```cpp
	list<int> mylist;
```

sort
unique
remove
remove_if
merge
reverse
splice
---

```cpp
	list<int> mylist(100);
	list<int> mylist{ 2,4,5,7 };



```

---

```cpp
	list<int> mylist{ 1,3,5,8,12,90,45,21 };
	mylist.reverse();
	print(mylist.begin(), mylist.end());
```

	21 45 90 12 8 5 3 1
---

```cpp
 	mylist.sort();
	print(mylist.begin(), mylist.end());
```

	21 45 90 12 8 5 3 1
---

1 3 5 8 12 21 45 90
---

---

```cpp
	auto n = mylist.remove(3);
	cout << n << " tane eleman silindi";
	print(mylist.begin(), mylist.end());
```

	1 tane eleman silindi1 5 8 12 21 45 90
---

---

```cpp
#include <iostream>
#include <list>
#include <string>

template <typename T>
void cprint(const T& con)
{
    for (const auto& elem : con)
        std::cout << elem << '\n';
}

int main()
{
    using namespace std;

    list<string> x{ "ali", "burak", "can", "emir", "furkan", "ramazan", "yunus" };
    list<string> y{ "banu", "demir", "ramiz", "turgut", "ziya", "zubeyde" };

    x.merge(y);

    cout << "y.size() = " << y.size() << '\n';

    cprint(x);
}
```

y.size() = 0
ali
banu
burak
can
demir
emir
furkan
ramazan
ramiz
turgut
yunus
ziya
zubeyde
---

list									forward list
size									size yok (distance)
insert									insert_after
erase									erase_after
xxxxxx									before_begin
---

```cpp
	forward_list<string> mylist{ "ece","efe","nur","gul","tan" };

	mylist.erase_after(mylist.begin());

	print(mylist.begin(), mylist.end());
```

	ece nur gul tan
```cpp
	mylist.erase_after(mylist.before_begin());
```

	efe nur gul tan
```cpp
	mylist.pop_front();
```

	efe nur gul tan
---

```cpp
std::array

int ar[20]  std::array<int,20>

template <typename T, std::size_t SIZE>
class Array {
	T ar[SIZE];
};
```

Avantajlar
---

---

---

---
