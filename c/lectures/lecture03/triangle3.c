#include <stdio.h>
#include <iso646.h> // and, or, not
int main(void) {
  int a, b, c;
  printf("Enter the sides of a triangle in ascending order!\n");
  do {
    printf("Length of side A: ");
    scanf("%d", &a);
  } while(a <= 0);
  do {
    printf("Length of side B: ");
    scanf("%d", &b);
  } while(b < a);
  do {
    printf("Length of side C: ");
    scanf("%d", &c);
  } while(c<b or a+b<=c); // it could be || as well
  return 0;
}
