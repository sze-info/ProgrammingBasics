#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <string.h>

int sze_getline(char s[], int lim) {
  int c, i;
  for(i=0; i<lim and (c=getchar())!=EOF and c!='\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  while(c!=EOF and c!='\n') c = getchar();
  return i;
}

#define CITIES 7
#define MAX 32
int getCityIdx() {
  char* cityList[CITIES] = {
    "Budapest", "Gyor", "Szeged",
    "Debrecen", "Veszprem",
    "Dunaujvaros", "Eger"
  };
  char cityName[MAX+1];
  do {
    sze_getline(cityName, MAX);
    for(int i=0; i<CITIES; i++) {
      if(not strcmp(cityList[i], cityName)) {
        return i;
      }
    }
    printf("Non-existent city!\n");
  } while(true);
}

int getDistance(int from, int to) {
  if(from == to) return 0;
  int distanceMtx[(CITIES*(CITIES-1))/2] = { 
    121,
    174, 287,
    231, 377, 218,
    115,  82, 278, 368,
     83, 176, 161, 320, 103,
    139, 285, 298, 131, 275, 228
  };
  if(from < to) {
    int swap = from;
    from = to;
    to = swap;
  }
  return distanceMtx[from*(from-1)/2 + to];
}

int main(void) {
  int from, to;
  printf("Determining the distances of cities\n"
         "Exit by entering the same city twice\n");
  do {
    printf("Departure from: "); from = getCityIdx();
    printf("Arrival at: "); to = getCityIdx();
    if(from != to) {
      printf("Distance: %dkm\n", getDistance(from, to));
    }
  } while(from != to);
  return 0;
}
