#include <string.h>

#include <iostream>

using namespace std;

struct test {
  char str1[20];
};

int main() {
  struct test st1, st2;
  strcpy(st1.str1, "Tutorial Point");
  st2 = st1;
  st1.str1[0] = 'X';
  st1.str1[1] = 'Y';
  /* Because copy was Deep, both arrays are different */
  cout << "st1's str = " << st1.str1 << endl;
  cout << "st2's str = " << st2.str1 << endl;
  return 0;
}