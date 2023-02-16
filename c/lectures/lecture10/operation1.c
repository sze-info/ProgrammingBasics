#include <stdio.h>

int square(int x) {
  return x * x;
}

int main(void) {
  printf("%d^2=%d\n", 3, square(3));     // 3*3 = 9
  printf("%d^2=%d\n", 3+1, square(3+1)); // 4*4 = 16
  return 0;
}
