#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[128] = "Tom"; // The terminating '\0' is placed at
  char s2[] = "Jerry";  // the end of the string automatically
  strcat(s1, " and ");  // conCATenation
  strcat(s1, s2);       // Is s1 able to store all the characters?
                        // Format specifier: %s
  printf("Title of the tale: %s\n", s1);
                        // LENgth; z -> size_t, u -> unsigned
  printf("Title length: %zu\n", strlen(s1)); 
                        // l -> long, u -> unsigned
  printf("Memory needed: %lu bytes.\n", sizeof(s1));
  strcpy(s1, "The Flinstones"); // CoPY
  printf("Another tale: %s\n", s1);
  s1[3] = '\0'; s2[0] = 'G'; // Any characters can be modified
  printf("Not funny: %s %s\n", s1, s2);
                             // CoMParing the contents
  int comp = strcmp(s1, s2);
  if(comp < 0) {
    printf("%s in front of %s.\n", s1, s2);
  } else if(comp > 0) {
    printf("%s follows %s.\n", s1, s2);
  } else {
    printf("%s and %s are the same.\n", s1, s2);
  }
  return 0;
}
