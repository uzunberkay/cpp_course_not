# 17. DERS

==========
Delegating ctor
birden fazla ctor var ve bu ctor'larin ortak bir kodu var.
Sinıfların static veri elemanlari  ve static üye fonksiyonlari
=================================================================
```cpp
//myclass.h
class Myclass {

	static int mx;
};


// myclass.c
int Myclass::mx = 10;

//myclass.h
class Myclass {
	int mx{};
	static int x;
	static int y;
	static int z;
};


// myclass.c



int main()
{

	using namespace std;

	constexpr auto sz = sizeof(Myclass);

	cout << sz;



}

Cevap : 4 ;
```

global değişkenler yerşne
sınıfların static veri elemanları kullanıyoruz (bazen)
```cpp
class Myclass {
public:
	static int s;
};

int Myclass::s;

int main()
{

	Myclass m1, m2, m3;
	m1.s = 5;
	m2.s++;
	m3.s *= 2;
	std::cout << "  S  =  " << Myclass::s << '\n';
}
  S  =  12
```

Yani Myclass sınıfının elemanlarının ortak bir global değişkeniymiş gibi...
=============================================================================
```cpp
class Myclass {

public:
	static int ms;
	static int g;
};
int Myclass::g = 21;
int g = 10;

int Myclass::ms = g;

int main()
{
	/*
	* !!! BU BIR MULAKAT SORUSU !!!
	* MS ÇIKTISI NEDİR ?
	* Cevap : 21.
	* İsim araması ilk class scope'da yapılıyormus.
	* o yüzden classdaki g yi alıyor.
	* int Myclass::ms = ::g; yapsaydık , :: ile global g yi alacaktık.
	*/
	std::cout << "MS = " << Myclass::ms << '\n';
}
```

=============================================================================
Sınıfların static üye fonksiyonlari
Sınıfın genel fonksiyonudur. Yani this falan kullanılamaz.
1) ctor/dtor static üye fonk. olamaz
```cpp
2) operator fonksiyonları (special / non special) static üye fonksiyon olamaz.
```

3) Sanal fonksiyonlar static olamazlar.
[
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
			std::erase(fighters, this);
		}
		void ask_help();
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

		f3.ask_help();

	}
```

	]
scope leakage (kapsam sızıntısı) idientiifiers
bir isim yalnızca o ismin kullanıldığı kod alanında bilinsin dışında bilinmesin.
