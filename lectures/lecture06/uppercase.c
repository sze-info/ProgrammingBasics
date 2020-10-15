#include <stdio.h>
#include <iso646.h>

int main(void) {
  char c;
  printf("Character: "); scanf("%c", &c);
  c = c>='a' and c<='z' ? c-'a'+'A' : c;
  printf("Uppercase shape: %c\n", c);
  return 0; 
}
