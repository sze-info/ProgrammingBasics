#include <stdio.h>

int main(void) {
  char b[64];
  unsigned d, i;
  printf("Enter a binary number!\n");
  scanf("%s", b); // Format specifier: %s, no address-of operator!!!
  d = i = 0;
  while(b[i] != '\0') { // Please, do not use strlen!
    d = d*2 + b[i]-'0'; // In general, it is VERY SLOW
    i++;
  }
  printf("In decimal number system: %d\n", d);
  return 0;
}
