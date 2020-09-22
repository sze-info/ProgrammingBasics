#include <stdio.h>
#include <iso646.h>
#define PIECES 10
int main(void) {
  printf("Counting digits, whitespace and other characters\n"
         "until EOF or Ctrl+D is given.\n\n");
  int i, c, white=0, other=0;
  int digits[PIECES];  // 10 element array for the digits
  i = 0;
  while(i < PIECES) {
    digits[i] = 0; // Zeroing the counters
    i++;
  }
  while((c=getchar()) != EOF){
    if(c>='0' and c<='9') {
      i = c-'0';     // Converting a character (ASCII code) to a number,
      digits[i]++;   // which is used as an index
    } else if(c==' ' or c=='\n' or c=='\t') white++;
    else other++;
  }
  printf("Digits:\n");
  i = 0;             // Displaying the results
  while(i < PIECES) {
    printf("%d\t%d\n", i, digits[i]);
    i++;
  }
  printf("White spaces: %d, others: %d\n", white, other);
  return 0;
}
