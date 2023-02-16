#include <stdio.h>

int main(void) {
  int number = -1;     // the initialization forces
  while(number <= 0) { // the execution of loop body
    printf("Enter a positive number! ");
    scanf("%d", &number);
  }
  printf("Read value: %d\n", number);
  return 0;
}
