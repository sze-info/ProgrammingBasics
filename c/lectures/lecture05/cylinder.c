#include <stdio.h>
#include <math.h>

int main(void) {
  double r, h;
  printf("Enter the radius of the cylinder: ");
  scanf("%lf", &r); // scanf: %lf -> double
  printf("Enter the height of the cylinder: ");
  scanf("%lf", &h); // printf: %f -> double
  printf("Volume: %f\n\tSurface: %f\n", 
         r*r*M_PI*h, 2.*r*M_PI*(r+h));
  return 0;
}
