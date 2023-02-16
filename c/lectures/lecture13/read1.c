#include <stdio.h>

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
  } else {
    FILE* f = fopen(argv[1], "rt");
    if(f) {
      int c;
      while((c=fgetc(f)) != EOF) putchar(c);
      fclose(f);
    } else {
      fprintf(stderr, "File opening error.\n");
    }
  }
  return 0;
}
