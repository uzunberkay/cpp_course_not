# removing algorithms

remove
remove_if
unique
silme işlemi yapmıyolar
logical remove
---

2 4 5 4 1 2 22
```cpp
int main() {

	using namespace std;

	vector<int> ivec = { 1,2,3,4,5,6,7,71,2,3,44,55,13 };
	print(ivec.begin(), ivec.end());
	cout << "Size = " << ivec.size() << " capacity =  " << ivec.capacity() << '\n';

	auto logic_end = remove(ivec.begin(), ivec.end(), 3);

	print(ivec.begin(), ivec.end());
	cout << "Size = " << ivec.size() << " capacity =  " << ivec.capacity() << '\n';





	return 0;
}
```

1 2 3 4 5 6 7 71 2 3 44 55 13
```cpp
Size = 13 capacity =  13
```

1 2 4 5 6 7 71 2 44 55 13 55 13
```cpp
Size = 13 capacity =  13

```

---

```cpp
	auto n_erased = distance(logic_end, ivec.end());

	cout << n_erased << " element removed!\n";
	Size = 13 capacity =  13
```

	2 element removed!
---

```cpp
	auto n_exists = distance(ivec.begin(), logic_end);
	cout << n_exists << " element removed!\n";
```

11 element removed!
---

```cpp
int main()
{
    using namespace std;

    vector<string> vec;
    rfill(vec, 100, random_name);
    cprint(vec);
```

    vec.erase(
        unique(vec.begin(), vec.end(),
            [](const auto& s1, const auto& s2)
```cpp
            {
                return s1.front() == s2.front();
            }),
```

        vec.end()
```cpp
    );

    cprint(vec, " ");
}
```

---

```cpp
int main()
{
    using namespace std;

    vector<Date> vec;
    rfill(vec, 1000, Date::random);

    list<Date> ls;

    int mon;
    std::cout << "enter the month: ";
    cin >> mon;
```

    remove_copy_if(vec.begin(), vec.end(), back_inserter(ls),
        [mon](const Date& dt)
```cpp
        {
            return dt.month() > mon;
        });

    cprint(ls, "\n");
}
```

---

```cpp
	using namespace std;

	string str{ "her goren agladi kalbini bagladi ankara ruzgarina" };

	replace_copy(str.begin(), str.end(), ostream_iterator<char>(cout), 'a', '*');
```

    her goren *gl*di k*lbini b*gl*di *nk*r* ruzg*rin*
---

```cpp
	using namespace std;

	string str{ "2313fasfas123fzxvxzvlzl4124123i591281" };
```

	replace_copy_if(str.begin(), str.end(), ostream_iterator<char>(cout),
```cpp
		[](char c) {return isdigit(c); }, '?');
```

????fasfas???fzxvxzvlzl???????i??????
---

sorting algorithms
sort
partial_sort
stable_sort
stable_sort
nth_element
partition
stable_partition
partition_copy
partition_pointer
is_sorted
is_sorted_until
is_parititioned
```cpp
// heap algorithms



```

---

```cpp
int main()
{
    using namespace std;

    vector<int> ivec;
    rfill(ivec, 10000, Irand{ 0, 999999 });
    sort(ivec.begin(), ivec.end());
    sort(ivec.begin(), ivec.end(),[](int x , int y){return x>y;});
```

    2 overload var
```cpp
    std::ofstream ofs{ "out.txt" };
    if (!ofs) {
        std::cerr << "out.txt dosyasi olusturulamadi\n";
        exit(EXIT_FAILURE);
    }

    cprint(ivec, "\n", ofs);
}


```

---

```cpp
	using namespace std;
	list mylist{ 12,24,5,4,1,-5,-45 };

	cout << boolalpha;
```

	cout << is_sorted(mylist.begin(), mylist.end(), [](int x, int y)
```cpp
		{return x > y; });
```

false
---

```cpp
int main()
{
    using namespace std;

    vector vec{ 12, 45, 76, 98, 124, 692, 89, 12 };

    auto iter = is_sorted_until(vec.begin(), vec.end());

    if (iter != vec.end()) {
        cout << *iter << '\n';
        std::cout << "sorted range distance : " << iter - vec.begin() << '\n';

        copy(vec.begin(), iter, ostream_iterator<int>{ cout, " " });
    }
    else {
        std::cout << "the range is already sorted\n";
    }
}
```

89
sorted range distance : 6
12 45 76 98 124 692
---

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> ivec;

    // ivec içine 0 ile 10000 arasında rastgele 1000 tane int değer atar.
    rfill(ivec, 1000, Irand{ 0, 10000 });

    int n;

    cout << "ilk kac tanesi siralansin: ";
    cin >> n;

    // partial_sort:
    // ivec içindeki en küçük n elemanı bulur,
    // bu n elemanı sıralı şekilde vectorün başına yerleştirir.
    //
    // Parametreler:
    // 1) ivec.begin()      -> sıralanacak aralığın başlangıcı
    // 2) ivec.begin() + n  -> ilk n elemanın sıralı olacağı sınır
    // 3) ivec.end()        -> aralığın sonu
    partial_sort(ivec.begin(), ivec.begin() + n, ivec.end());

    // Vectorü ekrana yazdırır.
    cprint(ivec);
}
```

---

partition algorithms
bölümleme
kosulu sağlayanlar başta
kosulu sağlamayanlar sonda
---

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> ivec;

    // ivec içine 0 ile 999 arasında rastgele 30 tane int değer atar.
    rfill(ivec, 30, Irand{ 0, 999 });

    // Partition işleminden önce vectorü yazdırır.
    cprint(ivec);

    // partition:
    // Verilen koşulu sağlayan elemanları baş tarafa,
    // sağlamayan elemanları arka tarafa taşır.
    //
    // Buradaki koşul:
    // x % 2 == 0
    //
    // Yani çift sayılar başa,
    // tek sayılar sona alınır.
    auto iter = partition(ivec.begin(), ivec.end(),
        [](int x)
        {
            return x % 2 == 0;
        });

    // Partition işleminden sonra vectorü yazdırır.
    cprint(ivec);

    // iter, partition noktasını gösterir.
    // Yani çift sayıların bittiği,
    // tek sayıların başladığı ilk konumu gösterir.
    if (iter != ivec.end()) {
        cout << "the value at partition point is : " << *iter << '\n';
        cout << "idx for partition point : " << iter - ivec.begin() << '\n';
    }

    cout << "elements that satisfy the predicate\n";

    // Koşulu sağlayan elemanları yazdırır.
    // Bu örnekte bunlar çift sayılardır.
    copy(ivec.begin(), iter, ostream_iterator<int>{ cout, " " });
    std::cout << "\n";

    cout << "elements that don't satisfy the predicate\n";

    // Koşulu sağlamayan elemanları yazdırır.
    // Bu örnekte bunlar tek sayılardır.
    copy(iter, ivec.end(), ostream_iterator<int>{ cout, " " });
    std::cout << "\n";
}
```

Buradaki ana olay şu:
```cpp
auto iter = partition(ivec.begin(), ivec.end(),
    [](int x)
    {
        return x % 2 == 0;
    });
```

Bu kod `ivec` içindeki elemanları iki gruba böler:
```cpp
çift sayılar | tek sayılar
```

`partition` sıralama yapmaz. Yani çift sayıları kendi içinde küçükten büyüğe dizmez. Sadece koşulu sağlayanları başa, sağlamayanları sona toplar.
`iter` ise bu iki grubun ayrıldığı noktadır:
```cpp
ivec.begin()  -> iter       : koşulu sağlayanlar
iter          -> ivec.end() : koşulu sağlamayanlar
```

Bu örnekte:
```cpp
ivec.begin() - iter
```

arası çift sayılar,
```cpp
iter - ivec.end()
```

arası tek sayılar olur.
---

---

---

---

---

---

---
