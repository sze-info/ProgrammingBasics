#include <stdio.h>
#include <iso646.h>
#include <string.h>
#define ROWS 10
#define COLUMNS 30

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

int read(char (*a)[COLUMNS]) {
  int n;
  printf("Number of names to be sorted (max. %d): ", ROWS);
  scanf("%d%*c", &n);
  if(n > ROWS) n = ROWS;
  for(int i=0; i<n; i++) {
    printf("Name #%d: ", i+1);
    sze_getline(a[i], COLUMNS-1);
  }
  return n;
}

void bubble(char (*a)[COLUMNS], int n) {
  for(int e=n-1; e>=1; e--) {
    for(int b=0; b<e; b++) {
      if(strcmp(a[b], a[b+1]) > 0) {
        char swap[COLUMNS];
        strcpy(swap, a[b]);
        strcpy(a[b], a[b+1]);
        strcpy(a[b+1], swap);
      }
    }
  }
}

void print(char (*a)[COLUMNS], int n) {
  for(int i=0; i<n; i++) {
    printf("%s\n", a[i]);
  }
}

int main(void) {
  printf("Sorting names\n");
  char roster[ROWS][COLUMNS];
  int n = read(roster);
  bubble(roster, n);
  printf("Names in alphabetic order:\n");
  print(roster, n);
  return 0;
}
