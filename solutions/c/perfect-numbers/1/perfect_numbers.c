#include "perfect_numbers.h"

int aliquot_sum(int number);

int aliquot_sum(int number){
	if(number == 1) return 0;
	int sum = 1;

	for(int i = 2; i < number; ++i){
		if(number%i == 0)
			sum += i;
	}

	return sum;
}

kind classify_number(int number){
	if(number <= 0) return ERROR;
	int sum = aliquot_sum(number);

	if(number < sum) return ABUNDANT_NUMBER;
	if(number == sum) return PERFECT_NUMBER;
	return DEFICIENT_NUMBER;
}