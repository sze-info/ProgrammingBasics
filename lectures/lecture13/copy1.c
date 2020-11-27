#include <stdio.h>

int main(int argc, char* argv[]) {
  if(argc != 3) {
    printf("Usage: %s source destination\n", argv[0]);
  } else {
    FILE* in = fopen(argv[1], "rt");
    if(in) {
      FILE* out = fopen(argv[2], "wt");
      if(out) {
        int c;
        while((c=fgetc(in)) != EOF) {
          fputc(c, out);
        }
        fclose(out);
      } else {
        fprintf(stderr, "Opening error: %s\n", argv[2]); 
      }
      fclose(in);
    } else {
      fprintf(stderr, "Opening error: %s\n", argv[1]); 
    }
  }
  return 0;
}
