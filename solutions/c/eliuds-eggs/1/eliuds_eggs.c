#include "eliuds_eggs.h"

unsigned egg_count(unsigned encoded_number){
	unsigned count = 0;

	while(encoded_number != 0){
		count += encoded_number % 2;
		encoded_number >>= 1;
	}

	return count;
}