#include "hamming.h"

int compute(const char *lhs, const char *rhs){
	if(!lhs || !rhs)
		return ERROR;

	int hamming_distance = 0;
	
	for(; *lhs && *rhs; ++lhs, ++rhs){
		if(*lhs != *rhs)
			++hamming_distance;
	}

	return (*lhs || *rhs ? ERROR : hamming_distance);
}