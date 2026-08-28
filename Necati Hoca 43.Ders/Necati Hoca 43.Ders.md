# iterator nedir ?

 öyle bir değişken olsun ki
 bir veri yapısındaki bir
 ögenin konumunu tutsun
```cpp
 template<typename Iter>
void print_range(Iter beg, Iter end)
{
	while (beg != end)
	{
		std::cout << *beg << ' ';
		++beg;
	}
	std::cout << '\n';


}



int main() {

	int ar[] = { 1,2,3,4,5,6,76,7,8,9 };
	std::vector<std::string> svec{ "necati","furkan","ramazan","umut" };
	std::list<double> dlist{ 1.1,2.2,3.3,4.4,5.5 };
	print_range(std::begin(ar), std::end(ar));
	print_range(std::begin(svec), std::end(svec));
	print_range(std::begin(dlist), std::end(dlist));




	return 0;
}
```

ÇIKTI:
1 2 3 4 5 6 76 7 8 9
necati furkan ramazan umut
1.1 2.2 3.3 4.4 5.5
|**********|********************|*************|*********|
```cpp
int main() {
	using namespace std;
	int ar[] = { 1,2,3,4,5,6,76,7,8,9 };
	reverse(begin(ar), end(ar));

	for (auto i : ar)
	{
		cout << i << " ";
	}

	return 0;
}
```

9 8 7 76 6 5 4 3 2 1
|**********|********************|*************|*********|
```cpp
iter = vec.end();
*iter -> ub
```

|**********|********************|*************|*********|
```cpp
neden modern C++ ile
```

begin ve end fonk geldi ?
 - diziler
|**********|********************|*************|*********|
input iterator
```cpp
++iter iter++
*iter
iter1 == iter2
```

iter1 != iter2
output iterator
```cpp
++iter iter++
*iter

forward iterator
```

input interface + output interface
bidirectional iterator
```cpp
	forward iterator +
	--iter
	iter--
```

random access iterator
iter2-iter1
iter[n]
iter + n
iter - n
random access iterator
|**********|********************|*************|*********|
vec.begin()  vec.end()
vec.cbegin()  vec.cend()
|**********|********************|*************|*********|
|**********|********************|*************|*********|
|**********|********************|*************|*********|
|**********|********************|*************|*********|
