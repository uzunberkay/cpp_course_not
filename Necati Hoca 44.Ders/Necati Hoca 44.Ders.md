# 44.ders

---

```cpp
class ReverseIterator {
public:

operator++()
{
	 --iter;
}
T& operator*()
{
	return *(iter -1 );
}

private:
Iterator iter;

};



```

---

kap'ların
normal iterator isteyen bir erase fonksiyonu var
---

```cpp
template <typename InIter , typename T>
```

InIter Find(InIter beg, InIter end, const T& key)
```cpp
{
	while (beg != end)
	{
		if (*beg == key)
			return beg;
		++beg;
	}

	return end;
}


```

---

```cpp
int main() {
	using namespace std;

	int n = 4;
	list<string> slist{ "kadir","berkay","gizem","furkan" ,"umut","necati" };

	auto iter = slist.begin();
	auto it = next(iter, 3);

	cout << *it;

	return 0;
}
```

furkan
---

```cpp
int main() {
	using namespace std;

	int n = 4;
	list<string> slist{ "kadir","berkay","gizem","furkan" ,"umut","necati" };

	auto iter = slist.end();
	auto it = prev(iter, n);

	cout << *it;

	return 0;
}
```

gizem
---

```cpp
template<typename Iter1, typename Iter2>
void IterSwap(Iter1 it1, Iter2 it2)
{
	auto temp = std::move(*it1);
	*it1 = std::move(*it2);
	*it2 = std::move(*it1);
}
```

---

```cpp
	set<string> myset{ "tan","beko","can","ata" };
	vector<string>svec(4);
	copy(myset.begin(), myset.end(), svec.begin());


```

---

what is a lambda expression
x+ 5
```cpp
Myclass{}
```

x+y
lambda exp için compiler
closure type(kapanış türü)
bir lambda
	bir sınıf nesnesi
	Pr value
```cpp
[]() {cout <<"merhaba duynya ";}();
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

---

---

---
