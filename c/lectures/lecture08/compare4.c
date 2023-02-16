#include <stdio.h>
#include <string.h>

#define MAX 128

int main(void) {
  printf("Enter two names and we determine which one comes first "
         "according to the alphabet\n");
  char n1[MAX], n2[MAX];
  char* end;
  printf("First name: "); fgets(n1, MAX, stdin); 
  if((end=strrchr(n1, '\n')) != NULL)
    *end = '\0';
  printf("Second name: "); fgets(n2, MAX, stdin);
  if((end=strrchr(n2, '\n')))
    *end = '\0';
  int order = strcmp(n1, n2);
  if(order < 0)
    printf("%s is ahead of %s\n", n1, n2);
  else if(order > 0)
    printf("%s is ahead of %s\n", n2, n1);
  else
    printf("The two names are the same\n");
  return 0;
}
