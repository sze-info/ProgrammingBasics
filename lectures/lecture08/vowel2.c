#include <stdio.h>
#include <ctype.h>
#include <iso646.h>

const char *strchr(const char *s, int c) {
  while(*s!=c and *s!='\0') s++;
  if(*s) return s;
  else return NULL;
}

int main(void) {
  char* text = "Commodore 64 Basic V2";
  char* vowels = "euioa";
  printf("Determining vowels (V), consonants (C) and others (-) "
    "\n%s\n", text);
  for(; *text; text++) {
    if(isalpha(*text)) { // Binary <--> linear search?
      if(strchr(vowels, tolower(*text))) putchar('V');
      else putchar('C');
    } else putchar('-'); 
  }
  printf("\n");
  return 0;
}
