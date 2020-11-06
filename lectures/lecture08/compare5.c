#include <stdio.h>
#include <string.h>
#include <iso646.h>

#define MAX 128

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

int main(void) {
  printf("Enter two names and we determine which one comes first "
         "according to the alphabet\n");
  char n1[MAX], n2[MAX];
  printf("First name: "); sze_getline(n1, MAX); 
  printf("Second name: "); sze_getline(n2, MAX);
  int order = strcmp(n1, n2);
  if(order < 0)
    printf("%s is ahead of %s\n", n1, n2);
  else if(order > 0)
    printf("%s is ahead of %s\n", n2, n1);
  else
    printf("The two names are the same\n");
  return 0;
}
