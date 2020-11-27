#include <stdio.h>

int main(int argc, char* argv[]) {
  if(argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
  } else {
    FILE* f = fopen(argv[1], "wt");
    if(f) {
      char* song[] = {
        "She's got a smile it seems to me",
        "Reminds me of childhood memories",
        "Where everything",
        "Was as fresh as the bright blue sky",
        "Now and then when I see her face",
        "She takes me away to that special place",
        "And if I'd stare too long",
        "I'd probably break down and cry"
      };
      for(unsigned i=0; i<sizeof(song)/sizeof(song[0]); i++) {
        fprintf(f, "%s\n", song[i]);
      }
      fclose(f);
    } else {
      fprintf(stderr, "File opening error.\n");
    }
  }
  return 0;
}
