#include <stdio.h>

int main(void) {
  double v, abs;
  printf("Number: "); 
  scanf("%lf", &v);
  printf("Absolute value: ");
  
  
  if(v < 0.) abs = -v;
  else abs = v;
  
  
  printf("%f\n", abs);
  return 0;
}
