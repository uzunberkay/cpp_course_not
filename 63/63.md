# flush

to flush stream
```cpp
cout.flush();
ofs.flush();
```

tie
bağlamak
bir giriş akımı bir çıkış akımına bağlanırsa
o giriş akımında bir okuma işlemi yapıldığında
önce onun bağlandığı çıkış akımı buffer'ıo flush edilir
```cpp
int main()
{

    using namespace std;
    int x;
    cout << "bir sayi girin : ";


}







```

---

```cpp
    using namespace std;
    int x;

    ostream* op = cin.tie();
    cout << "op = " << op << '\n';
    cout << &cout << '\n';
op = 00007FF9BD47B040
```

00007FF9BD47B040
---

file operations
```cpp
istream     ==>     isstringstream
ostream     ==>     osstringstream
iostream    ==>     stringstream

```

---

```cpp
istream     ==> ifstream
ostream     ==> ofstream
iostream    ==> fstream
```

---

dosya işlemileri, derken ne kast edilişr
dosyadan okuma yapmak
dosyaya yazmak
file pointer (dosya konum göstericisi)
---

ftell
fseek
fsetpos
fgetpos
rewind
---

file pointer
    sequential access
    random access
dosya açış modları
    read
    write
```cpp
    append (sona ekleme)
```

text
binary
   FILE* fopen(const char* name , const char* openmode)
   "r"
   "w"
   "w+"
   "a+"
   "ab+
---

```cpp
 #include<fstream>

int main()
{

    using namespace std;
    ifstream ifs("main.cpp", ios::binary | ios_base::ate);


}

```

---

```cpp
    ofstream("ahmet.txt");
    ofstream{"ahmet.txt", ios_base::out | ios_base::trunc};
```

    aynılar
---

```cpp
    using namespace std;
    ofstream file("furkan.txt");

    file << "bugun gunlerden cuma\n";

```

---

  bir file stream nesnes i şu ili stateten birinde olçabilir
  a) bir dosya ile ilişkilendirilmiştir
  b) bir dosyanın sahibideğil
    default ctor edilmiş ve open fonk. çağrılmamış
    close
---

```cpp
    using namespace std;
    ifstream ifs;
    if (ifs.is_open())
    {
        cout << "evet dosya sahibi\n";

    }
    else
    {
        cout << "hayir dosya sahibi degil\n";
    }
```

    hayir dosya sahibi degil
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
