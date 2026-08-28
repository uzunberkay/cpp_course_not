# 52

bool cmp(int x, int y)
```cpp
{
	return std::abs(x) < std::abs(y);
}


int main() {

	using namespace std;
	set<int, bool(*)(int, int)>;

	set<int, decltype(&cmp)>;


		using namespace std;
	set<string,greater<string>> names;
	rfill(names, 10, random_name);
	cprint(names);
```

Seyma Selim Sedat Oyku Melek Halil Gokhan Ezgi Damla Burak
greater ile buyukten kucuge dolasıyor.
```cpp
	set<string> names;
	rfill(names, 10, random_name);
	cprint(names);
```

	Ece Fatih Handan Iclal Murat Mustafa Nur Sema Su Yusuf
	böyle de küçükten buyuge
```cpp
--------------------------------------------------------;
	set<string> names;
	rfill(names, 10, random_name);
	cprint(names);
	string key;
	cout << "aranacak isim: ";
	cin >> key;

	// arama find ile yapılıyor

	if (auto iter = names.find(key); iter != names.end()) {
		cout << " bulundu : " << *iter << " \n";
	}
	else
	{
		cout << "bulunamadi!\n";
	}
```

	Alp Gokhan Kaan Kadir Kivilcim Kubra Mavi Meryem Nisa Tolga
aranacak isim: Kadir
 bulundu : Kadir
```cpp
--------------------------------------------------------;

	// arama count ile yapılıyor

	if (names.count(key)) {
		cout << " bulundu \n ";
	}
	else
	{
		cout << "bulunamadi!\n";
	}
```

	Bulent Deniz Elif Emir Oyku Ozge Tolga Tulay Tunc Volkan
aranacak isim: Oyku
 bulundu
 Belma Canan Ceylan Ferda Jale Kartal Levent Osman Seda
aranacak isim: Berkay
bulunamadi!
```cpp
--------------------------------------------------------;

	// arama .contains ile yapılıyor

	if (names.contains(key)) {
		cout << " bulundu \n ";
	}
	else
	{
		cout << "bulunamadi!\n";
	}
```

Ceren Damla Ela Elif Gokhan Kubra Naci Necati Rabia Tulay
aranacak isim: Ceren
 bulundu
```cpp
--------------------------------------------------------;
	if (auto iter = names.find(key); iter != names.end()) {
		cout << " bulundu : " << *iter << " \n";
		names.erase(iter);
		cprint(names);
	}
	else
	{
		cout << "bulunamadi!\n";
	}
```

	Alp Cansu Derya Handan Huseyin Kivilcim Selim Serkan Seyma
aranacak isim: Huseyin
 bulundu : Huseyin
Alp Cansu Derya Handan Kivilcim Selim Serkan Seyma
```cpp
--------------------------------------------------------;
		using namespace std;
	multiset<string> names;
	rfill(names, 100, random_name);
	cprint(names);
	string key;
	cout << "aranacak isim: ";
	cin >> key;

	size_t n = names.erase(key);
	if (n)
	{
		cout << n << " eleman silindi!\n";
		cprint(names);
	}
	else
	{
		cout << "hicbir eleman silinmedi\n";
	}
```

Ada Ada Ahmet Ahmet Aleyna Aleyna Arda Asli Asli Baran Belma Belma Beren Bora Bulent Bulent Cagan Canan Cansu Cansu Cihan Cihan Cinar Derya Devran Devran Efe Ege Eren Esra Eylul Fatih Ferhat Feyza Feyza Furkan Gizem Gokce Gokhan Gorkem Gorkem Gorkem Gul Halil Hande Hasan Hazal Iclal Ipek Ismail Kadir Kadir Kagan Kivilcim Kubra Kuzey Kuzey Lale Leyla Lidya Mehmet Mustafa Naci Naci Necati Nisa Nur Nur Oguz Orhan Osman Oyku Oyku Oyku Ozan Perihan Rabia Riza Riza Ruya Selin Su Sukru Tolga Toprak Tuana Tugba Tugrul Tulay Ummu Vildan Vildan Vildan Yavuz Yigit Yildiz Yunus Yusuf Zafer Zeliha
aranacak isim: Vildan
3 eleman silindi!
Ada Ada Ahmet Ahmet Aleyna Aleyna Arda Asli Asli Baran Belma Belma Beren Bora Bulent Bulent Cagan Canan Cansu Cansu Cihan Cihan Cinar Derya Devran Devran Efe Ege Eren Esra Eylul Fatih Ferhat Feyza Feyza Furkan Gizem Gokce Gokhan Gorkem Gorkem Gorkem Gul Halil Hande Hasan Hazal Iclal Ipek Ismail Kadir Kadir Kagan Kivilcim Kubra Kuzey Kuzey Lale Leyla Lidya Mehmet Mustafa Naci Naci Necati Nisa Nur Nur Oguz Orhan Osman Oyku Oyku Oyku Ozan Perihan Rabia Riza Riza Ruya Selin Su Sukru Tolga Toprak Tuana Tugba Tugrul Tulay Ummu Yavuz Yigit Yildiz Yunus Yusuf Zafer Zeliha
```cpp
--------------------------------------------------------;

	using namespace std;
	multiset<string> names;
	rfill(names, 10, random_name);
	cprint(names);
	string oldkey, newkey;
	cout << "eski ve yeni anahtarlari giriniz: ";
	cin >> oldkey >> newkey;
	if (auto iter = names.find(oldkey); iter != names.end())
	{
		cout << "bulundu ve degistiriliyor...\n";
		names.erase(iter);
		names.insert(newkey);
		cprint(names);

	}
	else
	{
		cout << "bulunamadi!";
	}
```

Hatice Hazal Kader Leyla Necati Osman Oyku Ramazan Tarik Zeliha
eski ve yeni anahtarlari giriniz: Hazal Zonguldak
bulundu ve degistiriliyor...
Hatice Kader Leyla Necati Osman Oyku Ramazan Tarik Zeliha Zonguldak
```cpp
--------------------------------------------------------;

	using namespace std;
	multiset<string> names;
	rfill(names, 10, random_name);
	cprint(names);
	string oldkey, newkey;
	cout << "eski ve yeni anahtarlari giriniz: ";
	cin >> oldkey >> newkey;
	if (auto iter = names.find(oldkey); iter != names.end())
	{
		auto handle = names.extract(iter);
		handle.value() = newkey;
		names.insert(move(handle));
		cout << "bulundu ve degistiriliyor...\n";
		cprint(names);

	}
	else
	{
		cout << "bulunamadi!";
	}
```

Ada Ege Fatih Ferda Ibrahim Irmak Melis Mert Serkan Seyma
eski ve yeni anahtarlari giriniz: Irmak
Cevo
bulundu ve degistiriliyor...
Ada Cevo Ege Fatih Ferda Ibrahim Melis Mert Serkan Seyma
```cpp
--------------------------------------------------------;
```

sorted ranges
lower bound
upper bound
equal bound
2 5 7 7 7 7 7 8 8 12 34 56
lower bound for a key
	o anahtarın sırayı bozmadan eklenebileceği ilk konum
	anahtardan >= olan ilk ögenin konumu
upper bound for a key
	o anahtarın sırayı bozmadan eklenebileceği ilk konum
	anahtardan > olan ilk ögenin konumu
equal range
	[lower_bound,upper_bound]
```cpp
--------------------------------------------------------;

    multiset myset{ 2,4,7,7,7,7,9,9,12,34,56 };


    auto iter = myset.lower_bound(17);
    cout << *iter;
```

	34
	-
```cpp
	multiset myset{ 2,4,7,7,7,7,9,9,12,34,56 };


    auto iter = myset.upper_bound(17);
    cout << *iter;
```

	34
```cpp
--------------------------------------------------------;

    multiset myset{ 2,4,7,7,7,7,9,9,12,34,56 };


    auto iter_lower = myset.lower_bound(7);
    auto iter_upper = myset.upper_bound(7);

    cout << "iter lower : " << *iter_lower << '\n';
    cout << "iter upper : " << *iter_upper << '\n';
	 cout << "distance   : " << distance(iter_lower, iter_upper) << '\n';
	 copy(iter_lower, iter_upper, ostream_iterator<int>{cout, " "});
```

	iter lower : 7
	iter upper : 9
	distance   : 4
	7 7 7 7
```cpp
--------------------------------------------------------;
 auto equal_range = myset.equal_range(7);
  cout << "distance   : " << distance(equal_range.first, equal_range.second) << '\n';
```

  distance   : 4
```cpp
--------------------------------------------------------;
int main()
{
    using namespace std;

    vector<int> ivec;

    // ivec içine 0 ile 9 arasında rastgele 20 tane int değer atar.
    rfill(ivec, 20, Irand{ 0, 9 });

    // Binary search algoritmaları sıralı aralık ister.
    // O yüzden önce vector sıralanıyor.
    sort(ivec.begin(), ivec.end());

    // Sıralanmış vector ekrana yazdırılır.
    cprint(ivec);

    std::cout << "anahtari girin: ";

    int key;
    cin >> key;

    // equal_range:
    // Sıralı aralıkta key değerinin bulunduğu aralığı döndürür.
    //
    // Geriye pair döner:
    // first  -> lower_bound iterator'ı
    // second -> upper_bound iterator'ı
    auto [iter_lower, iter_upper] = equal_range(ivec.begin(), ivec.end(), key);

    cout << "index for lower_bound : " << iter_lower - ivec.begin() << '\n';
    cout << "index for upper_bound : " << iter_upper - ivec.begin() << '\n';

    // lower_bound ile upper_bound arasındaki mesafe,
    // key değerinden kaç tane olduğunu verir.
    cout << "distance = " << distance(iter_lower, iter_upper) << '\n';
}
```

0 0 1 2 2 2 3 4 4 4 5 5 6 6 6 7 7 7 7 7
anahtari girin: 4
index for lower_bound : 7
index for upper_bound : 10
```cpp
distance = 3
--------------------------------------------------------;





--------------------------------------------------------;

 using namespace std;

    vector<string> svec;

    for (int i = 0; i < 10; ++i) {

        // Rastgele bir isim üretiliyor.
        auto s = random_name();

        // lower_bound kullanılsaydı:
        // Aynı değerden varsa yeni elemanı eşitlerin başına eklerdi.
        // svec.insert(lower_bound(svec.begin(), svec.end(), s), s);

        // upper_bound:
        // Yeni ismi sıralı düzeni bozmayacak şekilde ekler.
        // Eğer aynı isimden varsa, eşit olanların sonrasına ekler.
        svec.insert(upper_bound(svec.begin(), svec.end(), s), s);

        // Her eklemeden sonra vector yazdırılır.
        cprint(svec);

        // Program her adımda bekler.
        // Enter'a basınca sonraki isim eklenir.
        (void)getchar();
```

tonguc
---

ferhunde tonguc
---

ferhunde hakan tonguc
---

ferhunde hakan irmak tonguc
---

ferhunde hakan irmak muslum tonguc
---

ferhunde hakan irmak mukerrem muslum tonguc
---

birhan ferhunde hakan irmak mukerrem muslum tonguc
---

birhan cahide ferhunde hakan irmak mukerrem muslum tonguc
---

```cpp
--------------------------------------------------------;
```

popüler mülakat soruları
bir container'a nasıl ekleme yaparım
c.push_back()
c.emplace_back()
c.push_front()
c.insert()
c.emplace()
```cpp
--------------------------------------------------------;
```

Mapte key yerine pair tutuluyor.
```cpp
	using namespace std;
	map<int, string> mymap;
	Irand rand{ 0,999 };
	for (int i = 0; i < 10; ++i)
	{
		mymap.insert(make_pair(rand(), random_name()));


	}
	for (const auto& p : mymap)
	{
		cout << p.first << "  " << p.second << '\n';
	}
```

75  Oyku
138  Kemal
224  Esra
243  Turan
378  Selim
383  Bulut
408  Naz
717  Bulut
866  Sinan
871  Perihan
```cpp
--------------------------------------------------------;
	using namespace std;
	map<int, string> mymap;
	Irand rand{ 0,999 };
	for (int i = 0; i < 10; ++i)
	{
		mymap.insert(make_pair(rand(), random_name()));


	}
	for (const auto& p : mymap)
	{
		cout << p.first << "  " << p.second << '\n';
	}
	cout << "anahtari girin : ";
	int key;
	string value;

	cin >> key >> value;

	if (auto iter = mymap.find(key); iter != mymap.end())
	{
		cout << "bulundu !";

		iter->second = value;
		cprint(mymap);
	}

--------------------------------------------------------;


int main() {

	using namespace std;
	map<int, string> mymap;
	Irand rand{ 0,999 };

	mymap.insert(pair<int, string>{12, string{ "ali" }});
	mymap.insert(pair{ 23,"ali"s });
	mymap.insert(make_pair(65, "canan"s));
	mymap.emplace(98, "suleyman");
	mymap.insert(pair{ 12,"mert"s });
	mymap.insert(pair{ 23,"suheyla"s });

	for (const auto& [id, name] : mymap)
	{
		cout << id << " " << name << '\n';
	}

	return 0;
}
```

12 ali
23 ali
65 canan
98 suleyman
```cpp
--------------------------------------------------------;


	using namespace std;

	vector<int> ivec;
	rfill(ivec, 40, Irand{ 0,99 });
	cprint(ivec);
	set<int> myset(ivec.begin(), ivec.end());
	cprint(myset);
	return 0;
```

33 78 31 21 37 18 94 72 36 24 52 61 60 53 82 7 78 89 65 53 70 94 13 73 45 85 94 36 66 37 90 4 74 84 57 92 27 75 16 90
4 7 13 16 18 21 24 27 31 33 36 37 45 52 53 57 60 61 65 66 70 72 73 74 75 78 82 84 85 89 90 92 94
```cpp
--------------------------------------------------------;
    using namespace std;

    map<int, string> mymap{
        {12, "muharrem"},
        {14, "selim"},
        {23, "ayla"},
        {34, "kadir"},
        {98, "burcin"},
    };

    cout << "eski ve yeni anahtarlari girin: ";

    int oldkey, newkey;
    cin >> oldkey >> newkey;

    if (auto iter = mymap.find(oldkey); iter != mymap.end()) {
        std::cout << "bulundu\n";

        auto value = iter->second;

        mymap.erase(iter);

        mymap.emplace(newkey, value);
        cprint(mymap, "\n");
    }
```

eski ve yeni anahtarlari girin: 14 88
bulundu
12: muharrem
23: ayla
34: kadir
88: selim
98: burcin
veya
```cpp
    if (auto iter = mymap.find(oldkey); iter != mymap.end()) {
        std::cout << "bulundu\n";

        auto handle = mymap.extract(iter);
        handle.key() = newkey;
        mymap.insert(move(handle));
        cprint(mymap, "\n");
    }
```

eski ve yeni anahtarlari girin: 14 9991
bulundu
12: muharrem
23: ayla
34: kadir
98: burcin
9991: selim
```cpp
--------------------------------------------------------;

   map<int, string> mymap{
        {12, "muharrem"},
        {14, "selim"},
        {23, "ayla"},
        {34, "kadir"},
        {98, "burcin"},
    };

    cout << "eski ve yeni anahtarlari girin: ";

    int key ;
    string value;
    cin >> key >> value;

    mymap[key] = value;
    cprint(mymap, "\n");
```

eski ve yeni anahtarlari girin: 12 bacolii
12: bacolii
14: selim
23: ayla
34: kadir
98: burcin
eski ve yeni anahtarlari girin: 88 naber
12: muharrem
14: selim
23: ayla
34: kadir
88: naber
98: burcin
```cpp
--------------------------------------------------------;

--------------------------------------------------------;

--------------------------------------------------------;

--------------------------------------------------------;

--------------------------------------------------------;
```
