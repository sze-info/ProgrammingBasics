#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 4

void generate(int m[][COLS]) {
  for(int r=0; r<ROWS; r++) {
    for(int c=0; c<COLS; c++) {
      m[r][c] = 10 + rand()%40;
    }
  }
}

void add(const int (*ma)[COLS], 
         const int (*mb)[COLS], 
               int (*mc)[COLS]) {
  for(int r=0; r<ROWS; r++) {
    for(int c=0; c<COLS; c++) {
      mc[r][c] = *(ma[r] + c) + *(*(mb+r) + c);
    }
  }
}

void print(const int ma[][COLS],
           const int mb[][COLS],
           const int mc[][COLS]) {
  for(int r=0; r<ROWS; r++) {
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
}

int main(void) {
  int ma[ROWS][COLS], mb[ROWS][COLS], 
      mc[ROWS][COLS];
  srand(time(NULL));
  generate(ma);
  generate(mb);
  add((const int(*)[COLS])ma, 
      (const int(*)[COLS])mb, mc);
  print((const int(*)[COLS])ma, 
        (const int(*)[COLS])mb, 
        (const int(*)[COLS])mc);
  return 0;
}
