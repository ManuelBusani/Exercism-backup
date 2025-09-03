#include "hamming.h"

int compute(const char *lhs, const char *rhs){
	int hamming_distance = 0, i;
	
	for(i = 0; lhs[i] && rhs[i]; ++i){
		if(lhs[i] != rhs[i])
			++hamming_distance;
	}

	return (lhs[i] || rhs[i] ? ERROR : hamming_distance);
}