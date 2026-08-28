# neden array kullanmalıyız ?

1) sınıf
	interface
		daha STL uyumlu
2) exception handling
3) C apileri için uygun
4) array decaay yok
5) fonksiyonlara tek argumanla geçiş
6) genmeric kodlarda boyutu 0 olan  yuani bos olan bir dizi
7)
algorithms
	heap algo
		make_heap
		push_heap
		pop_heap
		sort_heap
		is_heap
		is_heap_until
```cpp
template<typename T>
struct Plus {
	operator()(const T& lhs, const T& rhs)
	{
		return lhs + ths;
	}
};


int main() {

	using namespace std;

	Plus<int>{}(12, 45);

	return 0;
}
```

set
multiset
map
multimap
```cpp
ekleme (insert)
silme	(erase)
```

search
binary search tree
red-black tree tercih ediyolarmıs
```cpp
<key> ->set
```

multisette birden fazla anahtar tutabiliriz
map
key - value
```cpp
isimlerden ===> telefon numara
```

multimapte birden fazla anahtar tutabiliriz
```cpp
x==y
```

equli,ty
equivalance
```cpp
	set<int > myset;

	for (int i = 0; i < 10; ++i)
	{
		int x = Irand{ 0, 9999 }();
		cout << x << " is inserted!\n";
		myset.insert(x);
	}
	for (auto i : myset)
	{
		cout << i <<" ";
	}
```

4957 is inserted!
664 is inserted!
1222 is inserted!
5478 is inserted!
870 is inserted!
2680 is inserted!
3129 is inserted!
4680 is inserted!
9388 is inserted!
4147 is inserted!
664 870 1222 2680 3129 4147 4680 4957 5478 9388
---

```cpp
	set<int > myset;
	Irand rand{ 0,999 };

	for (int i = 0; i < 400; ++i)
	{

		myset.insert(rand());
	}
	cout << "size : " << myset.size();
```

size : 331
---

strict weak ordering ne demek
irreflexive olması
a<a always false     a<= a
asymetric
```cpp
if a< b true thjen b< a false
```

transitive
```cpp
if a< b && b< c then a<c
```

transitibity of equivalance
!(a<b) && ! (b<a)
	!(b<c) && !(c<b)
		==> !(a < c ) && !(c<a)
---

```cpp
	using namespace std;
	set<int > myset{ 2,6,3,7,9,1 };
	cprint(myset);
	myset.insert(8);
	cprint(myset);
```

	1 2 3 6 7 9
	1 2 3 6 7 8 9
---

set'in insert gonjksşınun g.d degeri
pair<iterator,bool>
eger g.d.d olan pair'in second'i true ise
ekleme yapılmıştır
eger g.d.d olan pair'in second'i false ise
ekleme yapılmamıştır
ve first var olan öge konumu iterator
---

 find fonksiynu
 count
 contains
---

```cpp
	using namespace std;
	set<string> myset;
	rfill(myset, 10, random_name);
	cprint(myset,",");

	string name;
	std::cout << "enter the name : ";
	cin >> name;

	if (auto iter = myset.find(name); iter != myset.end()) {
		cout << "found : " << *iter << " distance : " << distance(myset.begin(), iter) << '\n';

	}
	else {
		cout << "not found\n";
	}
```

Bulent,Ceren,Ebru,Fatih,Gokhan,Hakan,Handan,Hatice,Nesrin,Serkan,
enter the name : Ebru
found : Ebru distance : 2
---

---

---

---

---

---
