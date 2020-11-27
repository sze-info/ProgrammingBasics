#include <stdio.h>
#define MAX 256

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
  } else {
    FILE* f = fopen(argv[1], "rt");
    if(f) {
      char buf[MAX];
      while(fscanf(f, "%s", buf) != EOF) 
        printf("%s\n", buf);
      fclose(f);
    } else {
      fprintf(stderr, "File opening error.\n");
    }
  }
  return 0;
}
