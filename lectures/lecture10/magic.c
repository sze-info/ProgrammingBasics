#include <stdio.h>
#include <stdlib.h>

// It works only with square matrices of odd order!
int** generate(int size) {
  // Allocating memory
  int** mtx = (int**)malloc(size*sizeof(int*));
  for(int r=0; r<size; r++) {
    mtx[r] = (int*)calloc(size, sizeof(int));
  }
  // Filling
  int r=0, c=size/2;
  for(int n=1; n<=size*size; n++) {
    mtx[r][c] = n;
    int i = r-1; if(i==-1) i=size-1;
    int j = c+1; if(j==size) j=0;
    if(mtx[i][j] != 0) {
      r++;
    } else { 
      r = i; 
      c = j; 
    } 
  } 
  return mtx;
}

void print(int** mtx, int size) {
  for(int r=0; r<size; r++) {
    for(int c=0; c<size; c++) {
      printf("%d\t", mtx[r][c]);
    } 
    putchar('\n');
  }
}

void freeMem(int** mtx, int size) {
  for(int r=0; r<size; r++) {
    free(mtx[r]);
  }
  free(mtx);
}

int main(void) {
  int size;
  do {
    printf("Size of the magic square: ");
    scanf("%d", &size);
  } while(size%2 == 0);
  int** magic = generate(size);
  print(magic, size);
  freeMem(magic, size);
  return 0;
}
