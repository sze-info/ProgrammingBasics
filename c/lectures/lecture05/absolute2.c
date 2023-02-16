#include <stdio.h>

int main(void) {
  double v, abs;
  printf("Number: "); 
  scanf("%lf", &v);
  printf("Absolute value: ");
  
  
  abs = v<0. ? -v : v;
  
  
  
  printf("%f\n", abs);
  return 0;
}
