#include <stdio.h>
int main(void) {
  int a, b, c;
  int valid = 0; // logical false
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
    if(a+b<=c || b+c<=a || c+a<=b) // or --> ||
      printf("The triangle is invalid!\n");
    else {
      valid = 1; // logical true
      printf("The triangle is valid.\n"); }
  } while(!valid); // not --> !
  return 0; }
