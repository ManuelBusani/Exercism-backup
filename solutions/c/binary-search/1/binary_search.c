#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length){
	if(length == 0)
		return NULL;

	int bottom = 0, top = length-1;

	while(bottom <= top){
		int middle = bottom + (top - bottom)/2;

		if(arr[middle] == value)
			return arr + middle;

		if(arr[middle] < value)
			bottom = middle + 1;
		
		else top = middle - 1;
	}

	return NULL;
}