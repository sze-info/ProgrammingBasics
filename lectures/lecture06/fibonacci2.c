#include <stdio.h>

unsigned long fibonacci(unsigned month) {
  if(month < 2) return month;
  return fibonacci(month-1)+fibonacci(month-2);
}

int main(void) {
  unsigned month;
  printf("Fibonacci sequence\nNumber of months: ");
  scanf("%u", &month);
  printf("Number of rabbit pairs: %lu\n", fibonacci(month));
  return 0; 
}
