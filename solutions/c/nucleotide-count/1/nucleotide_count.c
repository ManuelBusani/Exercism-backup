#include "nucleotide_count.h"

// static size_t number_length(unsigned number){
// 		size_t count = 1;
// 	while((number/=10) > 0) count++;
// 	return count;
// }

char *count(const char *dna_strand){
	if(!dna_strand) return "";

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
				return "";
		}
	}

	size_t length = STRING_SIZE + 100;

	char *result = malloc(length*sizeof(char));
	sprintf(result,"A:%d C:%d G:%d T:%d",a,c,g,t);

	return result;
}