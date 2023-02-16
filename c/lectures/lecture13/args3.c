#include <stdio.h>
#include <stdlib.h> // srand, rand, atoi
#include <time.h>   // time

int main(int argc, char* argv[]) {
  if(argc != 3) {
    printf("Usage: %s min max\n", argv[0]);
  } else {
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    srand(time(NULL));
    printf("A random-generated number in the [%d, %d] interval: %d\n",
      min, max, min + rand()%(max-min+1));
  }
  return 0;
}
