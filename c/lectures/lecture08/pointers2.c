#include <stdio.h>

int main(void) {
  int a[] = { 100, 200, 300 };
  int* pi = a;
  printf("Value (address) of the 1st element:\t%d (%p)\n", pi[0], a);
  pi++;
  printf("Value (address) of the 2nd element:\t%d (%p)\n", *pi, pi);
  printf("Value (address) of the 3rd element:\t%d (%p)\n", *(a+2), a+2);
  return 0;
}
