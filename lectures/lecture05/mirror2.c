#include <stdio.h>
#include <string.h>
int main(void) {
  printf("Enter a word! ");
  char word[64];
  scanf("%s", word);
  int from, to;
  
  
  for(from=0, to=strlen(word)-1;
      from<to;
      from++, to--) {
    char swap = word[from];
    word[from] = word[to];
    word[to] = swap;
  }


  printf("Mirrored: %s\n", word);
  return 0;
}
