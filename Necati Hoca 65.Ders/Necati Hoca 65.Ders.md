# 65

---

```cpp
basic_istream& seekg(pos_type pos);


basic_istream& seekg(off_type off , std::ios_base::seekdir dir);
```

---

```cpp
ifs.seekg(100,ios_base::end)
```

---

user defined literals
```cpp
literal operators



```

---

```cpp
??? operator""_x(long double);
??? operator""_x(unsigned long long);

```

---

unit birim
234.86_kg
---

```cpp
constexpr double operator""_mt(long double val)
{
    return static_cast<double>(val);
}


int main()
{

    auto distance = 784.12_mt;
    cout << distance;

}
```

784.12
---

```cpp
constexpr double operator""_mt(long double val)
{
    return static_cast<double>(val);
}
constexpr double operator""_cm(long double val)
{
    return static_cast<double>(val / 100);
}
constexpr double operator""_mm(long double val)
{
    return static_cast<double>(val / 1000);
}
constexpr double operator""_km(long double val)
{
    return static_cast<double>(val * 1000);
}

int main()
{

    auto distance = 0.032_km + 1.987_km + 23.865_cm + 23567.83_mm;

    cout << distance;
}
```

2042.81
---

strong types
```cpp
class meter{

};
```

---

```cpp
constexpr unsigned long long operator""_2(unsigned long long val)
{
    return val * val;
}
int main()
{

    auto distance = 924_2;

    cout << distance;
}
```

853776
---

type deduction
```cpp
auto
```

decltype
```cpp
decltyope(auto)

```

---

```cpp
class Myclass{};


int main()
{

    Myclass m;

    decltype(auto) y = m;  myclcass
    decltype(auto) y = (m);  myclcass&
    decltype(auto) y = move(m);  myclcass&&




}



```

---

---
