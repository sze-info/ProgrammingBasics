#include <stdio.h>
#include <stdbool.h>
int main(void) {
  int a, b, c;
  bool valid = false; // logikai tipus
  printf("Enter the sides of a triangle!\n");
  do {
    do { // start of the loop body
      printf("Length of side A: ");
      scanf("%d", &a);
    } while(a <= 0); // end of the loop
    do {
      printf("Length of side B: ");
      scanf("%d", &b);
    } while(b <= 0);
    do {
      printf("Length of side C: ");
      scanf("%d", &c);
    } while(c <= 0);
    if(a+b<=c || b+c<=a || c+a<=b) // logical OR
      printf("The triangle is invalid!\n");
    else {
      valid = true;
      printf("The triangle is valid.\n"); }
  } while(!valid);
  return 0; }
