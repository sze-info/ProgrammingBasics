#include <stdio.h>
#define N 5
int main(void) {
  printf("Enter %d numbers. The program prints them in reverse order.\n\n", N);
  int numbers[N], quantity=0;
  while(quantity < N) {
    printf("Number %d: ", quantity+1);
    scanf("%d", &numbers[quantity++]);    // merger
  }
  printf("\nIn reverse order:\n");
  while(quantity--) printf("%d\t", numbers[quantity]); // merger
  printf("\n");
  return 0;
}
