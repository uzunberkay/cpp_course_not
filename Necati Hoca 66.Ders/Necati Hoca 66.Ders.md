# 66

---

<time.h>
chrono
ratio
kesir
 1 / 3
 2 / 7
---

 ratio<10,20>  ratioz<1,2>
---

1/10
1/10
1/1000
1/ 10 ^15
1
10
100
1000
10000
100000
---

```cpp
std::atto  = 1 / 10^18;
std::femto = 1 / 10^15;
std::pico  = 1 / 10^12;
std::nano  = 1 / 10^9;
std::micro = 1 / 10^6;
std::milli = 1 / 10^3;
std::centi = 1 / 10^2;
std::deci  = 1 / 10;

std::deca  = 10;
std::hecto = 100;
std::kilo  = 1000;
std::mega  = 10^6;
std::giga  = 10^9;
std::tera  = 10^12;
std::peta  = 10^15;
std::exa   = 10^18;
```

---

    ratio_add<ratio<2,3>,radio<3,4>>::num
---

clock
    system_clock
    steady_clock
    high_resolution_clock
time_point  class template
duration    class template
---

```cpp
{

    using namespace std;
    using namespace std::chrono;

    ;// su kadar tane saniyenin bu kesirden
```

    duration<int,milli>
---

```cpp
int main()
{

    using namespace std;
    using namespace std::chrono;

    ;// su kadar tane saniyenin bu kesirden
    using halfseconds = duration<int, ratio<1, 2>>;
    using dseconds = duration<double>;

    halfseconds x(7624);
    x.count();



}
```

---

```cpp
// duration türleri arasındaki dönüştürmek
```

coarse fine
---

timepoint
    bir clock'undan epoch değerinden geçen süre
---

```cpp
{
    using namespace std;

    using clock = std::chrono::system_clock;

    clock::time_point epoch{};

    std::time_t tt = clock::to_time_t(epoch);

    std::tm tm = *std::gmtime(&tt);

    cout << tm.tm_year + 1900;

    // std::tm tm = *std::localtime(&tt); // Yerel saat istersen

    // std::cout << std::put_time(&tm, "%Y-%m-%d %H:%M:%S UTC\n");
}
```

---

timepoint +
---

```cpp
int main()

{
    using namespace std;
    using namespace std::chrono;

    cout <<system_clock::now();
}
```

2026-08-23 11:10:46.8829499
---

---

---

---

---

---

---
