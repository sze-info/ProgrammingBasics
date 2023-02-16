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
  int distanceMtx[CITIES][CITIES] = {
    {   0, 121, 174, 231, 115,  83, 139 },
    { 121,   0, 287, 377,  82, 176, 285 },
    { 174, 287,   0, 218, 278, 161, 298 },
    { 231, 377, 218,   0, 368, 320, 131 },
    { 115,  82, 278, 368,   0, 103, 275 },
    {  83, 176, 161, 320, 103,   0, 228 },
    { 139, 285, 298, 131, 275, 228,   0 }
  };
  return distanceMtx[from][to];
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
