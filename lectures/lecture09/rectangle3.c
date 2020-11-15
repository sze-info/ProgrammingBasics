#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
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

void draw(struct rectangle* ar, int count) {
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

bool readTLX(int n, int min, int max, int* k) {
  bool goon;
  do {
    printf("X coordinate of the top left corner of rectangle #%d [%d, %d] "
      "(exits to a negative value) ", n, MINX, MAXX-1);
    scanf("%d", k);
    goon = *k>=0;
  } while(goon && (*k<MINX or *k>MAXX-1));
  return goon;
}

int read(int n, char s[], int min, int max) {
  int k;
  do {
    printf("%s rectangle #%d [%d, %d] ", 
      s, n, min, max);
    scanf("%d", &k);
  } while(k<min or k>max);
  return k; 
}

int readAll(struct rectangle** ar) {
  int used=0, total = 2, tlx;
  bool goon;
  printf("\t[Initial memory allocation]\n");
  *ar = (struct rectangle*)malloc(
    total * sizeof(struct rectangle));
  do {
    printf("\t[Used: %d, Array size: %d]\n", used, total);
    goon = readTLX(used+1, MINX, MAXX-1, &tlx);
    if(goon) {
      if(used == total) {
        printf("\t[Memory re-allocation]\n");
        total += 2;
        *ar = (struct rectangle*)realloc(
          *ar, total*sizeof(struct rectangle));
      }
      (*ar)[used].tl.x = tlx;
      (*ar)[used].tl.y = read(used+1, 
        "Y coordinate of the top left corner", MINY, MAXY-1);
      (*ar)[used].br.x = read(used+1, 
        "X coordinate of the bottom right corner", 
        (*ar)[used].tl.x+1, MAXX);
      (*ar)[used].br.y = read(used+1, 
        "Y coordinate of the bottom right corner", 
        (*ar)[used].tl.y+1, MAXY);
      printf("Drawing character of rectangle #%d: ", used+1);
      scanf(" %c", &(*ar)[used].c);
      used++;
    }
  } while(goon);
  return used;
}

int main(void) {
  struct rectangle* ar; int used;
  printf("Please enter the data of rectangles!\n");
  used = readAll(&ar);
  draw(ar, used);
  free(ar);
  return 0; 
}
