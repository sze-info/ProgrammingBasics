#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <iso646.h>

int read(int max) {
  int number;
  bool invalid;
  do {
    printf("Number: "); scanf("%d", &number);
    invalid = number<1 or number>max;
    if(invalid) printf("Invalid data!\n");
  } while(invalid);
  return number;
}

unsigned long factorial(int n) {
  if(n < 2) return 1;
  return n * factorial(n-1);
}

unsigned long combination(int n, int k) {
  return factorial(n) / (factorial(k)*factorial(n-k));
}

int main(void) {
  int n = read(INT_MAX);
  int k = read(n);
  printf("%lu\n", combination(n, k));
  return 0; 
}
