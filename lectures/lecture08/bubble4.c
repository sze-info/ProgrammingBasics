#include <stdio.h>

void bubble(int* a, int n) {
  for(int e=n-1; e>=1; e--) {
    for(int b=0; b<e; b++) {
      if(a[b] > a[b+1]) {
        int swap = a[b];
        a[b] = a[b+1];
        a[b+1] = swap;
      }
    }
  }
}

void printArray(const int* a, int n) {
  for(const int* end=a+n; a<end; a++) {
    printf("%d\t", *a);
  }
  printf("\n");
}

int main(void) {
  int numbers[] = {12, 3, 54, -4, 56, 4, 7, 3};
  int n = sizeof(numbers)/sizeof(numbers[0]);
  bubble(numbers, n);
  printf("After sorting:\n");
  printArray(numbers, n);
  return 0;
}
