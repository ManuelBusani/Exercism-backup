#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit){
	if(!factors || number_of_factors == 0) return 0;

	unsigned sum = 0;

	for(size_t factor_index = 0; factor_index < number_of_factors; factor_index++){
		unsigned int multiple = factors[factor_index];
		
		if(multiple == 0) continue;

		while(multiple < limit){
			bool is_not_repeated = true;
			for(unsigned int i = 0; i < factor_index; i++){
				if(factors[i] == 0) continue;
				if(multiple%factors[i] == 0){
					is_not_repeated = false;
					break;
				}
			}
			if(is_not_repeated) sum += multiple;
			multiple += factors[factor_index];
		}
	}
	return sum;
}