#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int c, numLines, numWords, numChars;
  bool insideWord = false;
  printf("Counting the characters, words and lines of the input\n"
         "Exit: Ctrl+D or EOF.\n\n");
  numLines = numWords = numChars = 0;
  while((c=getchar()) != EOF){
    ++numChars;
    if(c == '\n') ++numLines;
    if(c==' ' || c=='\n' || c=='\t') insideWord = false;
    else if(!insideWord){
      insideWord = true;
      ++numWords;
    }
  }
  printf("Number of lines = %d, words = %d, characters = %d\n", 
    numLines, numWords, numChars);
  return 0;
}
