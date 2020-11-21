#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// macro with arguments
#define idx(r,c,rowLength) ((r)*(rowLength)+(c))

int* allocate(int rows, int cols) {
  return (int*)malloc(rows * cols * sizeof(int));
}

void generate(int* m, int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      m[idx(r, c, cols)] = 10 + rand()%40;
    }
  }
}

void add(int* ma, int* mb, int* mc, 
         int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      mc[idx(r, c, cols)] = ma[idx(r, c, cols)] + mb[idx(r, c, cols)];
    }
  }
}

void print(int* ma, int* mb, int* mc,
           int rows, int cols) {
  for(int r=0; r<rows; r++) {
    for(int c=0; c<cols; c++) {
      printf("%d ", ma[idx(r, c, cols)]);
    }
    printf("%c ", r==rows/2?'+':' ');
    for(int c=0; c<cols; c++) {
      printf("%d ", mb[idx(r, c, cols)]);
    }
    printf("%c ", r==rows/2?'=':' ');
    for(int c=0; c<cols; c++) {
      printf("%d ", mc[idx(r, c, cols)]);
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
