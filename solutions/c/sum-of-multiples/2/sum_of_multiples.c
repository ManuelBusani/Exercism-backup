#include "sum_of_multiples.h"

static bool is_unique(unsigned int multiple, const unsigned int *factors,
                            size_t max_index){
	for(size_t i = 0; i < max_index; i++){
		if(factors[i] == 0) continue;
		if(multiple%factors[i] == 0) return false;
	}
	return true;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit){
	unsigned int sum = 0;

	for(size_t i = 0; i < number_of_factors; i++){
		unsigned int multiple = factors[i];		
		if(multiple == 0) continue;

		while(multiple < limit){
			if(is_unique(multiple,factors,i)) sum += multiple;
			multiple += factors[i];
		}
	}
	return sum;
}