# 74

---

```cpp
class AtomicCounter {
public:
    AtomicCounter() : m_c(0) {}
    AtomicCounter(int val) : m_c{ val } {}

    int operator++() { return ++m_c; }
    int operator++(int) { return m_c++; }

    int operator--() { return --m_c; }
    int operator--(int) { return m_c--; }

    int get() const { return m_c.load(); }

    operator int() const {
        return m_c.load();
    }

private:
    std::atomic<int> m_c;
};

AtomicCounter cnt;

void foo()
{
    for (int i = 0; i < 1'000'000; ++i) {
        ++cnt;
    }
}



int main()
{
    foo();
}

```

---

memory order
```cpp
namespace std{
enum class memory_order:
```

    relaxed,
    consume,
    acquire,
    release,
    acq_rel,
    seq_cst,
```cpp
   };
}
```

Dikkat!
    memory_order_release
    ve
    memory_order_acquire
acquaire-release
```cpp
atomic<bool> flag(false);


statement1;
statement2;
statement3;
```

<============================>
```cpp
    x.store(true,memory_order_release); publish;

```

---

```cpp
#include <atomic>
#include <cassert>

int data = 0;
std::atomic_bool flag{false};

void publisher()
{
    data = 42;
    flag.store(true, std::memory_order_relaxed);
}

void receiver()
{
    while (!flag.load(std::memory_order_relaxed))
        ;

    assert(data == 42);
}

int main()
{
    using namespace std;
}
```

---

---

---

---

---

---

---

---

---

---

---

---

---
