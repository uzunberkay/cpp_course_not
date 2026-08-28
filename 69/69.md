# 69

---

senkranizasyon
mutex kullanmak
atomik değişken kullanmak
race condition
data race
---

```cpp
std::mutex mtx;
void foo()
{
    std::lock_guard lg(mtx);
    std::cout << x << '\n';
}
void bar()
{
    std::lock_guard lg(mtx);
    x = 9999;
    std::cout << x << '\n';
}


int main()
{
      jthread t1(foo);
    jthread t2(bar);
    return 0;
}
```

0
9999
---

```cpp
int cnt = 0;

void func()
{
    for (unsigned int i = 0; i < 1'000'000; ++i) {
        ++cnt;
    }
}

int main()
{
    using namespace std;

    thread t1(func);
    thread t2(func);
    thread t3(func);
    thread t4(func);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "cnt = " << cnt << '\n';
}
cnt = 1455645
```

4 milyon beklerdik dimi ?
---

```cpp
std::mutex mtx;
void func()
{
    mtx.lock();
    for (unsigned int i = 0; i < 1'000'000; ++i) {
        ++cnt;
    }
    mtx.unlock();
}
```

yaparsak
```cpp
cnt = 4000000
```

---

live lock
```cpp
// MUTEX CLASSES

1 - std::mutex
2 - std::timed_mutex
3 - std::recursive_mutex
4 - std::recursive_timed_mutex
5 - std::shared_mutex
6 - std::shared_timed_mutex

```

---

```cpp
class Myclass {
public:
    void foo()
    {
        mtx.lock();
        //
        mtx.unlock();
    }

    void cf() const
    {
        mtx.lock();
        //
        mtx.unlock();
    }

    void bar()
    {
        mtx.lock();
        //
        mtx.unlock();
    }

private:
    mutable std::mutex mtx;
    //
};
```

---

```cpp
class DatabaseAccess {
public:
    void create_table()
    {
        db_mutex.lock();
        //...

        db_mutex.unlock();
    }

    void insert_data()
    {
        db_mutex.lock();
        //...

        db_mutex.unlock();
    }

    void create_table_and_insert_data()
    {
        db_mutex.lock();
        //...
        create_table();

        db_mutex.unlock();
        //...
    }

private:
    std::mutex db_mutex;
    //...
};

int main()
{
    DatabaseAccess dx;

    dx.create_table_and_insert_data(); // deadlock
}
```

---

```cpp
#include <mutex>
#include <iostream>

class Nec {
public:
    void func()
    {
        std::lock_guard guard{ mtx };
```

        std::cout << std::this_thread::get_id() << " func cagrildi\n";
```cpp
        foo();
        std::cout << std::this_thread::get_id() << " func sona eriyor\n";
    }

    void foo()
    {
        std::lock_guard guard{ mtx };
```

        std::cout << std::this_thread::get_id() << " foo cagrildi\n";
```cpp
    }

private:
    mutable std::mutex mtx;
};

void gf()
{
    Nec nec;

    nec.func();
}

int main()
{
    std::thread t1{ gf };
    std::thread t2{ gf };
}

```

---

---

---
