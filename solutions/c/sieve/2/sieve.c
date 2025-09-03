#include "sieve.h"

static uint32_t find_next_prime(bool *is_marked, uint32_t number, uint32_t limit){
	for(; number <= limit; number++){
		if(!is_marked[number - 2]) return number;
	}
	return NOT_FOUND;
}

static void mark_numbers(bool *is_marked, uint32_t number, uint32_t limit){
	for(uint32_t i = number + 1; i <= limit; i++){
		if(i%number == 0) is_marked[i-2] = true;
		}
}

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
	// `is_marked[i]` represents whether the number `i+2` is marked
	bool is_marked[limit - 1];
	for(unsigned i = 0; i < limit - 1; i++) is_marked[i] = false;

	size_t prime_count = 0;
	uint32_t number = 2;

	while(prime_count < max_primes){
		number = find_next_prime(is_marked, number, limit);

		if(number == NOT_FOUND) break;

		*primes = number;
		primes++; prime_count++;

		mark_numbers(is_marked, number, limit);

		number++;
	}

	return prime_count;
}