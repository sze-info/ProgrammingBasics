#include <stdio.h>

int main(void) {
  printf("Type non-negative integers and\n"
         "the program finds their minimum and maximum.\n"
         "Exit by entering a negative number.\n");
  int quantity=0, current=1; // initialization
  int min, max;
  while(current >= 0) {
    printf("Next number: ");
    scanf("%d", &current);
    if(current >= 0) {
      if(quantity == 0) min = max = current; // multiple assignment
      else if(current > max) max = current;
      else if(current < min) min = current;
      quantity++; // increase by one
    }
  }
  if(quantity > 0) printf("Minimum: %d\nMaximum: %d\n",
    min, max);
  else printf("You did not enter any numbers.\n");
  return 0;
}
