# 31. ders

---

kaplarda doğrudan referans tutulamaz.
	kaplarda pointer değişkenler tutulabilir (raw pointer)
	kaplarda smart pointer değişkenler tutulabilir
	unique_ptr
	reference_wrapper
Normal olarak taban sınıfın
sanal fonksiyonunu override eden
türemiş sınıf fonksiyonu
	taban sınıf fonksiyonu ile aynı imzaya sahip
	ve aynı geri dönüş türüne sahip olmalı.
	eğer g.d.d türü farklı olursa kod gecersiz olur.
bir taban sınıfın sanal fonksiyonunn bildirimi şöyle olsun:
```cpp
class Base{

virtual B* foo();
virtual B& bar();
};
```

eğer D sınıfı B sınıfının bir (public türeöiş sınıfı ise)
```cpp
class B{}
class D: public B{}



class B{

};

class D:public B{
};

class Base {
public:
	virtual B* foo();
	virtual B& bar();

};

class Der :public Base {
	public:
	 D* foo()override;  // D de B de geçerli olur.
	 D& bar()override;

};
```

RTTI
	runtime type information
	runtime type identification
	programın çalışma zamanının bir  nesnenin dinamik türünün belirlenmesi
```cpp
static_cast
```

	const_cast
```cpp
		reinterpret_cast
```

			dynamic_cast
dynamic_cast op.
down-casting'in güvenli  bir biçimde yapılıp yapulamayacağını kontrol eder.
typeid
 type_info
 upcasting
 downcasting
cross-cast
	multiple interitance
```cpp
dynamic_cast<Der*>(base_ptr);
```

Dikkat!
dynamic_cast op. kullanılabilmesi için
operand olan ifadenin polimorfik bir türden olması gerekir.
```cpp
Der* deptr = dunamic_cast<Der*>(base_ptr);

if(derptr != nullptr){
	// down-casting başarılı)
	derptr->foo();
	}

	for (size_t i = 0; i < 100; i++)
	{
		Car* carptr = create_random_car();
		carptr->start();
		carptr->run();
		if(Honda* h = dynamic_cast<Honda*>(carptr))
		{
			h->open_sunroof();
			(void)getchar();
		}
	}

typedeid(x)
typedeid(*ptr)
typedeid(10)

std::type_info sınıfı türünden bir nesne kullanmanın tek yolu

typeid operatorü kullanmaktır.

class Myclass {};
struct Neco {};

int main()
{

	using namespace std;
	int x = 5;
	int* ptr{ &x };

	Myclass m;
	Neco nec;

	std::cout << typeid(x).name() << '\n';
	std::cout << typeid(ptr).name() << '\n';
	std::cout << typeid(*ptr).name() << '\n';
	std::cout << typeid(m).name() << '\n';
	std::cout << typeid(nec).name() << '\n';


	return 0;
}

int
int * __ptr64
int
class Myclass
struct Neco

```

---

```cpp
class Base {
public:
	/*virtual void foo(){}*/
};

class Der : public Base {
};

int main()
{

	Base* base_ptr = new Der();

	std::cout << typeid(*base_ptr).name() << "\n";
	std::cout << std::boolalpha << (typeid(*base_ptr) == typeid(Der)) << "\n";



	return 0;
}
class Base
```

false
polimorfik olmayan türlerde runtime type information (RTTI)
	çalışma zamanında tür bilgisi sağlanmaz.
```cpp
class Base {
public:
	virtual void foo(){}
};

class Der : public Base {
};
```

polimorfik türlerde RTTI çalışır.
```cpp
class Der
```

true
