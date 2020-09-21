#include<stdio.h>
int main(void) {
  int i;
  int* pi;
  i = 42;
  printf("The value of 'i' is: %d\n", i);
  printf("The address of 'i' is: %p\n", &i);
  pi = &i;
  printf("The value at address 'pi' is: %d\n", *pi);
  printf("The value of 'pi' is: %p\n", pi);
  printf("The address of 'pi' is: %p\n", &pi);
  return 0;
}
