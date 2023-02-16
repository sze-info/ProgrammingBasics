#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** allocate(int rows, int cols) {
  int** m = (int**)malloc(rows * sizeof(int*));
  for(int r=0; r<rows; r++) {
    m[r] = (int*)malloc(cols * sizeof(int));
  }
  return m;
}

void generate(int** m, int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      m[r][c] = 10 + rand()%40;
    }
  }
}

void add(int** ma, int** mb, int** mc, 
         int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      mc[r][c] = *(ma[r] + c) + *(*(mb+r) + c);
    }
  }
}

void print(int** ma, int** mb, int** mc,
           int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      printf("%d ", ma[r][c]);
    }
    printf("%c ", r==rows/2?'+':' ');
    for(int c=0; c<cols; c++) {
      printf("%d ", mb[r][c]);
    }
    printf("%c ", r==rows/2?'=':' ');
    for(int c=0; c<cols; c++) {
      printf("%d ", mc[r][c]);
    }
    putchar('\n');
  }
}

void freeMem(int** m, int rows) {
  for(int r=0; r<rows; r++) {
    free(m[r]);
  }
  free(m);
}

int main(void) {
  srand(time(NULL));
  int rows = 1 + rand()%4;
  int cols = 1 + rand()%4;
  int** a = allocate(rows, cols);
  int** b = allocate(rows, cols);
  int** c = allocate(rows, cols);
  generate(a, rows, cols);
  generate(b, rows, cols);
  add(a, b, c, rows, cols);
  print(a, b, c, rows, cols);
  freeMem(a, rows);
  freeMem(b, rows);
  freeMem(c, rows);
  return 0;
}
