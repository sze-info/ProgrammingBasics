#include <stdio.h>

int main(void) {
  printf("Fahrenheit --> Celsius\n"
         "Fahrenheit: ");
  double f;
  scanf("%lf", &f);
  // Implicit type conv.
  printf("Celsius: %f\n", (5./9)*(f-32)); 
  return 0;
}
