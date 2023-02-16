#include<stdio.h>

int main(void) {
  signed char c = (signed char)0xAA; /* 1010 1010 */
  printf("%x\n",c>>4); /* output: fffffffa */
  return 0;
}
