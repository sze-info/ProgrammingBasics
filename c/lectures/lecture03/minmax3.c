#include <stdio.h>
int main(void) {
  printf("Type non-negative integers and\n"
         "the program finds their minimum and maximum.\n"
         "Exit by entering a negative number.\n");
  int quantity=0, current;
  int min, max;
  // operator ,
  while(printf("Next number: "), scanf("%d", &current), current>=0) {
    if(!quantity) min = max = current; // operator !
    else if(current > max) max = current;
    else if(current < min) min = current;
    quantity++;
  }
  // logical expression
  if(quantity) printf("Minimum: %d\nMaximum: %d\n", min, max);
  else printf("You did not enter any numbers.\n");
  return 0;
}
