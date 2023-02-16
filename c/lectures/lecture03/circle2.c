#include <stdio.h>
#define R 10 // The radius of the circle is now 10

int main(void) {
  int row = -R; 
  while(row <= R) {
    int column = -R;
    while(column <= R) {
      if(R*R >= row*row + column*column) printf("*");
      else printf(" ");
      column++;
    }
    row += 2; // increase by two
    printf("\n");
  }
  return 0;
}
