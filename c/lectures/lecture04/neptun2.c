#include <stdio.h>
#include <ctype.h> // toupper() needs it
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
      // ASCII code -> integer; 0 -> false, everything else -> true
      while(not invalid and neptun[i]) {
        char c = toupper(neptun[i]); // converting to uppercase letter
        if((c<'0' or c>'9') and (c<'A' or c>'Z')) {
          printf("Only alphanumeric characters are allowed!\n");
          invalid = true; }
        i++; } }
  } while(invalid);
  printf("The code is valid.\n");
  return 0; }
