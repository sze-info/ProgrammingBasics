#include <stdio.h>

#define MAX 128

int strcmp(const char *s1, const char *s2 ) {
  for(; *s1 == *s2; ++s1, ++s2)
    if(!(*s1)) return 0; // s1 is the same as s2
  return(*s1 - *s2); } // s1 < s2 or s1 > s2

int main(void) {
  printf("Enter two names and we determine which one comes first "
         "according to the alphabet\n");
  char n1[MAX], n2[MAX];
  printf("First name: "); scanf("%s", n1);
  printf("Second name: "); scanf("%s", n2);
  int order = strcmp(n1, n2);
  if(order < 0)
    printf("%s is ahead of %s\n", n1, n2);
  else if(order > 0)
    printf("%s is ahead of %s\n", n2, n1);
  else
    printf("The two names are the same\n");
  return 0;
}
