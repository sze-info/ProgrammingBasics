#include <stdio.h>

void swap1(int a, int b) {
  printf("swap1: address of 'a': %p, address of 'b': %p\n", &a, &b);
  printf("swap1: value of 'a': %d, value of 'b': %d\n", a, b);
  int temp = a;
  a = b;
  b = temp;
}

void swap3(int* a, int* b) {
  printf("swap3: address of 'a': %p, address of 'b': %p\n", &a, &b);
  printf("swap3: value of 'a': %p, value of 'b': %p\n", a, b);
  printf("swap3: value@address 'a': %d, "
         "value@address 'b': %d\n", *a, *b);
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a = 1, b = 2;
  printf("main: address of 'a': %p, address of 'b': %p\n", &a, &b);
  printf("main: value of 'a': %d, value of 'b': %d\n", a, b);
  swap1(a, b); 
  printf("main, after calling swap1: "
         "value of 'a': %d, value of 'b': %d\n", a, b);
  swap3(&a, &b);
  printf("main, after calling swap3: "
         "value of 'a': %d, value of 'b': %d\n", a, b);
  return 0;
}

