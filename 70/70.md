# MUTEX WRAPPING RAII CLASSES

1 lock guard
2 unique lock
3 scoped lock
4 shared lock
---

```cpp
std::lock()
mtx.lock();
mtx.un lock();

```

---

bazı durumlarda raii nesnelerimizin şunları da sağlaması gerekiyor
defaultr - constructible
....... lg(???)
```cpp
unique_lock<mutex> lock(mtx,adopt_lock);
unique_lock<mutex> lock(mtx,try_lock);

unique_lock(mutex&);
unique_lock(mutex&,defer_lock_t);
unique_lock(mutex&,adopt_lock_t);
unique_lock(mutex&,try_to_lock_t);
unique_lock(mutex&,duration);
unique_lock(mutex&,time_point);


```

---

```cpp
lock()
try_lock()
try_lock_for()
try_lock_until()
unlock()
owns_lock()
operator bool

mutex* ptr = lg.release();
```

---

```cpp
std::shared_mutex mtx;

void read_data()
{
    std::shared_lock lock(mtx);
    std::cout << std::this_thread::get_id << " reading\n";
}

void write_data()
{
    std::unique_lock<std::shared_mutex> lock(mtx);
    std::cout << std::this_thread::get_id << " writing\n";
}

int main()
{
    using namespace std;

    std::vector<std::thread> vec(50);

    for (size_t i = 0; i < vec.size(); ++i) {
        if (i % 10 == 0)
            vec[i] = thread(write_data);
        else
            vec[i] = thread(read_data);
    }

    for (auto& t : vec)
    {
        t.join();
    }
}
```

00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B00007FF7ED57190B reading
 reading
00007FF7ED57190B reading
00007FF7ED57190B writing
00007FF7ED57190B writing
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B writing
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B00007FF7ED57190B reading
00007FF7ED57190B reading
 reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
 reading
00007FF7ED57190B writing
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B writing
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
00007FF7ED57190B reading
---

---

---

---

---

---
