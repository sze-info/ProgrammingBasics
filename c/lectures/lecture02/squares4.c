#include<stdio.h>
int main(void) {
  int base;
  printf("Squares of natural numbers\n\n");
  base = 1;
  while(base <= 10) {
    printf("%d^2=%d\n", base, base*base);
    base = base + 1;
  }
  return 0;
}
