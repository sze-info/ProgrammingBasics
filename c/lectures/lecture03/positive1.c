#include <stdio.h>

int main(void) {
  int number;
  printf("Enter a positive number! ");   // message 1
  scanf("%d", &number);                  // reading 1
  while(number <= 0) { // repeat if input is erroneous
    printf("Enter a positive number! "); // message 2
    scanf("%d", &number);                // reading 2
  }
  printf("Read value: %d\n", number);
  return 0;
}
