# 25. Ders

---

String Sınıfı
```cpp
class template

template instantiation
	template specilization
```

basic_string
```cpp
	basic_string<char, char_traits<char>, allocator<char>> s1;
	basic_string<char> s2;
	string str = "Hello, World!";
```

	Bunlar aynı.
	kaynak kullanan sınıfılar
		RAII idiom
			move semantics
```cpp
	operator overloading
```

	     function overloading
	function overloading
	   member func.
	   free func.
	nested type
	    type alias
special member functions
   string_view
   regex library
data structures (veri yapıları)
dynamic array (dinamik dizi)
```cpp
contanier (kap)
```

contanier interface
	insert
	erase
iterator
```cpp
STL (Standard Template Library)
```

algorithm
```cpp
O(1)
O(n)
O(log n)
O(n log n)
```

işini görüyprsa
(default)
	seçim
	  dinamik dizi
```cpp
capacity (kapasite)
```

Dikkat!
```cpp
reallocation (yeniden tahsis)
```

    reallocation takes time
sso  small string optimization
	small memory optimization
string sınfı içinde 20 bytlelık alan var. Eğer string 20 byte dan kısaysa heap e gitmiyor.
stackte tutuluyor. Bu da küçük stringler için performans artışı sağlıyor.
Allocator kullanımı azaltıyor.
Eğer sonradan eklenip 20 byte ı geçerse heap e gidiyor. (allocator kullanıyor))
```cpp
	cout << str.length() << endl;
	cout << str.size() << endl;  // contanier
```

big class
contanier
  .size()
  .empty()
  .erase(iter)
  .clear() tüm ögeleri siler
  .front() ilk ögeye erişim
  .back() son ögeye erişim
index interface
```cpp
str.find('a');  index of first 'a'

```

---

```cpp
	using namespace std;
	vector vec{ 2,5,7,9,1 };

	auto iter = vec.begin() + 2;
	vec.erase(iter);

	cout << "Vector elemanlari: ";
	for (const auto& eleman : vec)
	{
		cout << eleman << " ";
	}
```

	Vector elemanlari: 2 5 9 1
---

index isteyen tüm parametreler
index döndürem tüm fonksiyonlar
yazı uzunluğu
kapasite
index
string::size_type
string sınıfında karşımıza çıkacak
fonksiyonların parametrik yapılar
param											anlamı
```cpp
const char* s        (cstring)                   sonunda null karakter olan yazı addresi
const string& str						parametre olan stringin tuttuğu yazı
const char*p , size_t n					p adresinden başlayarak n karakterlik yazı
```

size_t n , char c						n karakterlik yazı, her karakter c
```cpp
const string& str , size_t idx (data)            str stringinin idx indeksinden başlayan yazı ve geri kalan kısmı
```

size_t n , char c (fill)
initialize_list<char>                ilist			listedeki karakterlerin olustudugu yazı
```cpp
const char*pf , const char* pe


```

---

```cpp
	auto len = str.length();
	auto cap = str.capacity();
```

	cout << "Length: " << len << ", Cap
Length: 13, Capacity: 15
---

```cpp
	cout << str << endl;
	cout << "Length: " << str.length() << ", Capacity: " << str.capacity() << endl;
	str += " Welcome to C++23.";
	cout << str << endl;
	cout << "Length: " << str.length() << ", Capacity: " << str.capacity() << endl;
```

	Hello, World!
Length: 13, Capacity: 15
```cpp
Hello, World! Welcome to C++23.
```

Length: 31, Capacity: 31
---

Dikkat!
string sınıfının char parametreli ctor yok!!!
Dikkat !
string sınıfının
string::size_type yani size_t türümnden
```cpp
constexpr static npos isimli bir veri elemanı
```

string::npos ne işe yarıyor ?
