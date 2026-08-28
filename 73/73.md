# 73

---

```cpp
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker()
{
    std::unique_lock<std::mutex> lock(mtx);

    while (!ready) {
        cv.wait(lock);
    }
}

void set_ready()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }

    cv.notify_one();
}

```

---

lock-free data structure
```cpp
notify_all_at_thread_exit(cv,)
```

thread1                 thread2
set
                         read
thread tx(foo)
operation
unlock
lock
happens-before
---

intra-thread relation
seuqenced before
```cpp
x= 10;
y = x + 20;
```

synchronizes with
---

```cpp
#include<atomic>

    atomic_int x;
    atomic<int> y;
    atomic z(10);
```

    aynı
---

```cpp
int main()
{
    using std::cout, std::atomic;

    cout << std::boolalpha;

    atomic<bool> flag_1;
    atomic<bool> flag_2;

    cout << "flag_1 = " << flag_1 << '\n';  // operator T
    cout << "flag_2 = " << flag_2 << '\n';  // operator T

    auto b_old = flag_1.exchange(true);

    cout << "b_old = " << b_old << '\n';
    cout << "flag_1 = " << flag_1 << '\n';  // operator T
    cout << "flag_1.load() = " << flag_1.load() << '\n';
    cout << "flag_2.load() = " << flag_2.load() << '\n';
}
flag_1 = false
flag_2 = false
b_old = false
flag_1 = true
```

flag_1.load() = true
flag_2.load() = false
---

```cpp
int main()
{
    using std::cout, std::atomic;

    cout << std::boolalpha;

    atomic x = 5;
    atomic y = 5;

    auto r1 = x += 2;
    auto r2 = y.fetch_add(2);


    cout << "r1 " << r1 << '\n';
    cout << "r2 " << r2 << '\n';

}
```

r1 7
r2 5
---

---

---

---

---

---

---

---
