#include <iostream>

constexpr int factorial(int n){
  return n > 0 ? * factorial(n-1) : 1;
}

// Explicit specialisation when it is 0
template<>
struct Factorial<0> {
  static const long val = 1; // Must be a compile time 
}
