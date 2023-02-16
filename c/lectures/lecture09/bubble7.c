#include <stdio.h>
#include <stdlib.h>

int* read(int* used) {
  int current, total = 1;
  printf("\t[Initial memory allocation]\n");
  int* numbers = (int*)malloc(total * sizeof(int));
  *used = 0;
  do {
    printf("\t[Used: %d, Array size: %d]\n", *used, total);
    printf("Number #%d: ", *used + 1);
    scanf("%d", &current);
    if(current >= 0) {
      if(*used == total) {
        printf("\t[Memory re-allocation]\n");
        total *= 2;
        numbers = (int*)realloc(numbers, total*sizeof(int));
      }
      numbers[*used] = current;
      (*used)++;
    }
  } while(current >= 0);
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
  int used; // Number of currently used array elements
  int* numbers; // Address of the array
  printf("Enter non-negative numbers\n");
  numbers = read(&used);
  bubble(numbers, used);
  printf("After sorting:\n");
  printArray(numbers, used);
  free(numbers);
  return 0;
}
