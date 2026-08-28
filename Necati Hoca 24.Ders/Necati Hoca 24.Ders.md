# 24. Ders

---

nested tyoes
type member
member type
içsel türler
nested types
erg is a nested class of class Nec
```cpp
class Nec {
public:
	class Erg {

	};
};
int main()
{
	Nec::Erg obj;  nested class
```

1 class scopda
```cpp
class ile mantıksal bi ilişkisi var
```

enclosing class kendi nested class'inın private
bölümüne erişebilir mi ?
- Hayır erişemez.
```cpp
class Nec {
public:
	void necFunc()
	{
		Erg obj;
		obj.foo();

	}
private:
	class Erg {
		class Nec;
		void foo();

	};
};
```

erişemiyor fakat  Erg içinde Nec classi friend
olarak tanımlanırsa erişebilir.
-
```cpp
class Nec {
public:
	void necFunc()
	{
		Erg obj;
		obj.foo();

	}
private:
	class Erg {
		friend class Nec;
		void foo();

	};
};
```

-
```cpp
class Nec {
public:

private:
	void necFunc();
	class Erg {

		 void foo()
		 {
			 Nec n;
			 n.necFunc();
		}

	};
};
```

Bu legal xd.
nested class içinde enclosing class'in private bölümüne erişebilir.
---

```cpp
class Enc {
public:
	class Nested {
	public:
		Nested() = default;
		Nested(int val = 0) : value(val) {}
```

		Nested foo(int x)
```cpp
		{
			std::cout << "Value: " << value + x << std::endl;
			return Nested(x);
		}
	private:
		int value;
	};
};


int main()
{
	Enc::Nested n1(3);
	n1.foo(5);
	return 0;

}
```

---

has-a-relationtip
is-a-relation
```cpp
class Member {
public:
    Member() {
        std::cout << "Member default ctor\n";
    }

    ~Member() {
        std::cout << "Member dtor\n";
	}
};


class Owner {
public:
    Owner()
    {
		std::cout << "Owner default ctor\n";
    }
```

    ~Owner()
```cpp
	{
		std::cout << "Owner dtor\n";
	}
    Member mx;
};

int main()
{

    Owner a;

}
```

Member default ctor
Owner default ctor
Owner dtor
Member dtor
---
