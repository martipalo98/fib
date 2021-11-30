#include <stdio.h>

#define N 1024000
#define tam 16*1024*1024

#define LINE_SIZE 128

int i, j, limite;
unsigned char v[tam];

void InitCache(int cod);
void Referencia(unsigned char *dir);
int Referencias();
int Fallos();
 
int refs, misses;

int main() 
{  int i, j;
   

  for (limite=128; limite <= 128000; limite+=128) {

    InitCache(0x29B424A0); 

    i = 0;
    for (j=0; j<N; j++) {
      Referencia((unsigned char *)&v[i]);     // acceso a v[i] 
      i=i+LINE_SIZE;
      if (i >= limite) i=0;
    }

    refs = Referencias();
    misses = Fallos(); 

    printf("CacheSize? limite=%6d ; fallos=%6d ; referencias=%6d\n", limite, misses, refs);

  }

  return 0;
}

