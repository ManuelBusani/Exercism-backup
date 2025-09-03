#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
	size_t count = 0;
	uint64_t factor = 2;

	while(n > 1 && count < MAXFACTORS){
		if(n%factor == 0){
			factors[count] = factor;
			n /= factor;
			count++;

		}else{
			factor++;
		}
	}

	return count;
}