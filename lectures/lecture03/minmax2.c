#include <stdio.h>

int main(void) {
  printf("Type non-negative integers and\n"
         "the program finds their minimum and maximum.\n"
         "Exit by entering a negative number.\n");
  int quantity=0, current; // current does not need initialization
  int min, max;
  printf("Next number: "); // first occurrence of the code snippet
  scanf("%d", &current);
  while(current >= 0) {
    if(quantity == 0) min = max = current; // a selection is missing from here
    else if(current > max) max = current;
    else if(current < min) min = current;
    quantity++;
    printf("Next number: "); // second occurrence of the code snippet
    scanf("%d", &current);
  }
  if(quantity > 0) printf("Minimum: %d\nMaximum: %d\n", min, max);
  else printf("You did not enter any numbers.\n");
  return 0;
}
