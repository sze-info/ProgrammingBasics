#include <stdio.h>
#define N 5
int main(void) {
  printf("Enter %d numbers. The program prints them in reverse order.\n\n", N);
  int numbers[N], quantity;
  for(quantity=0; quantity<N; quantity++) {
    printf("Number %d: ", quantity+1);
    scanf("%d", &numbers[quantity]);
  }
  
  printf("\nIn reverse order:\n");
  for(quantity=N-1; quantity>=0; quantity--) {
    printf("%d\t", numbers[quantity]);
  }
  
  
  printf("\n");
  return 0;
}
