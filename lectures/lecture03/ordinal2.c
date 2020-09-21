#include <stdio.h>
int main(void) {
  printf("Number: ");
  int number;
  scanf("%d", &number);
  if(number == 0) printf("0");
  else {
    printf("%d", number);
    if(number>10 && number<21) printf("th");
    else switch(number%10) {
      case 1: printf("st"); break;
      case 2: printf("nd"); break;
      case 3: printf("rd"); break;
      default: printf("th");
    }
  }
  return 0;
}
