#include <stdio.h>
#include <iso646.h>  // and, or, not
#include <stdbool.h> // bool
#define SIDES 3
int main(void) {
  int sideArray[SIDES]; // 3 element array for storing side lengths
  int i;                // index of the current side (0-2)
  bool valid = false;
  printf("Enter the sides of a triangle!\n");
  do {
    i = 0;
    while(i < SIDES) { // The code snippet of reading side length appears only once
      do {
        printf("Length of the next side: "); scanf("%d", &sideArray[i]); // array indexing
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
