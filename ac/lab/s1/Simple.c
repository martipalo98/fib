#include "cycle.h"
#include "tiempo.c"
#include<stdio.h>

main()
{
  
  long long i, resultado=0;
  float t1,t2;
  ticks ti1,ti2;
  ti1=getticks();
  t1=GetTime();
  
  for ( i=0; i<3000000; i++)
    resultado=resultado+i;

  printf("Resultado = %lld\n",resultado);
  t2=GetTime()-t1;
  ti2=elapsed(getticks(),ti1);
  printf("Ciclos = %llu\n", ti2);
  printf("Milisegundos = %9f\n", t2);
  printf("MIPS = %f\n", ti2/(t1*1000000));
}
