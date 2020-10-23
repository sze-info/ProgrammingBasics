#include <stdio.h>
#include <math.h>
#define MAX 1000

struct vector {
  double x, y, z;
  double length;
};

int main(void) {
  struct vector av[MAX];
  int count;
  double maxLength = 0.;
  printf("Searching for the longest vectors\n"
         "Enter the number of vectors: ");
  scanf("%d", &count);
  for(int i=0; i<count; i++) {
    printf("X coordinate of vector %d: ", i+1); scanf("%lf", &av[i].x);
    printf("Y coordinate: "); scanf("%lf", &av[i].y);
    printf("Z coordinate: "); scanf("%lf", &av[i].z);
    av[i].length = sqrt(
      av[i].x*av[i].x + av[i].y*av[i].y + av[i].z*av[i].z);
    if(av[i].length > maxLength) maxLength = av[i].length;
  }
  printf("Maximum length: %f, the longest vectors are:\n", maxLength);
  for(int i=0; i<count; i++) {
    if(av[i].length == maxLength) {
      printf("%f %f %f\n", av[i].x, av[i].y, av[i].z);
    }
  }
  return 0;
}
