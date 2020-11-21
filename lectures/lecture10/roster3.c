#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <string.h>

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

#define MAX 64
int read(char*** a) { // Points to a location where a pointer to an
  int n;              // array of pointers is placed
  char buf[MAX];
  printf("Number of names to be sorted: ");
  scanf("%d%*c", &n);
  *a = (char**)malloc(n * sizeof(char*)); // Allocate memory for the
  for(int i=0; i<n; i++) {                // array of pointers
    printf("Name #%d: ", i+1);
    int length = sze_getline(buf, MAX-1);
    (*a)[i] = (char*)malloc((length+1) * sizeof(char));
    strcpy((*a)[i], buf);
  }
  return n;
}

void bubble(char** a, int n) {
  for(int e=n-1; e>=1; e--) {
    for(int b=0; b<e; b++) {
      if(strcmp(a[b], a[b+1]) > 0) {
        char* swap = a[b]; // moving pointers only
        a[b] = a[b+1];
        a[b+1] = swap;
      }
    }
  }
}

void print(char** a, int n) {
  for(int i=0; i<n; i++) {
    printf("%s\n", a[i]);
  }
}

void freeMem(char** a, int n) {
  for(int i=0; i<n; i++) {
    free(a[i]);
  }
  free(a); // freeing the array
}

int main(void) {
  printf("Sorting names\n");
  char** roster; // Points to an array of pointers
  int n = read(&roster);
  bubble(roster, n);
  printf("Names in alphabetic order:\n");
  print(roster, n);
  freeMem(roster, n);
  return 0;
}
