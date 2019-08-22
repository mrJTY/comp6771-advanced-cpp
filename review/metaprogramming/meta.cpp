#include <iostream>

int factorial(int n){
  return n > 0 ? n * factorial(n-1) : 1;
}

int main(){
  int a = factorial(6);
  std::cout << a << std::endl;
}

