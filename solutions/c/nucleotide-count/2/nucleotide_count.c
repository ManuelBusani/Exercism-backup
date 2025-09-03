#include "nucleotide_count.h"

char *count(const char *dna_strand){
	if(!dna_strand) return NULL;

	char *result = malloc(MAX_STRING_SIZE*sizeof(char));
	if(!result) return NULL;

	unsigned a=0, c=0, g=0, t=0;

	for(; *dna_strand != '\0'; dna_strand++){
		switch(*dna_strand){
			case 'A':
				a++;
				break;
			case 'C':
				c++;
				break;
			case 'G':
				g++;
				break;
			case 'T':
				t++;
				break;
			default:
				*result = '\0';
				return result;
		}
	}

	snprintf(result, MAX_STRING_SIZE, "A:%d C:%d G:%d T:%d",a,c,g,t);

	return result;
}