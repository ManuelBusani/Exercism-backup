#include "binary.h"

int convert(const char *input){
	if(!input) return INVALID;

	int number = 0;
	for(; *input; ++input){
		switch(*input){
			case '0':
				number = number << 1;
				break;

			case '1':
				number = (number << 1) + 1;
				break;

			default:
				return INVALID;
		}
	}

	return number;
}