# 62

---

ios_base::goodbit
ios_base::failbit
ios_base::eofbit
ios_base::bad bit
---

```cpp
int main()
{

    using namespace std;

    cout << bitset<16>(cin.rdstate()) << '\n';

}
```

0000000000000000
---

```cpp
void display_state(std::ios& s)
{
    const auto state = s.rdstate();

    if (state == 0) {
        std::cout << "stream is ok!\n";
        return;
    }

    if (state & std::ios::failbit) {
        std::cout << "failbit is set!\n";
    }

    if (state & std::ios::eofbit) {
        std::cout << "eofbit is set!\n";
    }

    if (state & std::ios::badbit) {
        std::cout << "badbit is set!\n";
    }
}

int main()
{

    using namespace std;

    cout << "enter an integer :";
    int x{ 124 };

    cin >> x;

    display_state(cin);

}
```

enter an integer :bbbb
failbit is set!
```cpp
    if (!cin)
    {
        cout << "there is an error in cin state\n";

    }
    else
    {
        cout << "there is no error in cin state\n";
    }
```

enter an integer :aa
there is an error in cin state
---

istream manipulaters
cout << hex
cin >> hex
---

```cpp
int main()
{

    using namespace std;


    int x, y, z;
    cout << "uc sayi giriniz : ";
    cin >> hex >> x >> oct >> y>> dec >> z;
    cout << "X = " << x << '\n';
    cout << "y = " << y << '\n';
    cout << "z = " << z << '\n';
}
```

uc sayi giriniz : 126 126 126
```cpp
X = 294
y = 86
z = 126
```

---

bir giriş islemi herhangi bir nedenden basarisiz oldugunda
bir exception throw etmiyor.
---

osstringstream
```cpp
int main()
{

    using namespace std;


    int x = 345;
    string str = "alican";
    double dval = 45.98;
    ostringstream os;
    os << x << " " << str << "  "<< dval;
auto s = os.str();
cout << " [ " << s << " ]\n";
}
```

 [ 345 alican  45.98 ]
---

```cpp
int main()
{

    using namespace std;

    int day = 5, mon = 8, year = 1984;
    ostringstream oss;
    oss << setfill('0');
    oss << setw(2) << day << '-' << setw(2) << mon << '-' << year;
    cout << "[" << oss.str() << "]\n";
}
```

[05-08-1984]
---

```cpp
int main()
{

    using namespace std;

    int x = 123;
    double d = 9.12;
    cout << format("{:<12},{:^24}\n", x, d) << '\n';
}
```

123         ,          9.12
---

in memory input/output operation
---

---

---

---

---

---
