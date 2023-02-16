#include <stdio.h>
#include <iso646.h>  // and, or, not
#include <stdbool.h> // bool
#define SIDES 3
int main(void) {
  int sideArray[SIDES];
  int i;
  bool valid = false;
  printf("Enter the sides of a triangle!\n");
  do {
    i = 0;
    while(i < SIDES) {
      do {
        printf("Length of side %c: ", i+'A'); /* side's name */ scanf("%d", &sideArray[i]);
      } while(sideArray[i] <= 0);
      i++;
    }
    if(sideArray[0]+sideArray[1]<=sideArray[2] or 
       sideArray[1]+sideArray[2]<=sideArray[0] or 
       sideArray[2]+sideArray[0]<=sideArray[1])
      printf("The triangle is invalid!\n");
    else {
      valid = true; printf("The triangle is valid.\n"); }
  } while(not valid);
  return 0; }
