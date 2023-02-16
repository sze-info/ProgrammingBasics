#include <stdio.h>
#include <string.h>

#define SEP "&"
int main(void) {
  char url[] = "http://it.sze.hu/index.php?tart=hirek&old=2";
  char* pk = strchr(url, '?');
  char* pv;
  if(pk && (pk=strtok(pk+1, SEP))) {
    do {
      pv = strchr(pk, '=');
      if(pv) *pv = '\0';
      else continue;
      printf("Key: %s, value: %s\n", pk, pv+1);
    } while((pk=strtok(NULL, SEP)));
  } else {
    printf("The URL does not contain query string.\n"); 
  }
  return 0; }
