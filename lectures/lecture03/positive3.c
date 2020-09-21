#include <stdio.h>

int main(void) {
  int number; // no need to initialize it to
  do {        // execute the loop body at least once
    printf("Enter a positive number! ");
    scanf("%d", &number);
  } while(number <= 0);
  printf("Read value: %d\n", number);
  return 0;
}
