#include <stdio.h>
#include <iso646.h>
#define MAX 5

int beolvas(int* szamok) {
  int uj, hasznal = 0;
  do {
    printf("%d. szam: ", hasznal + 1);
    scanf("%d", &uj);
    if(uj>=0 and hasznal<MAX) {
      *(szamok + hasznal) = uj;
      hasznal++;
    }
  } while(uj>=0 and hasznal<MAX);
  return hasznal;
}

void buborek(int* t, int n) {
  for(int i=n-1; i>=1; i--) {
    for(int k=0; k<i; k++) {
      if(t[k] > t[k+1]) {
        int csere = t[k];
        t[k] = t[k+1];
        t[k+1] = csere;
      }
    }
  }
}

void tombKiir(const int* t, int n) {
  for(const int* vege=t+n; t<vege; t++) {
    printf("%d\t", *t);
  }
  putchar('\n');
}

int main(void) {
  int hasznal; // Ennyi elemet hasznalunk eppen
  int szamok[MAX];
  printf("Adjon meg nemnegativ szamokat!\n");
  hasznal = beolvas(szamok);
  buborek(szamok, hasznal);
  printf("Rendezes utan:\n");
  tombKiir(szamok, hasznal);
  return 0;
}
