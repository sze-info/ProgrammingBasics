#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 100

int main(void) {
  srand(time(NULL));
  int guess, number = MIN + rand()%(MAX-MIN+1);
  printf("Guess a number between %d and %d.\n", MIN, MAX);
  do {
    printf("Guess: "); scanf("%d", &guess);
    if(guess < number) printf("The number is greater.\n");
    else if(guess > number) printf("The number is less.\n");
  } while(guess != number);
  printf("You guessed it!\n");
  return 0; }
