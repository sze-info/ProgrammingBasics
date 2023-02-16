#include <stdio.h>
#include <iso646.h>  // and, or, not
#include <stdbool.h> // bool
int main(void) {
  int a, b, c;
  bool valid = false; // more expressive type/value
  printf("Enter the sides of a triangle!\n");
  do {
    do { // start of the loop body
      printf("Length of side A: "); scanf("%d", &a);
    } while(a <= 0); // end of the loop
    do {
      printf("Length of side B: "); scanf("%d", &b);
    } while(b <= 0);
    do {
      printf("Length of side C: "); scanf("%d", &c);
    } while(c <= 0);
    if(a+b<=c or b+c<=a or c+a<=b) // or
      printf("The triangle is invalid!\n");
    else {
      valid = true; // more expressive logical value
      printf("The triangle is valid.\n"); }
  } while(not valid); // not
  return 0; }
