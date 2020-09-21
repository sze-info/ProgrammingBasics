#include <stdio.h>
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
  } while(c<b || a+b<=c);
  return 0;
}
