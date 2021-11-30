#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
	int tag;			// Etiqueta
	unsigned int v; 	// Bit Validesa
	unsigned int d;		// Dirty Bit
} linia_cache;

linia_cache cache[128];

int hits;			// Contador Hits
int misses;			// Contador Misses
int num_writes;


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	for (int i = 0; i < 128; i++){cache[i].v = 0; cache[i].d = 0;}	
	hits = misses = 0;	
	num_writes = 0;

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */
	lec_mp = 0;
	esc_mp = 0;
	mida_lec_mp = 0;
	mida_esc_mp = 0;
	replacement = 0;
	byte = (address & 0x0000001F);				// Bits 27 - 31
	bloque_m = address >> 5;					// Bits 0 - 26
	linea_mc = (address & 0x00000FE0) >> 5;		// Bits 20 - 26
	tag = address >> 12;						// Bits 0 - 19

	// Bit de validesa a 1
	if (cache[linea_mc].v == 1) {
		
		// Hit
		if (cache[linea_mc].tag == tag) { 
			miss = 0;
			++hits;

			//Si s'està escribint, només a la caché, DB a 1
			if (LE == 1) cache[linea_mc].d = 1;
		}
		
		// Miss
		else {
			miss = 1;
			++misses;
			tag_out = cache[linea_mc].tag;
			cache[linea_mc].tag = tag;
			replacement = 1;
			// Si DB = 1, guardar a MP
			if(cache[linea_mc].d == 1) {
				++num_writes;
				cache[linea_mc].d = 0;
				esc_mp = 1;
				mida_esc_mp = 32;
			}
			if(LE == 1) cache[linea_mc].d = 1;
			lec_mp = 1;
			mida_lec_mp = 32;
		}
	}
	// Bit de validesa a 0
	else {
		// No cal reemplaçar
		miss = 1;
		++misses;
		// Llegir de MP
		lec_mp = 1;
		mida_lec_mp = 32;
		cache[linea_mc].v = 1;
		cache[linea_mc].tag = tag;
		if (LE) cache[linea_mc].d = 1;
	}




	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  	printf("\tHits: %d\n\tMisses: %d\n\tEscriptures MP: %d\n", hits, misses, num_writes);  
}
