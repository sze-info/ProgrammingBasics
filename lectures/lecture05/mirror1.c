#include <stdio.h>
#include <string.h>
int main(void) {
  printf("Enter a word! ");
  char word[64];
  scanf("%s", word);
  int from, to;
  
  
  from = 0; to = strlen(word)-1;
  while(from < to) {
    char swap = word[from];
    word[from] = word[to];
    word[to] = swap;
    from++; to--;
  }
  
  
  printf("Mirrored: %s\n", word);
  return 0;
}
