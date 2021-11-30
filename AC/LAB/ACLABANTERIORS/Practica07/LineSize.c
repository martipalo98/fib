#include <stdio.h>

#define N 1024000
#define tam 16*1024*1024

int i, j, step;
unsigned char v[tam];

void InitCache(int cod);
void Referencia(unsigned char *dir);
int Referencias();
int Fallos();


int main() 
{  int i, j, step;
   int refs, misses;


  for (step=1; step<=128; step++) {
	
    InitCache(0xA1523FD3); 

    i = 0;

    for (j=0; j<N; j++) {
      Referencia((unsigned char *)&v[i]);     // acceso a v[i] 
      i = i + step;
      if (i >= tam) i = 0;
    }

    refs = Referencias();
    misses = Fallos(); 
    printf("LineSize? step=%3d ; fallos=%6d ; referencias=%6d\n", step, misses, refs);

  }

  return 0;
}

