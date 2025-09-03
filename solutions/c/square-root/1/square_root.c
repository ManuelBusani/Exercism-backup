#include "square_root.h"

#define PRECISION 0.01
#define FIRST_GUESS 1

static double absolute(double x){
	return x < 0 ? -x : x;
}

static double newton_sqrt(double x){
	double result = FIRST_GUESS;
	while(absolute(result*result - x) > PRECISION){
		result = (result + x/result)/2;
	}
	return result;
}

uint16_t square_root(uint16_t x){
	return (uint16_t)newton_sqrt((double)x);
}