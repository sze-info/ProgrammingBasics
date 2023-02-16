#include <stdio.h>

long power(int base, unsigned exponent) {
  long result;
  if(exponent == 0) return 1;
  if(exponent == 1) return base;
  result = power(base, exponent/2);
  result *= result; // We don't invoke it twice!
  if(exponent%2 == 1) result *= base;
  return result; }

int main(void) {
  int b; unsigned e;
  printf("Power\nBase: "); scanf("%d", &b);
  printf("Exponent: "); scanf("%u", &e);
  printf("Result: %ld\n", power(b, e));
  return 0; }
