#include<stdio.h>

int main(void) {
  int number;
  number = 42;
  if(number%2 == 0) {
    printf("The number is even.\n");
  } else {
    printf("The number is odd.\n");
  }
  return 0;
}
