#include <stdio.h>

long power(int base, unsigned exponent) {
  long result = 1;
  unsigned i;
  for(i=0; i<exponent; i++) {
    result *= base; }
  return result; }

int main(void) {
  int b; unsigned e;
  printf("Power\nBase: "); scanf("%d", &b);
  printf("Exponent: "); scanf("%u", &e);
  printf("Result: %ld\n", power(b, e));
  return 0; }
