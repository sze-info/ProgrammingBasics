#include<stdio.h>

int main(void) {
  int number;
  printf("Type an integer and the program decides "
         "is it even or odd.\n\n");
  scanf("%d", &number);
  if(number%2 == 0) {
    printf("The number is even.\n");
  } else {
    printf("The number is odd.\n");
  }
  return 0;
}
