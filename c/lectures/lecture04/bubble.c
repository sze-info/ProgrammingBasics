#include <stdio.h>
int main(void) {
  int numbers[] = {12, 3, 54, -4, 56, 4, 7, 3};
  int n = sizeof(numbers)/sizeof(numbers[0]); // Calculating array size
  int e=n-1, b;
  while(e>=1) {
    b = 0;
    while(b<e) {
      if(numbers[b]>numbers[b+1]) {
        int swap = numbers[b];
        numbers[b] = numbers[b+1];
        numbers[b+1] = swap;
      }
      b++;
    }
    e--;
  }
  int i = 0;
  printf("After sorting:\n");
  while(i < n) {
    printf("%d\t", numbers[i]);
    i++;
  }
  printf("\n");
  return 0;
}
