#include <stdio.h>

int search(char haystack[], char needle) {
  unsigned i;
  for(i=0; haystack[i]!='\0'; i++) {
    if(haystack[i] == needle) return i;
  }
  return -1;
}

int main(void) {
  char word[64]; char letter; int position;
  printf("Searching for a letter in a word\nEnter word: "); scanf("%s", word);
  printf("Letter to search for: ");                         scanf(" %c", &letter);
  position = search(word, letter); // Notice the space in front of %c!
  if(position == -1) {
    printf("Not found.\n");
  } else {
    printf("Found at %d.\n", position);
  }
  return 0; 
}
