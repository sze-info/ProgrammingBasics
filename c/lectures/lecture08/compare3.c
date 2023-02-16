#include <stdio.h>
#include <string.h>

#define MAX 128

int main(void) {
  printf("Enter two names and we determine which one comes first "
         "according to the alphabet\n");
  char n1[MAX], n2[MAX];
  printf("First name: "); gets(n1);
  printf("Second name: "); gets(n2);
  int order = strcmp(n1, n2);
  if(order < 0)
    printf("%s is ahead of %s\n", n1, n2);
  else if(order > 0)
    printf("%s is ahead of %s\n", n2, n1);
  else
    printf("The two names are the same\n");
  return 0;
}
