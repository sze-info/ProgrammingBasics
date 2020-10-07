#include <stdio.h>
#include <math.h> // sqrt() needs it

int main(void) {
  double a, b, c;
  printf("Solving equation ax^2+bx+c = 0\n"
         "Enter the value of coefficient a: "); 
  scanf("%lf", &a);
  if(a == 0.) {
    printf("The equation is not quadratic!\n");
  } else {
    printf("Enter the value of coefficient b: "); scanf("%lf", &b);
    printf("Enter the value of coefficient c: "); scanf("%lf", &c);
    double d = b*b - 4.*a*c;
    if(d < 0.) {
      printf("The equation has no real root.\n");
    } else {
      printf("x1 = %f\nx2 = %f\n", (-b + sqrt(d)) / (2.*a),
                                   (-b - sqrt(d)) / (2.*a));
    }
  }
  return 0;
}
