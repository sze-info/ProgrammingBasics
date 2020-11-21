#include <stdio.h>

#define SQUARE(x) x*x

int main(void) {
  printf("%d^2=%d\n", 3, SQUARE(3));     // 3*3 = 9
  printf("%d^2=%d\n", 3+1, SQUARE(3+1)); // 3+1*3+1 = 7
  return 0;
}
