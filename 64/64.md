# 64

---

 wire format
```cpp
 struct Data{
 cjar c1;
 cjar c2;
 int x,

 };
 struct Data mydata = {12,56,89765};

 write(&mydata,1,sizeof mydata,f:);
```

 wire format
 offset
 0 char		1
 1 char		1
 2 int(BE)	4
---

bir dosyaya ilk bir milyon prime numbers
primes.txt
---

bir dosyayı text modunda açmak ile
	binary modda açmak arasında nasıl fark var
Windows işletim sisteminde
dosya text modunda açılırsa
	newline karakteri
	2byte olarak yazılır
	13 10
---

```cpp
int main()
{

    using namespace std;
    constexpr int n = 10000000;
    auto ofs = create_text_file("primes.txt");
    int x = 1;
    int prime_count = 0;
    ofs << left;
    while (prime_count < n)
    {
        if (is_prime(x))
        {
            if (prime_count && prime_count % 10 == 0)
                ofs << '\n';
            ofs << setw(12) << x;
            ++prime_count;
        }
        ++x;
    }


}
```

---

fseek
rewind
ftell
fsetpos
fgetpos
seekp
tellp
seekg
tellg
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

---

---

---

---
