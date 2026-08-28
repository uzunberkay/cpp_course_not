# 18. DERS

=========
Containers
vector
deque
list
```cpp
forward_list
```

array
string
set
multiset
map
multi map
unordered_set
unordered_multiset
unordered_map
unordered_multi map
range-based for loop
```cpp
class Fighter {
public:
	Fighter(const std::string& name):name_(name)
	{
		fighters.push_back(this);
	}
```

	~Fighter()
```cpp
	{
		/*std::erase(fighters, this);*/
		if (auto iter = std::find(fighters.begin(), fighters.end(), this); iter != fighters.end())
		{
			fighters.erase(iter);
		}
	}
	Fighter(const Fighter&) = delete;
	Fighter& operator=(const Fighter&) = delete;
	void ask_help()
	{
		std::cout << "Arkadaslar ben savasci " << name_ << '\n';
		for (auto p : fighters)
		{
			if (p != this)
			{
				std::cout << p->name_ << " ";
			}
		}
		std::cout << "Yetisin\n";
	}
private:
	std::string name_;
	inline static std::vector<Fighter*> fighters;

};

int main()
{
	Fighter f1("necati");
	Fighter f2("furkan");
	Fighter f3("gizem");
	Fighter f4("ogulcan");

	Fighter* p1 = new Fighter("Osman");
	Fighter* p2 = new Fighter("Aysegul");
	Fighter* p3 = new Fighter("Nihat");

	f3.ask_help();

	delete p1;
	delete p2;

	f1.ask_help();

}
```

Arkadaslar ben savasci gizem
necati furkan ogulcan Osman Aysegul Nihat Yetisin
Arkadaslar ben savasci necati
furkan gizem ogulcan Nihat Yetisin
===============================
named constructor idiom
isimlendirilmiş ctor
yalnızca dinamik ömürlü nesneler
```cpp
class Complex {
public:
```

	static Complex create_cartesian(double r, double i)
```cpp
	{
		return Complex{ r,i };
	}
```

	static Complex create_polar(double angle, double distance)
```cpp
	{
		return Complex{ angle,distance,0 };
	}


private:
	Complex(double r, double i)
	{
		std::cout << "Complex(double r, double i)\n";
	}
	Complex(double angle, double distance, int)
	{
		std::cout << "Complex(double angle, double distance, int)\n";
	}
};

int main()
{
	Complex a = Complex::create_cartesian(3, 5);


}
```

=============================================================
```cpp
int*
```

Fighter*
raw pointer
naked pointer
aslında kendisi bir sınıf nesnesi olan
	bir pointer gibi kullanılan
		pointer interface
```cpp
*ptr
++ptr;
--ptr;
ptr[n];
```

iterator
smart pointer
	uinique_ptr
	shared_ptr
```cpp
	class Singleton {
public:
	void foo();
	void bar(int);
	void baz(double);
```

	static Singleton& instance()
```cpp
	{
		static Singleton s;

		return s;
	}
private:
	inline static Singleton* sp{};
	Singleton()
	{
		std::cout << "Singleton ctor\n";

	}
};

int main()
{
	Singleton cx = Singleton::instance();


}
```

==============
Dinamik ögeler
===
new expression(s)
delete expression(s)
new Fighter
delete Fighter
Bir keyword bunlar.
```cpp
new expressipon - new operator
operator new
```

delete expr.
```cpp
operator delete
```

	new Myclass
```cpp
	//   static_cast<Myclass*>(operator new(sizeof(Myclass))).Myclass();


class Myclass {

public:
	Myclass() {
		std::cout << "Def. ctor \n";
	}
	void foo();
	void bar();
	void baz();
};

int main()
{
	Myclass* p = new Myclass;

}
```

eğer new ifadesi ile oluturugumuz sınıf nesnesini
ilgili delete ifadesi ile sonlandırmaz isek
1) destructor çağrılmayacak.
```cpp
2) operator delete çağrılmayacak

new expression ==> operator new() + constructor
delete expresion ==> destructor + operator delete


class Myclass {

public:
	Myclass() {
		std::cout << "constructor. this = " << this << '\n';
	}
```

	~Myclass()
```cpp
	{
		std::cout << "destructor. this = " << this << '\n';
	}

	void foo()
	{
		std::cout << " Myclass::foo. this =  " << this << '\n';
	}

};

int main()
{
	{
		Myclass* p = new Myclass;
		std::cout << "P =  " << p << '\n';
		p->foo();

		delete p;
	}



	std::cout << "Main devam ediyor\n";

}
constructor. this = 00000154653D79B0
P =  00000154653D79B0
 Myclass::foo. this =  00000154653D79B0
destructor. this = 00000154653D79B0
```

Main devam ediyor
!!!! EĞER DELETE yapmazsam destructor çağrılmıyor.
```cpp
class Myclass {

public:
	Myclass() {
		std::cout << "constructor. this = " << this << '\n';
	}
```

	~Myclass()
```cpp
	{
		std::cout << "destructor. this = " << this << '\n';
	}

	void foo()
	{
		std::cout << " Myclass::foo. this =  " << this << '\n';
	}
private:
	char buf[16];
};

int main()
{
	std::cout << "enter the size of  the array ";
	std::size_t n;
	std::cin >> n;

	Myclass* p = new Myclass[n];
	std::cout << "p =  " << p << '\n';
	(void)getchar();

	delete[] p;


}
```

enter the size of  the array 12
```cpp
constructor. this = 0000019139A590F8
constructor. this = 0000019139A59108
constructor. this = 0000019139A59118
constructor. this = 0000019139A59128
constructor. this = 0000019139A59138
constructor. this = 0000019139A59148
constructor. this = 0000019139A59158
constructor. this = 0000019139A59168
constructor. this = 0000019139A59178
constructor. this = 0000019139A59188
constructor. this = 0000019139A59198
constructor. this = 0000019139A591A8
p =  0000019139A590F8
destructor. this = 0000019139A591A8
destructor. this = 0000019139A59198
destructor. this = 0000019139A59188
destructor. this = 0000019139A59178
destructor. this = 0000019139A59168
destructor. this = 0000019139A59158
destructor. this = 0000019139A59148
destructor. this = 0000019139A59138
destructor. this = 0000019139A59128
destructor. this = 0000019139A59118
destructor. this = 0000019139A59108
destructor. this = 0000019139A590F8
```

==============================================
