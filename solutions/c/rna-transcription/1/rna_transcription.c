#include "rna_transcription.h"

char *to_rna(const char *dna){
	unsigned size = sizeof(dna), i = 0;
	char *rna = malloc(size);

	for(; /*i < size - 1*/ dna[i]; ++i){
		switch(dna[i]){
			case 'G':
				rna[i] = 'C';
				break;
			case 'C':
				rna[i] = 'G';
				break;
			case 'T':
				rna[i] = 'A';
				break;
			case 'A':
				rna[i] = 'U';
/*				break;
			default:
				rna[i] = '0';*/
		}
	}
	rna[i] = '\0';
	return rna;
}