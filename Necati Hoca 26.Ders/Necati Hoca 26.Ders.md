# 26. DERS

---

string::npos nedir?
size_t en büyük değerini temsil eden sabittir.
```cpp
	string str = "Hello, World!";
	auto idx = str.find("World");
	if (idx != string::npos) {
		cout << "'World' found at index: " << idx << endl;
	} else {
		cout << "'World' not found." << endl;
	}
```

	aranan bulunamazsa npos döner.
---

```cpp
	string name = "yasar ugur gulec";
	string str(name,6,4);
	cout << str << endl;
```

## Ugur

---

```cpp
		string s1{ "alican" }, s2{ "metehan" };

	//  std::string op std::string
	//  std::string op const char*
	//  const char* op string

	if (s1 == s2)
	{
		cout << "s1 ve s2 esit\n";
	}
	else
	{
		cout << "s1 ve s2 esit degil\n";
	}
```

s1 ve s2 esit degil
---

lexicographical compare
iki contanier
   karşılaştırıldığında
	eşit olmaları için
		size'lar eşit olacak
		    hem de karşılıklı bütün öğeler eşit olmalı
f
```cpp
cout << s1 + s2 << endl;
```

alicanmetehan oluyor.
string + string
string + cstring
string + cstring
string + char
char + string
```cpp
	s1.append(" metehan");
	cout << s1 << endl;
```

alican metehan
---

```cpp
	string str{ "bugun cuma gunu" };

	for(char& c : str)
	{
		if(c == ' ')
		{
			c = '_';
		}
	}
	cout << str << endl;
```

bugun_cuma_gunu
---

```cpp
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };

	cout << vec.front() << endl;  // Output: 1
	cout << vec.back() << endl;   // Output: 10
		vec.front() = 100;
	cout << vec.front() << endl;  // Output: 100
```

---

```cpp
		// atama operator fonksiyonu
	// copy assig. veya move assig.

	string s1;
	string s2 = { "gizem" };

	s1 = s2; // copy assignment

	cout << s1 << " " << s2 << endl;
```

	gizem gizem
---

```cpp
	s1 = move(s2); // move assignment

	cout << s1 << " " << s2 << endl;
	cout << boolalpha << (s1 == s2) << endl;
```

	gizem
	false
---

String atama fonksiyonları*
---

```cpp
	string s{ "muratcan" };
	cout << "[" << s << "]\n";
	s = "omer dogu";
	cout << "[" << s << "]\n";
	s = 'a';
	cout << "[" << s << "]\n";
	s = { 'a','l','i' };
	cout << "[" << s << "]\n";
	initializer_list<char> ilist = { 'n','u','r' };
	s = ilist;
	cout << "[" << s << "]\n";
```

[muratcan]
[omer dogu]
[a]
[ali]
[nur]
---

```cpp
	s.assign(10, 'p');
	cout << "[" << s << "]\n";
```

	10 tane p karakteri at  [pppppppppp]
---

```cpp
	string s{ "muratcan" };
	string str{ "erman candan" };
	print(s);

	s.assign(str, 6);
	print(s);
```

---

```cpp
	char ar[] = "Kerim oksuz";
	print(s);

	s.assign(str, 6);
	print(s);
	s.assign(ar, 5);
	print(s);
```

---

```cpp
char ar[] = "mehmet ali ersoy";
	s.assign(ar + 7 , 5);
	print(s);
```

[ali e]
---

mutators
push_back
```cpp
operator+=
append  -> sona ekleme
operator=
```

assign
```cpp
	string s{ "muratcan" };
	cout << "S len : " << s.length() << '\n';
	s.resize(20);
	cout << "S len : " << s.length() << '\n';
```

	S len : 8
S len : 20
---

```cpp
	string s{ "muratcan" };
	cout << "S len : " << s.length() << '\n';
	s.resize(20,'x');
	cout << "S len : " << s.length() << '\n';
	print(s);
```

S len : 8
S len : 20
[muratcanxxxxxxxxxxxx]
---

ekleme fonksiyonları her zaman konum ister.
hangi konuma ekleme yapılacak.
2 5 6 9 3
---

```cpp
	string name;
	cout << "ismin ne kardeşim: ";
	getline(cin, name);

	print(name);
	name.erase(name.begin() + 1, name.end() - 1);
	print(name);
```

ismin ne karde■im: berkay
[berkay]
[by]
Hangi aralıklar silinecek ?
---

```cpp
name.pop_back(); son karakteri siliyo.

	string name;
	cout << "ismin ne kardeşim: ";
	getline(cin, name);

	print(name);
	name.insert(name.begin() + 3, '*');
	print(name);
```

	ismin ne karde■im: berkay
[berkay]
[ber*kay]
---

```cpp
	string str(40, 'a');
	cout << "[" << str << "]\n";

	str.clear();

	cout << "[" << str << "]\n";
	str.clear(); // tamamen siler .
	str.resize(0); // tamamen siler .
	str.erase(str.begin(),str.end()); // tamamen siler .
	str.erase(0); // tamamen siler .
	str.assign(""); // tamamen siler .
	str.assign({}); // tamamen siler .
	str = string{};
```
