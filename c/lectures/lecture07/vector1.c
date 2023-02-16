#include <stdio.h>
#include <math.h>
#define MAX 1000

int main(void) {
  double x[MAX], y[MAX], z[MAX], length[MAX];
  int count;
  double maxLength = 0.;
  printf("Searching for the longest vectors\n"
         "Enter the number of vectors: ");
  scanf("%d", &count);
  for(int i=0; i<count; i++) {
    printf("X coordinate of vector %d: ", i+1); scanf("%lf", &x[i]);
    printf("Y coordinate: "); scanf("%lf", &y[i]);
    printf("Z coordinate: "); scanf("%lf", &z[i]);
    length[i] = sqrt(x[i]*x[i] + y[i]*y[i] + z[i]*z[i]);
    if(length[i] > maxLength) maxLength = length[i];
  }
  printf("Maximum length: %f, the longest vectors are:\n", maxLength);
  for(int i=0; i<count; i++) {
    if(length[i] == maxLength) {
      printf("%f %f %f\n", x[i], y[i], z[i]);
    }
  }
  return 0;
}
