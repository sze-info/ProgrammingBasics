#include <stdio.h>
#include <iso646.h>
#define PIECES 10
int main(void) {
  printf("Counting digits, whitespace and other characters\n"
         "until EOF or Ctrl+D is given.\n\n");
  int c, i, white=0, other=0;
  int digits[PIECES] = {0}; // resetting counters to zero
  while((c=getchar()) != EOF){
    if(c>='0' and c<='9') ++digits[c-'0']; // increasing the counter
    else if(c==' ' or c=='\n' or c=='\t') ++white;
    else ++other;
  }
  printf("Digits:\n");
  i = 0;
  while(i < PIECES) {
    printf("%d\t%d\n", i, digits[i]);
    i++;
  }
  printf("White spaces: %d, others: %d\n", white, other);
  return 0;
}
