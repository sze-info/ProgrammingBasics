#include <stdio.h>
#include <iso646.h>
#define N 10

int main(void) {
  int numbers[N] = {13, -11, 0, 1, 42, 7, 14, 17, -23, 21};
  printf("What are you looking for? ");
  int i=0, num;
  scanf("%d", &num);
  while(i<N and numbers[i]!=num)
    i++;
  if(i == N)
    printf("Match not found.\n");
  else
    printf("Match found at index %d.\n", i);
  return 0;
}
