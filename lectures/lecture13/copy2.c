#include <stdio.h>
#include <stdlib.h>
#define SIZE 65536

int main(int argc, char* argv[]) {
  if(argc != 3) {
    printf("Usage: %s source destination\n", argv[0]);
  } else {
    FILE* in = fopen(argv[1], "rb");
    if(in) {
      FILE* out = fopen(argv[2], "wb");
      if(out) {
        char* buffer = (char*)malloc(SIZE);
        int amount;
        do {
          amount = fread(buffer, 1, SIZE, in);
          fwrite(buffer, 1, amount, out);
        } while(amount == SIZE);
        free(buffer);
        fclose(out);
      } else {
        fprintf(stderr, "File opening error: %s\n", argv[2]);
      }
      fclose(in);
    } else {
      fprintf(stderr, "File opening error: %s\n", argv[1]); 
    }
  }
  return 0;
}
