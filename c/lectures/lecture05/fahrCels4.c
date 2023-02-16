#include <stdio.h>

int main(void) {
  printf("Fahrenheit --> Celsius\n"
         "Fahrenheit: ");
  double f;
  scanf("%lf", &f);
  // No conversion
  printf("Celsius: %f\n", (5./9.)*(f-32.)); 
  return 0;
}
