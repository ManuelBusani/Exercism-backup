#include "protein_translation.h"

static amino_acid_t parse(const char *const str){
	if(str[0] == 'A'){
		if(str[1] == 'U' && str[2] == 'G')
			return Methionine;
		return Not_amino_acid;
	}
	if(str[0] != 'U') return Not_amino_acid;
	if(str[1] == 'U'){
		if(str[2] == 'U' || str[2] == 'C')
			return Phenylalanine;
		if(str[2] == 'A' || 'G')
			return Leucine;
		return Not_amino_acid;
	}
	if(str[1] == 'C'){
		if(str[2] == 'U' || str[2] == 'C' || str[2] == 'A' || str[2] == 'G')
			return Serine;
		return Not_amino_acid;
	}
	if(str[1] == 'A'){
		if(str[2] == 'U' || str[2] == 'C') 
			return Tyrosine;
		if(str[2] == 'A' || str[2] == 'G')
			return Stop;
		return Not_amino_acid;
	}
	if(str[1] == 'G'){
		if(str[2] == 'U' || str[2] == 'C') 
			return Cysteine;
		if(str[2] == 'G')
			return Tryptophan;
		if(str[2] == 'A')
			return Stop;
		return Not_amino_acid;
	}
	return Not_amino_acid;
}

protein_t protein(const char *const rna){
	if(!rna) return (protein_t){.valid = false};

	protein_t protein = (protein_t){
		.valid = true,
		.count = 0
	};

	while(protein.count < MAX_AMINO_ACIDS && rna[3*protein.count] != '\0'){
		amino_acid_t acid = parse(rna + 3*protein.count);

		if(acid == Stop) break;

		if(acid == Not_amino_acid){
			protein.valid = false;
			return protein;
		}
		protein.amino_acids[protein.count] = acid;
		protein.count++;
	}
	return protein;
}