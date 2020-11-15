#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

struct student {
  char* name;
  int grade;
};

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

void freeMem(struct student* s, int n) {
  for(int i=0; i<n; i++) {
    free(s[i].name);
  }
  free(s);
}

#define MAX 128
struct student* read(int* n) {
  printf("How many students are on the course? ");
  scanf("%d%*c", n); // delete the new line character from the input buffer
  struct student* s = (struct student*)malloc(
    *n * sizeof(struct student));
  if(!s) return NULL;
  for(int i=0; i<*n; i++) {
    printf("Name of student #%d: ", i+1);
    char name[MAX];
    int length = sze_getline(name, MAX-1);
    s[i].name = (char*)malloc(length + 1);
    if(!s[i].name) { freeMem(s, i-1); return NULL; }
    strcpy(s[i].name, name);
    printf("Grade: ");
    scanf("%d%*c", &s[i].grade);
  }
  return s;
}

void bubble(struct student* s, int n) {
  for(int e=n-1; e>=1; e--) {
    for(int b=0; b<e; b++) {
      if(strcmp(s[b].name, s[b+1].name) > 0) {
        struct student swap = s[b];
        s[b] = s[b+1];
        s[b+1] = swap;
      }
    }
  }
}

void print(struct student* s, int n) {
  int longest = 0;
  for(int i=0; i<n; i++) {
    int length = strlen(s[i].name);
    if(length > longest) longest = length;
  }
  for(int i=0; i<n; i++) {
  // Column width specified at runtime
    printf("%*s %d\n", 
           longest, s[i].name, s[i].grade);
  }
}

int main(void) {
  int n;
  struct student *s = read(&n);
  if(s) {
    bubble(s, n);
    print(s, n);
    freeMem(s, n);
  }
  return 0;
}
