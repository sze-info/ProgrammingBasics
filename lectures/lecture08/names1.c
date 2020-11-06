#include <stdio.h>
#include <string.h>

#define HAYSTACK "Jane cooks, Jane bakes, Jane does the washing up"
#define FROM "Jane"
#define TO "Emily"

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
