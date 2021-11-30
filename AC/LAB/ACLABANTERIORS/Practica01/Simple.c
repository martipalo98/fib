#include<stdio.h>
#include "cycle.h"
main()
{
  
	long long i, resultado=0;
	//float t1,t2;
	//ticks ti1,ti2;
	//ti1=getticks();
	//t1=GetTime();


	for ( i=0; i<3000000; i++)
	resultado=resultado+i;

	printf("Resultado = %lld\n",resultado);
	/*t2=GetTime();
	printf("Milisegundos = %9f\n", t2-t1);
	ti2=getticks();
	printf("Ciclos = %lf\n", elapsed(ti2,ti1));
*/
}
