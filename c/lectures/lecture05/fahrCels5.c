#include <stdio.h>

int main(void) {
  printf("Fahrenheit --> Celsius\n"
         "Fahrenheit: ");
  double f;
  scanf("%lf", &f);
  // Pointless type casting
  printf("Celsius: %f\n", (double)(5/9)*(f-32.)); 
  return 0;
}
