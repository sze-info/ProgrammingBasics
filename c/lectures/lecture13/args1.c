#include <stdio.h>

int main(int argc, char* argv[]) {
  printf("Name of the started program: %s\n", argv[0]);
  if(argc == 1) {
    printf("No command line arguments were given.\n");
  } else {
    for(int i=1; i<argc; i++) {
      printf("Arg. #%d: %s\n", i, argv[i]);
    }
  }
  return 0;
}
