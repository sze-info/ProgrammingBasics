#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
  char* text = "Commodore 64 Basic V2";
  char* vowels = "euioa";
  printf("Determining vowels (V), consonants (C) and others (-) "
    "\n%s\n", text);
  for(; *text; text++) {
    if(isalpha(*text)) { // Binary <--> linear search?
      if(strchr(vowels, tolower(*text))) printf("V");
      else printf("C");
    } else printf("-"); 
  }
  printf("\n");
  return 0;
}
