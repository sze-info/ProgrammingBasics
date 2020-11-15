#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 4

int main(void) {
  // declaration, initialization
  int ma[ROWS][COLS] = {
    { 11, 12, 13, 14 },
    { 21, 22, 23, 24 },
    { 31, 32, 33, 34 }
  };
  int mb[ROWS][COLS], mc[ROWS][COLS];
  srand(time(NULL));
  for(int r=0; r<ROWS; r++) { // filling the mtx.
    for(int c=0; c<COLS; c++) {
      mb[r][c] = 10 + rand()%40;
    }
  }
  for(int r=0; r<ROWS; r++) { // add up mtxs.
    for(int c=0; c<COLS; c++) {
      mc[r][c] = ma[r][c] + mb[r][c];
    }
  }
  for(int r=0; r<ROWS; r++) { // printing
    for(int c=0; c<COLS; c++) {
      printf("%d ", ma[r][c]);
    }
    printf("%c ", r==ROWS/2?'+':' ');
    for(int c=0; c<COLS; c++) {
      printf("%d ", mb[r][c]);
    }
    printf("%c ", r==ROWS/2?'=':' ');
    for(int c=0; c<COLS; c++) {
      printf("%d ", mc[r][c]);
    }
    putchar('\n');
  }
  return 0; }
