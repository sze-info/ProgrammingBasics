#include <stdio.h>

unsigned long fibonacci(unsigned month) {
  unsigned long i=0, j=1, k;
  if(month < 2) return month;
  for(unsigned n=1; n<month; n++) {
    k = i+j;
    i = j;
    j = k;
  }
  return k;
}

int main(void) {
  unsigned month;
  printf("Fibonacci sequence\nNumber of months: ");
  scanf("%u", &month);
  printf("Number of rabbit pairs: %lu\n", fibonacci(month));
  return 0; 
}
