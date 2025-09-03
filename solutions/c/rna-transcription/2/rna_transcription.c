#include "rna_transcription.h"

char *to_rna(const char *dna){
	if(!dna) return NULL;
	
	char *rna = malloc(strlen(dna) + 1);
	
	if(!rna) return NULL;
	
	char *write = rna;

	for(; *dna; ++write, ++dna){
		switch(*dna){
			case 'G':
				*write = 'C';
				break;
	
			case 'C':
				*write = 'G';
				break;
	
			case 'T':
				*write = 'A';
				break;
	
			case 'A':
				*write = 'U';
				break;
	
			default:
				free(rna);
				return NULL;
		}
	}
	*write = '\0';
	return rna;
}