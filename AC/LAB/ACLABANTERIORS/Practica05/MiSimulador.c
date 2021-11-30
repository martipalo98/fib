#include "CacheSim.h"
#include <stdio.h>
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

//Struct que defineix cada línia de la cache, amb el bit de validesa i el tag
typedef struct {
    unsigned int v;
    int tag; 
} linea_cache;

linea_cache cache[128]; //Cache de 128 liníes
 //Contadors de hits i misses
int hits;
int misses;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
    //S'inicien el número total de hits i miss a 0, i cap dels tags es vàlid
    hits = 0;
    misses = 0;
    for (int i = 0; i < 128; i++) {
        cache[i].v = 0;
    }
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
    
    byte = address%32; //bits del 27 al 31
    bloque_m= address/32; //bits del 0 al 26
    linea_mc = bloque_m%128; //bits del 20 al 26
    tag = bloque_m/128; //bits del 0 al 19

    
    //Vàlida
    if (cache[linea_mc].v == 1) {
        //HIT
        if (cache[linea_mc].tag == tag) {
            replacement= 0;
            miss = 0;
            hits++;
        }
        //MISS, es canvia el tag
        else {
            miss = 1;
            misses++;
            replacement = 1;
            tag_out = cache[linea_mc].tag;
            cache[linea_mc].tag = tag;
        }
    }
    //Dada no vàlida. Sempre es un miss
    else {
        miss = 1;
       replacement= 0;
       misses++;
       cache[linea_mc].tag = tag;
       cache[linea_mc].v = 1;
    }


	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  printf ("Número de hits: %d\nNúmero de misses: %d\n", hits, misses);
  
}
