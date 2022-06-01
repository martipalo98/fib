#include <stdio.h>
#include "cycle.h"
#define N 3

int v[10]={1,2,3,4,-10,-11,-12,-13,201,-150};

int OperaVec(int Vector[], int elementos);

main(){
   long int i,b;
   int a;
   // Descomentar para medir los ticks
   //float t1,t2; 
  // Descomentar para medir los ticks
   //t1=GetTime();
   for (i=0;i<1000;i++)
     for (b=0;b<1000;b++)
       a=OperaVec(v,9);
  // Descomentar para medir los ticks
    //t2=GetTime();
    //printf("Milisegundos Tot = %9f\n",t2-t1);  
   if (a==-13)
     printf("OperaVec BIEN programado.\n");
   else
     printf("OperaVec MAL programado.\n");
}
