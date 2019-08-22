# COMP6771 19T2   Advanced C++ Programming
When would we specialise classes? Why do we not specialise functions?
Define your own type trait, from scratch, for is_a_pointer, to be used in an application like this

```cpp
template <typename T>
printPointer(T t) {
  if (traits::is_a_pointer<T>::value) {
  	std::cout << *t << "\n";
  } else {
  	std::cout << t << "\n";
  }
}
```

Ensure that your type trait is wrapped in a trait namespace.
Use type traits in the std namespace to produce your own composition type trait that returns true if the type passed in is an integer or floating point. It should be used as follows
template <typename T>
if (is_real_number<T>::value) {
  std::cout << "Is real number" << "\n";
}
What is an xvalue?
What is an prvalue?
What are the inferred types for each of the following?
int main() {
	int i = 5;
    int& k = i;

	decltype(i) x;
    decltype(k) y;
    decltype(std::move(i)) z;
    decltype(4.2);
	
}
What does the binding table for lvalues/rvalues look like?
This code currently doesn't work as the implementation for my_make_unique is incomplete. Complete it through the addition of using std::forward as well as variadic types.
template <typename T>
auto my_make_unique(T item) {
  return std::unique_ptr<T>{new T{item}};
}

int main() {
  MyClass myClass{"MyClass"};
  std::cout << *my_make_unique<MyClass>(myClass) << "\n";
  std::cout << *my_make_unique<MyClass>(std::move(myClass)) << "\n";
  NonCopyable nonCopyable{"NonCopyable"};
  std::cout << *my_make_unique<NonCopyable>(std::move(nonCopyable)) << "\n\n";

  // Use the size constructor.
  std::cout << my_make_unique<std::vector<MyClass>>(5U)->size() << "\n";

  // Use the size-and-value constructor.
  MyClass base{"hello"};
  std::cout << my_make_unique<std::vector<MyClass>>(6U, base)->size() << "\n";
}
Convert this normal C++ program using constexpr to a program using template meta-programming
#include <iostream>

constexpr int factorial (int n) {
  if (n <= 1) {
  	return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  std::cout << factorial(6) << std::endl;
}
