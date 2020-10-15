#include <stdio.h>
int main(void) {
  double absolute(double number) {
    return number<0. ? -number : number;
  }
  printf("%f\n", absolute(-1.));
  return 0; 
}
