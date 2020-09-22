#include <stdio.h>
#define N 10

int main(void) {
  int numbers[N] = {-23, -11, 0, 1, 7, 13, 14, 17, 21, 42};
  printf("What are you looking for? ");
  int num;
  scanf("%d", &num);
  int lower=0, upper=N-1, middle;
  while(lower <= upper) {
    middle = (lower+upper)/2;
    if(num < numbers[middle]) upper = middle-1;
    else if(num > numbers[middle]) lower = middle+1;
    else {
      printf("Match found at index %d.\n", middle);
      return 0;
    }
  }
  printf("Match not found, but it could be included at index %d.\n", lower);
  return 0;
}
