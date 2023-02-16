#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <string.h>
int main(void) {
  bool invalid;
  char neptun[64]; // Enough space for too long codes
  do {
    invalid = false;
    printf("Enter your Neptun code: "); scanf("%s", neptun);
    if(strlen(neptun) != 6) { // checking length
      printf("It must contain six characters!\n"); invalid = true;
    } else {
      unsigned i=0;
      while(not invalid and neptun[i]!='\0') {
        char c = neptun[i];
        bool digit = c>='0' and c<='9';
        bool upper = c>='A' and c<='Z';
        bool lower = c>='a' and c<='z';
        if(not digit and not upper and not lower) {
          printf("Only alphanumeric characters are allowed!\n");
          invalid = true; }
        i++; } }
  } while(invalid);
  printf("The code is valid.\n");
  return 0; }
