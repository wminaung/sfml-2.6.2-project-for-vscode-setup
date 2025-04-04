#include <iostream>

int main() {
  int a = 5;

  std::cout << *&a << std::endl;
}

// g++ g.cpp && ./a.exe