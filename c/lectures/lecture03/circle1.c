#include <stdio.h>

int main(void) {
  int row = -5; // The radius of the circle is 5
  while(row <= 5) {
    int column = -5;
    while(column <= 5) {
      if(5*5 >= row*row + column*column) printf("*");
      else printf(" ");
      column++;
    }
    row++;
    printf("\n");
  }
  return 0;
}
