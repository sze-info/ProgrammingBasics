#include <stdio.h>

double absolute(double number) {
  return number<0. ? -number : number;
}

int main(void) {
  double v;
  printf("Enter a number: "); scanf("%lf", &v);
  printf("Given number's absolute value: %f\n"
         "absolute(-3) == %f\nabsolute(v*3) == %f\n"
         "absolute(absolute(-3)) == %f\n",
         absolute(v), absolute(-3), 
         absolute(v * 3), absolute(absolute(-3)));
  return 0; 
}
