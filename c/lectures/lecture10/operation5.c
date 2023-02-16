#include <stdio.h>

#define SQUARE(x) ((x)*(x))
#define ADD(x,y) ((x)+(y))

int add(int x, int y) {
    return x + y;
}

int main(void) {
  printf("%d^2=%d\n", 3, SQUARE(3));
  printf("%d^2=%d\n", 3+1, SQUARE(3+1));
  printf("1+2=%d\n", ADD(1, 2));       // ((1)+(2))=3
  printf("4*(1+2)=%d\n", 4*ADD(1, 2)); // 4*((1)+(2))=12
  printf("4*(1+2)=%d\n", 4*add(1, 2)); // 4*(1+2)=12
  return 0;
}
