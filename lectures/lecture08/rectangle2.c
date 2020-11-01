#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#define MAXSHAPE 128
#define MINX 0
#define MAXX 79
#define MINY 0
#define MAXY 24

struct coordinate {
  int x, y;
};

struct rectangle {
  struct coordinate tl, br;
  char c;
};

bool isCovered(struct rectangle r, int row, int col) {
  return (r.tl.x<=col and r.br.x>=col) and
         (r.tl.y<=row and r.br.y>=row);
}

void draw(struct rectangle ar[MAXSHAPE], int count) {
  for(int r=MINY; r<=MAXY; r++) {
    for(int c=MINX; c<=MAXX; c++) {
      bool covered = false;
      for(int i=count-1; i>=0 and not covered; i--) {
        if(isCovered(ar[i], r, c)) {
          printf("%c", ar[i].c); covered = true;
        }
      }
      if(not covered) printf(" ");
    }
    printf("\n");
  }
}

bool readTLX(int count, int min, int max, int* k) {
  bool goon;
  do {
    printf("X coordinate of the top left corner of rectangle #%d [%d, %d] "
      "(exits to a negative value) ", count, min, max);
    scanf("%d", k);
    goon = *k>=0;
  } while(goon && (*k<min or *k>max));
  return goon;
}

int read(int count, char s[], int min, int max) {
  int k;
  do {
    printf("%s rectangle #%d [%d, %d] ", 
      s, count, min, max);
    scanf("%d", &k);
  } while(k<min or k>max);
  return k; 
}

int main(void) {
  struct rectangle ar[MAXSHAPE]; int count; bool goon = true;
  printf("Please enter the data of rectangles!\n");
  for(count=0; count<MAXSHAPE and goon; count++) {
    goon = readTLX(count+1, MINX, MAXX-1, &ar[count].tl.x);
    if(goon) {
      ar[count].tl.y = read(count+1, "Y coordinate of the top left corner", MINY, MAXY-1);
      ar[count].br.x = read(count+1, "X coordinate of the bottom right corner", 
        ar[count].tl.x+1, MAXX);
      ar[count].br.y = read(count+1, "Y coordinate of the bottom right corner", 
        ar[count].tl.y+1, MAXY);
      printf("Drawing character of rectangle #%d: ", count+1);
      scanf(" %c", &ar[count].c);
      count++;
    }
  }
  draw(ar, count-1);
  return 0; 
}
