#include <stdio.h>
#include <iso646.h>
#define MAX 5

int read(int* numbers) {
  int current, used = 0;
  do {
    printf("Number #%d: ", used + 1);
    scanf("%d", &current);
    if(current>=0 and used<MAX) {
      *(numbers + used) = current;
      used++;
    }
  } while(current>=0 and used<MAX);
  return used;
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
  int used; // Number of used array elements
  int numbers[MAX];
  printf("Enter non-negative numbers\n");
  used = read(numbers);
  bubble(numbers, used);
  printf("After sorting:\n");
  printArray(numbers, used);
  return 0;
}
