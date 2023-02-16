#include <stdio.h>

void display(int a, int b) {
  printf("a = %d, b = %d\n", a, b);
}

void swap1(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

struct twoNumbers { int a, b; };

struct twoNumbers swap2(int a, int b) {
  struct twoNumbers temp = {b, a};
  return temp;
}

void swap3(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a = 1, b = 2;
  printf("Original values:\t"); display(a, b);
  swap1(a, b); printf("After swap1:\t\t"); display(a, b);
  struct twoNumbers tn = swap2(a, b); a = tn.a; b = tn.b;
  printf("After swap2:\t\t"); display(a, b);
  swap3(&a, &b); printf("After swap3:\t\t"); display(a, b);
  return 0;
}

