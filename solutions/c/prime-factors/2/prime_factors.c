#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
	size_t count = 0;

	while(n%2 == 0 && count < MAXFACTORS){
		factors[count++] = 2;
		n /= 2;
	}

	for(uint64_t factor = 3; n > 1; factor += 2){
		while(n%factor == 0 && count < MAXFACTORS){
			factors[count++] = factor;
			n /= factor;
		}
	}
	
	return count;
}