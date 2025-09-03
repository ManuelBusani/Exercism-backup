#include "binary.h"

int convert(const char *input){
	if(!input) return INVALID;

	int number = 0;
	for(; *input; ++input){
		switch(*input){
			case '0':
				number *= 2;
				break;

			case '1':
				number *= 2;
				++number;
				break;

			default:
				return INVALID;
		}
	}

	return number;
}