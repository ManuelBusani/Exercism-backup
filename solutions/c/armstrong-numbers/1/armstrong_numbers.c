#include "armstrong_numbers.h"

// compute number of digits in base 10 of a given number
static int number_of_digits(int number){
	int digits = 1;
	while(number > 10){
		++digits;
		number /= 10;
	}
	return digits;
}

bool is_armstrong_number(int candidate){
	int digits = number_of_digits(candidate);
	int sum = 0, num = candidate;

	while(num != 0){
		sum += pow(num%10,digits);
		num /= 10;
	}

	return sum == candidate;
}