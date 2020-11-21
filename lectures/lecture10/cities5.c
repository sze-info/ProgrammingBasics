#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

#define MAX 32
char** readCities(int n) {
  char** cityList = (char**)malloc(n*sizeof(char*));
  for(int i=0; i<n; i++) {
    printf("Name of city #%d: ", i+1);
    char buf[MAX+1];
    int length = sze_getline(buf, MAX);
    cityList[i] = (char*)malloc(length+1);
    strcpy(cityList[i], buf);
  }
  return cityList;
}

int** readDistances(char** cityList, int n) {
  int** distanceMtx = (int**)malloc((n-1)*sizeof(int*));
  for(int from=1; from<n; from++) {
    distanceMtx[from-1] = (int*)malloc(from * sizeof(int));
    for(int to=0; to<from; to++) {
      printf("%s --> %s: ", cityList[from], cityList[to]);
      scanf("%d%*c", &distanceMtx[from-1][to]);
    }
  }
  return distanceMtx;
}

int getCityIdx(char** cityList, int n) {
  char cityName[MAX+1];
  do {
    sze_getline(cityName, MAX);
    for(int i=0; i<n; i++) {
      if(not strcmp(cityList[i], cityName)) {
        return i;
      }
    }
    printf("Non-existent city!\n");
  } while(true);
}

int getDistance(int** distanceMtx, int from, int to) {
  if(from == to) return 0;
  if(from < to) {
    int swap = from;
    from = to;
    to = swap;
  }
  return distanceMtx[from-1][to];
}

void freeMem(int** distanceMtx, char** cityList, int n) {
  for(int i=0; i<n-1; i++) {
    free(distanceMtx[i]);
    free(cityList[i]);
  }
  free(distanceMtx);
  free(cityList[n-1]);
  free(cityList);
}

int main(void) {
  char** cityList;
  int numCities;
  int** cityDistances;
  int from, to;
  printf("Determining the distances of cities\n"
         "Number of cities: ");
  scanf("%d%*c", &numCities);
  cityList = readCities(numCities);
  printf("Enter distances between cities\n");
  cityDistances = readDistances(cityList, numCities);
  printf("Exit by entering the same city twice.\n");
  do {
    printf("Departure from: "); 
    from = getCityIdx(cityList, numCities);
    printf("Arrival at: ");
    to = getCityIdx(cityList, numCities);
    if(from != to) {
      printf("Distance: %dkm\n" , 
        getDistance(cityDistances, from, to));
    }
  } while(from != to);
  freeMem(cityDistances, cityList, numCities);
  return 0;
}
