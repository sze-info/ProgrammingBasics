#include <stdio.h>
#include <limits.h>
#define WORDLENGTH sizeof(unsigned)*8

unsigned rotl(unsigned num) {
  return(num<<1 | num>>(WORDLENGTH-1));
}

unsigned multirotl(unsigned num, unsigned n) {
  return(num<<n | num>>(WORDLENGTH-n));
}

void print(unsigned n){
  unsigned i, mask = INT_MIN;
  for(i=0; i<WORDLENGTH; i++, n<<=1) {
    if(n & mask) putchar('1');
    else putchar('0');
  }
}

int main(void) {
  unsigned num = -(INT_MAX);
  printf("Original number:\t\t"); 
    print(num);
  printf("\nRotated to the left by 1 bit:\t"); 
    print(rotl(num));
  printf("\nRotated to the left by 4 bits:\t"); 
    print(multirotl(num, 4));
  return 0;
}
