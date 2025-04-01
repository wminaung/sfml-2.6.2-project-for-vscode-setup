#include <iostream>

extern "C" int my_add(int a, int b);
extern "C" int my_subtract(int a, int b);

int main() {

  std::cout << my_add(2, 3) << std::endl;
  std::cout << my_subtract(2, 3) << std::endl;
}

// g++ test.cpp && ./a.exe
// g++ -c test.cpp -o test.o
// - or -
// g++ -O3 -march=native test.cpp && ./a.exe
// */

/*

//// static library example ////
g++ -shared -o mmath.dll mmath.cpp
ar rcs libmmath.a mmath.o
g++ test.cpp -o test -L. -lmmath


//// dynamic library example ////
________________________________________
#include <iostream>
extern "C" int my_add(int a, int b);
extern "C" int my_subtract(int a, int b);
int main() {
  std::cout << my_add(2, 3) << std::endl;
  std::cout << my_subtract(2, 3) << std::endl;
}
________________________________________
#include <iostream>
extern "C" __declspec(dllexport) int my_add(int a, int b) {
  //
  return a + b;
};

extern "C" __declspec(dllexport) int my_subtract(int a, int b) {
  //
  return a - b;
  ;
};
________________________________________

g++ -fPIC -c mmath.cpp -o mmath.o
g++ -shared -o libmmath.so mmath.o
g++ test.cpp -o test -L. -lmmath

*/
