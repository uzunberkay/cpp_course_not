# 27.DERS*

---

```cpp
STL (Standart Template Library)

class template
```

function template
variable template
alias template
```cpp
concept (diğer template'leri constraint etmek)



	string str("bugun hava cok guzel");
	cout << "[" << str << "]\n";
	cout << "Kapasite= " << str.capacity() << '\n';
	cout << "uzunluk = " << str.length() << '\n';
	str.append(12, 'a');
	cout << "Kapasite= " << str.capacity() << '\n';
	cout << "uzunluk = " << str.length() << '\n';
	cout << "[" << str << "]\n";

```

---

	[bugun hava cok guzel]
```cpp
Kapasite= 31
uzunluk = 20
Kapasite= 47
uzunluk = 32
```

[bugun hava cok guzelaaaaaaaaaaaa]
---

---

Eğer string nesnenizin tuttuğu yazının "giderek belirli bir uzunluğa
kadar büyüyeceğini baştan biliyosanız
	defalarca reallocation olacağına
	baştan belirtelim.  "
	str.reserve(4000) gibi...
---

```cpp
Küçültmek istersem örneğin 40000 -> 10000 yapmak istiyorum.
```

non-binding shrink request
bağlayıcı olmayan büzülme talebi
---

```cpp
	/*
	* str.erase(1) ile
	* 1.indexten sonrasını sildik.
	* len = 1 oldu . Fakat
	* capacity düşmedi.. Düşmesini beklerdik dimi...
	*/
	string str(100'000, 'a');
	cout << "str.length() = " << str.length() << '\n';
	cout << "str.capacity() = " << str.capacity() << '\n';

	str.erase(1);

	cout << "str.length() = " << str.length() << '\n';
	cout << "str.capacity() = " << str.capacity() << '\n';
```

str.length() = 100000
str.capacity() = 100015
str.length() = 1
str.capacity() = 100015
---

```cpp
	str.reserve(40);
	cout << "after reserve call\n";
	cout << "str.capacity() = " << str.capacity() << '\n';
```

	str.capacity() = 100015
after reserve call
str.capacity() = 100015
capacity düşürmüyor.
---

```cpp
	str.shrink_to_fit();
	// dikkat bu da aslında non-binding request
	cout << "after reserve call\n";
	cout << "str.capacity() = " << str.capacity() << '\n';
```

str.capacity() = 100015
after reserve call
str.capacity() = 15
```cpp
str.shrink_to_fit----
```

---

```cpp
	string str{ "necatiergin" };

	auto s = str.substr(3);
	print(s);
```

	[atiergin]
	substr ile stringin belirli kısımlarından yeni bir string olusturulabilir.
```cpp
	auto s = str.substr(3,3);
```

	[ati]
```cpp
		string str{ "necatiergin" };

	auto s = str.substr();  // str.substr(0);
```

	gibi . O yüzden strnin aynısı olur.
```cpp
	print(s);
```

	[necatiergin]
	Burada aslında bir deep copy yapıyorum.
```cpp
	str.substr(4000,50000); gibi bir şey yapsaydım maliyet fena olacaktı
```

	peki sadece okumak istesem bu maliyeti ödemeden yapabilir miyim ?
	Evet
	<string_view> ile.
---

```cpp
	string str{ "necatiergin" };

	auto s = str.substr();
	string_view sv(str.substr(2));
	cout << sv;
```

	BU şekilde sv sadece read-only işlemler yapılabiliyo. Aslında
	2 adet pointer tutuyor içeride.
Dikkat!!
eğer substring oluşturmak istemenizin nedeni yalnızca
access op ise
	yeni bir kopya oluşturmak yerine
		gözlemci
			string_view kullanın.
f
---

overloading
fonksiyona hem L value hem de R value gönderilebilsin.
```cpp
void bar(std::string& s)
{
	// gelen L value ise onun kaynağını kopyala
	// gelen R value ise onun kaynağını çal.
}

void bar(const std::string& s)
{
	std::cout << "L value geldi bana onun kaynagini kopyaliyorum\n";
}

void bar(std::string&& s)
{
	std::cout << "R value geldi bana onun kaynagini caliyorum\n";
}

```

---

```cpp
	/*
	* ilginc bir şekilde allocate edilen bellek alanının>
	* addresini aşağıdaki kodlardan herhangi biriyle elde edebiliriz.
	*/
	cout << static_cast<const void*>(str.c_str()) << "\n";
	cout << static_cast<const void*>(str.data()) << "\n";
	cout << static_cast<const void*>(&str[0]) << "\n";
	cout << static_cast<const void*>(&str.at(0)) << "\n";
	cout << static_cast<const void*>(&*str.begin()) << "\n";
```

	 str.find
	 str.rfind
	 str.
	 find_first_of
```cpp
	 if(str.contains('c'))
```

---

```cpp
	string str;

	cout << "Bir yazi girin : ";

	getline(cin, str);
	if (auto idx = str.find('e');idx != string::npos) find ilki bulur rfind sonu bulur.
	{
		cout << "bulundu! idx = " << idx << '\n';
		str[idx] = '*';
		cout << str;
	}
	else
	{
		cout << "Bulunmadi!\n";
	}
```

	str.find('eiau',4) böyle falan a olabiliyor.
---

```cpp
	cout << "Bir yazi girin : ";

	getline(cin, str);
	cout << "[" << str << "]\n";
	auto ival = stoi(str);
	cout << ival;
```

	Bir yazi girin : 12334berkay
[12334berkay]
12334
---

```cpp
	size_t idx{};
	auto ival = stoi(str,&idx);
	cout << ival << '\n';
	cout << "idx = " << idx << '\n';
```

	Bir yazi girin : 321321berkay
[321321berkay]
321321
```cpp
idx = 6
```

---

```cpp
	cout << "[" << str << "]\n";
	size_t idx{};
	auto ival = stoi(str,&idx,16);
	cout << ival << '\n';
	cout << "idx = " << idx << '\n';
```

	16 ' da sayı tabanıymış
---

```cpp
	cout << "Bir yazi girin : ";

	getline(cin, str);
	cout << "[" << str << "]\n";
	if (str.contains("necati"))
	{
		cout << "evet var\n";
	}
	else
	{
		cout << "Hayir yok \n";
	}

```

---

```cpp
	string str{ " object oriented c++" };

	size_t n = erase(str, 'e');

	if (n)
		cout << "silindi : [ " << str << "]\n";
silindi : [  objct orintd c++]
```

e leri sildik.
---
