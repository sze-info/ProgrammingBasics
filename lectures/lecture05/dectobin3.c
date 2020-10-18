#include <stdio.h>
int main(void) {
  char b[100];
  int d, i;
  printf("Enter a number in decimal number system!\n");


  for(scanf("%d", &d),i=0; 
      d>0; 
      d/=2,i++) {
    b[i] = d%2+'0'; 
  }


  printf("In binary number system: ");
  for(i--; i>=0; i--) {
    printf("%c", b[i]);
  }
  printf("\n");
  return 0;
}
