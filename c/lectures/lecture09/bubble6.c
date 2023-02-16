#include <stdio.h>
#include <stdlib.h>

int* read(int* total) {
  printf("How many numbers do you want to sort? ");
  scanf("%d", total);
  int* numbers = (int*)malloc(*total * sizeof(int));
  for(int i=0; i<*total; i++) {
    printf("Number #%d: ", i + 1);
    scanf("%d", numbers + i); // &numbers[i]
  }
  return numbers;
}

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
  int total; // array size
  int* numbers = read(&total);
  bubble(numbers, total);
  printf("After sorting:\n");
  printArray(numbers, total);
  free(numbers);
  return 0;
}
