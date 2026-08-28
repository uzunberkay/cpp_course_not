# 67

---

```cpp
cout << system_clock::now().time_since_epoch().count() << '\n';
```

17875492623833093
---

```cpp
cout << duration_cast<seconds>(system_clock::now().time_since_epoch()).count() << '\n';
```

1787549319
---

```cpp
cout << duration_cast<days>(system_clock::now().time_since_epoch()).count() << '\n';
```

20689
---

```cpp
   std::mt19937 eng(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch()).count());
```

---

```cpp
initializer_list<int> list{ 1,3,6,7,9 };
```

---

```cpp
constexpr auto  sz = sizeof(initializer_list<int>); 8
```

---

```cpp
    // eskiden
    const int ar[] = { 2,6,8,9,1,3 };
    std::vector<int> ivec(ar, ar + sizeof(ar) / sizeof(*ar));
    for (int i : ivec)
    {
        std::cout << i << " ";
    }
```

2 6 8 9 1 3
---

```cpp
std::initializer_list<int> foo()
{
    return { 1,2,3,4 };
}
```

dangling pointer olacak
---

```cpp
void xyz_array(const int* p, size_t size)
{
    while (size--)
    {
        printf("%d ", *p++);
    }
    printf("\n");
}


int main()
{


    constexpr auto  sz = sizeof(initializer_list<int>);

    initializer_list<int> list{ 1,3,6,7,9 };

    xyz_array(list.begin(), list.size());
```

    1 3 6 7 9
---

thread nedir ve neden kullanılır  ?
aynı proses içinde aynı anda yürüyebilşen bağımsız iş gibi
```cpp
concurrency in c++
```

anthony williams
---

```cpp
#include<thread>

    thread t;
    // join
    // detach
```

task
iş parçacıgı
iş yükü
---

```cpp
    thread t;
    if (t.joinable())
    {
        cout << "joinable evet bir thread!\n";
    }
    else
    {
        cout << "hayir bir threadi temsil etmior \n";
    }
```

hayir bir threadi temsil etmior
---

```cpp
void foo()
{
    cout << "merhaba dunya ! \n";

}
int main()
{


    thread t{ foo };
    if (t.joinable())
    {
        cout << "joinable evet bir thread!\n";
    }
    else
    {
        cout << "hayir bir threadi temsil etmior \n";
    }
    t.join();
    if (t.joinable())
    {
        cout << "joinable evet bir thread!\n";
    }
    else
    {
        cout << "hayir bir threadi temsil etmior \n";
    }
}
```

joinable evet bir thread!
merhaba dunya !
hayir bir threadi temsil etmior
---

---

```cpp
#include<syncstream>

void foo(char c)
{
    for (int i = 0; i < 100'000; ++i)
    {
        std::osyncstream{ std::cout } << c;
   }
}
int main()
{


    thread t{ foo,'C'};
    thread t{ foo,'D'};
    thread t{ foo,'A'};
```

  CDCADCADCAACDACCCDDDDDDCAACDACCADDDDACCADDDDDCAACCADCAACDAADDAADCADCADDACDACDACDACDACDACDAC
  DACDACDACDACDACDACDDCAACDDCADDACDACDAADCADCADDACDACDACDACDACDAADCADCADCCDDCCDAADCADCADCADCADC
  CCADCADDACDACDACDACDACCADCADCADCADD
  ACDACDACDACDACDAAACCADCADCADCADCAACDACDDCCCADCADCADCCCADCAAAAADCAAADCADDACACCCCCC
---

join veya detach çağrılmazsa thrad nesnesini dtore çağrıldıgında
terminate çağrılacak.
---

---

---

---
