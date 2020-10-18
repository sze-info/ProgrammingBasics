#include <stdio.h>
#define LOWER 0
#define UPPER 150
#define STEP 10

int main(void) {
  printf("Fahrenheit\tCelsius\n"
         "----------\t--------\n");
  double f;
    
  for(f=LOWER; f<=UPPER; f+=STEP)
    printf("%f\t%f\n", f, (5./9.)*(f-32.));
         
  return 0;
}
