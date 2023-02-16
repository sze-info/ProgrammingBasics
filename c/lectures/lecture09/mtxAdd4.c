#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocate(int rows, int cols) {
  return (int*)malloc(rows * cols * sizeof(int));
}

void generate(int* m, int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      m[r*cols + c] = 10 + rand()%40;
    }
  }
}

void add(int* ma, int* mb, int* mc, 
         int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      mc[r*cols+c] = ma[r*cols+c] + mb[r*cols+c];
    }
  }
}

void print(int* ma, int* mb, int* mc,
           int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      printf("%d ", ma[r*cols + c]);
    }
    printf("%c ", r==rows/2?'+':' ');
    for(int c=0; c<cols; c++) {
      printf("%d ", mb[r*cols + c]);
    }
    printf("%c ", r==rows/2?'=':' ');
    for(int c=0; c<cols; c++) {
      printf("%d ", mc[r*cols + c]);
    }
    putchar('\n');
  }
}

int main(void) {
  srand(time(NULL));
  int rows = 1 + rand()%4;
  int cols = 1 + rand()%4;
  int* ma = allocate(rows, cols);
  int* mb = allocate(rows, cols);
  int* mc = allocate(rows, cols);
  generate(ma, rows, cols);
  generate(mb, rows, cols);
  add(ma, mb, mc, rows, cols);
  print(ma, mb, mc, rows, cols);
  free(ma);
  free(mb);
  free(mc);
  return 0;
}
