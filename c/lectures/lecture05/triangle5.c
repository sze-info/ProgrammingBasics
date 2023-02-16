#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#define SIDES 3

int main(void) {
  double sideArray[SIDES]; // side lengths can be racional numbers, too
  int i;
  bool valid = false;
  printf("Enter the sides of a triangle!\n");
  do {
    i = 0;
    while(i < SIDES) {
      do {
        printf("Length of side %c: ", 'A'+i);
        scanf("%lf", &sideArray[i]);
      } while(sideArray[i] <= 0.); // floating-point literal
      i++;
    }
    valid = (sideArray[0]+sideArray[1]>sideArray[2] and 
             sideArray[1]+sideArray[2]>sideArray[0] and 
             sideArray[2]+sideArray[0]>sideArray[1]);
    // ternary operator
    printf("The triangle is %s.\n", (valid ? "valid" : "invalid"));
  } while(not valid);
  return 0; }
