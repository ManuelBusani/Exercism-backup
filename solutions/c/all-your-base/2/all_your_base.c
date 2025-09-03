#include "all_your_base.h"

static bool is_invalid(int8_t digit, int16_t input_base){
	return digit < 0 || (int16_t)digit >= input_base;
}

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length){
	if(input_base <= 1 || output_base <= 1 || input_length == 0) return 0;

	int16_t number = 0;
	for(int16_t factor = 1; input_length > 0; factor *= input_base){
		int8_t digit = digits[--input_length];
		if(is_invalid(digit, input_base)) return 0;
		number += factor*(int16_t)digit;
	}
	if(number == 0){
		return 1;
	}
	size_t digit_count = 0;
	for(; number > 0; number /= output_base){
		digits[digit_count++] = (int8_t)(number%output_base);
	}
	// swapping position of elements
	for(size_t i = 0, index_limit = digit_count/2; i < index_limit; i++){
		int8_t temp = digits[i];
		digits[i] = digits[digit_count - i - 1];
		digits[digit_count - i - 1] = temp;
	}
	return digit_count;
}