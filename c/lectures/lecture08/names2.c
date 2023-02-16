#include <stdio.h>
#include <iso646.h>

#define HAYSTACK "Jane cooks, Jane bakes, Jane does the washing up"
#define FROM "Jane"
#define TO "Emily"

size_t strlen(const char* s) {
  const char* save = s;
  while(*s != '\0') s++;
  return s-save;
}

// Returns the address of the 1st occurrence of needle in haystack
// or a NULL pointer if needle not found
char *strstr(const char *haystack, const char *needle){
	const char *h, *n;
  for(; *haystack; ++haystack) {
    for(h=haystack,n=needle; *n!='\0' and *h==*n; ++h,++n);
    if(*n=='\0') return((char*)haystack);
  }
  return NULL;
}

char* strncat(char *dest, const char *src, size_t n) {
  char *save = dest;
  // Positioning to the terminating '\0' of dest
  while(*dest != '\0') ++dest;
  // Copying src to the end of dest until the terminating '\0' comes or
  // at most n characters
  while(n-- and *src!='\0') {
    *dest = *src;
    dest++; src++;
  }
  *dest = '\0';
  // Returning the combined string
  return save;
}

char* strcat(char *dest, const char *src) {
  char *save = dest;
  // Positioning to the terminating '\0' of dest
  while(*dest) ++dest;
  // Copying src to the end of dest until the terminating '\0' comes
  while((*dest++ = *src++));
  // Returning the combined string
  return save;
}

void names(const char* old, char* new, 
           const char* from, const char* to) {
  // Start of the substring NOT containing the name looked for
  const char *begin = old;
  char *end; // End of the same substring
  int fromLength = strlen(from);
  while((end = strstr(begin, from)) != NULL) {
    // Jane found somewhere
    // Copy everything in begin of her
    strncat(new, begin, end-begin);
    // Append Emily
    strcat(new, to);
    // Continue searching after Jane
    begin = end + fromLength;
  }
  // Copying the characters after the last occurrence of Jane
  strcat(new, begin);
}

int main(void) {
  char sentence[128] = "";
  names(HAYSTACK, sentence, FROM, TO);
  printf("%s\n", sentence);
  return 0;
}
