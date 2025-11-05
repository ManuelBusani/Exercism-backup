#include "rational_numbers.h"
#include <math.h>
#include <stdlib.h>

static void swap(int16_t *x, int16_t *y){
	int16_t aux = *x;
	*x = *y;
	*y = aux;
}

// greatest common divisor
// im not using this function with negative numbers
static int16_t gcd(int16_t a, int16_t b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

rational_t reduce(rational_t r){
	if(r.denominator == 0) return (rational_t){1, 0};
	if(r.numerator == 0) return (rational_t){0, 1};

	int16_t abs_numer = abs(r.numerator),
	        abs_denom = abs(r.denominator),
	        gcd_value = gcd(abs_numer, abs_denom);

	rational_t result;
	result.numerator = ((r.numerator < 0) == (r.denominator < 0) ?
						abs_numer: -abs_numer)/gcd_value;
	result.denominator = abs_denom/gcd_value;

	return result;
}

rational_t add(rational_t r1, rational_t r2){
	rational_t r;
	r.numerator = r1.numerator*r2.denominator + r1.denominator*r2.numerator;
	r.denominator = r1.denominator*r2.denominator;
	return reduce(r);
}

rational_t subtract(rational_t r1, rational_t r2){
	r2.numerator = -r2.numerator;
	return add(r1,r2);
}

rational_t multiply(rational_t r1, rational_t r2){
	rational_t r;
	r.numerator = r1.numerator*r2.numerator;
	r.denominator = r1.denominator*r2.denominator;
	return reduce(r);
}

rational_t divide(rational_t r1, rational_t r2){
	swap(&r2.numerator, &r2.denominator);
	return multiply(r1, r2);
}

rational_t absolute(rational_t r){
	r.numerator = abs(r.numerator);
	r.denominator = abs(r.denominator);
	return reduce(r);
}

rational_t exp_rational(rational_t r, int16_t n){
	if(n == 0) return (rational_t){1,1};
	if(n < 0){
		swap(&r.numerator, &r.denominator);
		n = -n;
	}
	r = reduce(r);
	r.numerator = pow(r.numerator, n);
	r.denominator = pow(r.denominator, n);
	return r;
}

float exp_real(uint16_t x, rational_t r){
	return powf(x, (float)r.numerator/(float)r.denominator);
}