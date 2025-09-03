#include "nth_prime.h"

static bool is_prime(uint32_t candidate, uint32_t *primes){
	for(; (*primes)*(*primes) <= candidate; primes++){
		if(candidate%(*primes) == 0) return false;
	}
	return true;
}

uint32_t nth(uint32_t n){
	if(n == 0) return 0;

	uint32_t *primes = malloc(n * sizeof(uint32_t));
	if(primes == NULL) return ERROR;
	primes[0] = 2;
	
	unsigned i = 1;
	for(uint32_t candidate = 3; i < n; candidate += 2){
		if(is_prime(candidate,primes)){
			primes[i++] = candidate;
		}
	}

	uint32_t output = primes[n-1];
	free(primes);
	return output;
}