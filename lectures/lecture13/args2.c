#include <stdio.h>

int main(int argc, char** argv) {
  printf("Name of the started program: %s\n", *argv);
  if(argc == 1) {
    printf("No command line arguments were given.\n");
  } else {
    for(argv++; *argv != NULL; argv++) {
      printf("%s\n", *argv);
    }
  }
  return 0;
}
