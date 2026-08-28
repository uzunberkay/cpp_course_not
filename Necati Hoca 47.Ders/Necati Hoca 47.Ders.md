# -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

vector default containerimiz gibi düşün diyor.
```cpp
#include <vector>
```

vector ile dinamik diziyi aynı anlamda kullanıyor.
---

```cpp
vector<vector<vector<int>>> vec;
```

---

```cpp
	vector<string> svec{ "furkan","kaveh","gizem","ramazan" };

	cout << svec[2] << '\n';
	svec[2] += "naz;
	cout << svec[2] << '\n';
```

---

gizem
gizemnaz
---

Dikkat
bir vektörü döngüsel bir yapıda
büyütüyorsanız niahi erişebileceği boyutu hakkında
bilgi sahibiyseniz
```cpp
	vector<string> svec(10000);
	cout << "svec.size() = " << svec.size() << '\n';
	cout << "svec.capacity() = " << svec.capacity() << '\n';


	svec.erase(svec.begin() + 10, svec.end());
	cout << "svec.size() = " << svec.size() << '\n';
	cout << "svec.capacity() = " << svec.capacity() << '\n';
```

svec.size() = 10000
svec.capacity() = 10000
svec.size() = 10
svec.capacity() = 10000
baştan sınıfın reserve fonksiyonunu çağırın.
bazı durumlarda vectorden elemanlar silindiğinde
kapasiteyi shring (büzmek) isteyebiliriz.
swap-trick
[
```cpp
	vector<string> svec(10000);
	cout << "svec.size() = " << svec.size() << '\n';
	cout << "svec.capacity() = " << svec.capacity() << '\n';


	svec.erase(svec.begin() + 10, svec.end());

	vector<string>(svec).swap(svec);

	cout << "svec.size() = " << svec.size() << '\n';
	cout << "svec.capacity() = " << svec.capacity() << '\n';
```

	svec.size() = 10000
svec.capacity() = 10000
svec.size() = 10
svec.capacity() = 10
]
---

shrink to fit
```cpp
	vector<string> svec(10000);
	cout << "svec.size() = " << svec.size() << '\n';
	cout << "svec.capacity() = " << svec.capacity() << '\n';


	svec.erase(svec.begin() + 10, svec.end());

	svec.shrink_to_fit();

	cout << "svec.size() = " << svec.size() << '\n';
	cout << "svec.capacity() = " << svec.capacity() << '\n';
```

svec.size() = 10000
svec.capacity() = 10000
svec.size() = 10
svec.capacity() = 10
---

```cpp
void print_array(const int* p, size_t size)
{
	while (size--)
		printf("%d ", *p++);
	printf("\n");
}

int main() {


	using namespace std;

	vector<int> ivec(10,5);
	cout << "svec.size() = " << ivec.size() << '\n';
	cout << "svec.capacity() = " << ivec.capacity() << '\n';
	print_array(ivec.data(), ivec.size());

	cout << "svec.size() = " << ivec.size() << '\n';
	cout << "svec.capacity() = " << ivec.capacity() << '\n';


	return 0;
}
```

svec.size() = 10
svec.capacity() = 10
5 5 5 5 5 5 5 5 5 5
svec.size() = 10
svec.capacity() = 10
---

Vector<T>()
Vector<T>(size_t)
Vector<T>(size_t,T)
Vector<T>(iter,iter)
Vector<T>(const Vector<T>&)
Vector<T>(Vector<T>&&)
Vector<T>(initializer_list<T>)
begin
cbegin
rbegin
crbegin
end
cend
rend
crend
```cpp
size()
capacity()
capacity()
data()
get_allocator()



operator[]()
operator[]()const
at()
at()const
front()
front()const
```

---

```cpp
	using namespace std;

	vector<string> svec{ "ali","ege","tan" };
	print(svec.begin(), svec.end());
	std::cout << "---------------------\n";
	svec.insert(svec.end(), { "esra","ayla","ecem" });
	print(svec.begin(), svec.end());
```

ali
ege
tan
---

ali
ege
tan
esra
ayla
ecem
---

```cpp
	vector<string> svec{ "ali","ege","tan" };
	list<string> slist{ "joe","michael","janson","thomas" };
	print(svec.begin(), svec.end());

	svec.insert(svec.end(), { "esra","ayla","ecem" });
	print(svec.begin(), svec.end());
	svec.insert(svec.begin(), slist.begin(), slist.end());
	print(svec.begin(), svec.end());
```

	ali
ege
tan
---

ali
ege
tan
esra
ayla
ecem
---

joe
michael
janson
thomas
ali
ege
tan
esra
ayla
ecem
---

döngüsel yapıda
	döngünün her turunda 1 tane değeri
		eklemek ya da silmek yerine
eğer tek bir çağrıyla
	birden fazla eleman eklemek
	birden fazla eleman silmek
range_insert daha verimli.
insert fonkları ilk insert edilen eleman konumunu döndürür
erase fonkları son silinen elemandan sonrakiş konumunu döndürür
(yani silinmemiş ilk elemanı)
```cpp
	vector<string> svec{ "ali","ege","tan" };
	list<string> slist{ "joe","michael","janson","thomas" };
	print(svec.begin(), svec.end());

	svec.insert(svec.end(), { "esra","ayla","ecem" });
	print(svec.begin(), svec.end());
	svec.insert(svec.begin(), slist.begin(), slist.end());
	print(svec.begin(), svec.end());

	auto iter = svec.erase(svec.begin());

	cout << *iter;
```

	ali
ege
tan
---

ali
ege
tan
esra
ayla
ecem
---

joe
michael
janson
thomas
ali
ege
tan
esra
ayla
ecem
---

michael
```cpp
	svec.clear();
	svec.resize(0);
	svec.erase(svec.begin(), svec.end());
```

---

```cpp
	vector<int> vec1{ 1,2,3,4,5,6 };
	vector<int> vec2{ 7,8,9,10 };
	print(vec1.begin(), vec1.end());
	vec1.swap(vec2);

	print(vec1.begin(), vec1.end());
```

1
2
3
4
5
6
---

7
8
9
10
---

ğretimde vector üzerinde yapılan bazı tipil işlemler
belirli bir değere sahip ilk ögeyi silmek
belirli bir değere sahip tüm elemanları silmek için
erase-remove idiyomu kullanılır.
```cpp
ancak C++20 ile bu idiyomu  implemente eden
```

	free function
```cpp
		std::erase eklenmiştir


```

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
