#include <stdio.h>
#include <ctype.h> // isalnum() needs it
#include <stdbool.h>
#include <iso646.h>
#include <string.h>
int main(void) {
  bool invalid;
  char neptun[64];
  do {
    invalid = false;
    printf("Enter your Neptun code: "); scanf("%s", neptun);
    if(strlen(neptun) != 6) {
      printf("It must contain six characters!\n"); invalid = true;
    } else {
      unsigned i=0;
      while(not invalid and neptun[i]) {
        if(not isalnum(neptun[i])) { // is it an alphanumeric character?
          printf("Only alphanumeric characters are allowed!\n");
          invalid = true; }
        i++; } }
  } while(invalid);
  printf("The code is valid.\n");
  return 0; }
