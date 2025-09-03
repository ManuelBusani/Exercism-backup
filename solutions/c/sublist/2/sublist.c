#include "sublist.h"

static inline bool is_equal(int *a, int *b, size_t length){
	return memcmp(a,b,length*sizeof(int)) == 0;
}

static bool is_sublist(int *a, int *b, size_t length_a, size_t length_b){
	size_t max_iter = length_b - length_a + 1;
	for(size_t i = 0; i < max_iter; i++){
		if(is_equal(a,b+i,length_a)) return true;
	}
	return false;
}

comparison_result_t check_lists(int *a, int *b, size_t length_a, size_t length_b){
	if(length_a < length_b){
		return is_sublist(a,b,length_a,length_b) ? SUBLIST : UNEQUAL;
	}
	if(length_a > length_b){
		return is_sublist(b,a,length_b,length_a) ? SUPERLIST : UNEQUAL;
	}
	return is_equal(a,b,length_a) ? EQUAL : UNEQUAL;
}