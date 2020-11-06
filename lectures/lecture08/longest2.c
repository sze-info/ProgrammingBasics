#include <stdio.h>
#include <iso646.h>
#define MAX 1000

char *strcpy(char *dest, const char *src) {
  char *save = dest;
  // copying src to dest including the terminating '\0'
  while((*dest++ = *src++));
  // Returns the copy
  return save; }

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

int main(void) {
  int length;        // Length of the current line
  int max = 0;       // Current maximum length
  char line[MAX+1];  // Current line
  char save[MAX+1];  // Currently longest line
  printf("Determining the longest line\n"
         "Finish the lines by pressing ENTER\n"
         "Exit with empty line or by pressing Ctrl+Z\n\n");
  while((length=sze_getline(line, MAX)) > 0) {
    if (length > max) {
      max = length;
      strcpy(save, line); } }
  printf("The longest line:\n");
  if(max > 0) printf("\n%s\n", save); // At least one line was entered
  return 0;
}
