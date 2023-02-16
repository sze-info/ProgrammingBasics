#include <stdio.h>
int main(void) {
  char b[100];
  int d, i;
  printf("Enter a number in decimal number system!\n");
  scanf("%d", &d);
  i = 0;
  while(d > 0) {
    b[i] = d%2+'0'; d /= 2; i++;
  }
  printf("In binary number system: ");
  i--;
  while(i >= 0) {
    printf("%c", b[i]); // Printing a single character
    i--;
  }
  printf("\n");
  return 0;
}
