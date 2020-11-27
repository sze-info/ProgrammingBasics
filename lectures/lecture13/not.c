#include<stdio.h>

int main(void) {
  unsigned char c = 0xA; /* 1010 */
  printf("%x\n",~c); /* output: fffffff5
    thus 1111 1111 1111 1111 1111 1111 1111 0101 */
  return 0;
}
