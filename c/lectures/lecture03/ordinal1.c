#include <stdio.h>
int main(void) {
  printf("Number: ");
  int number;
  scanf("%d", &number);
  if(number == 0) printf("0");
  else {
    printf("%d", number);
    if(number>10 && number<21) printf("th");
    else if(number%10 == 1) printf("st");
    else if(number%10 == 2) printf("nd");
    else if(number%10 == 3) printf("rd");
    else printf("th");
  }
  return 0;
}
