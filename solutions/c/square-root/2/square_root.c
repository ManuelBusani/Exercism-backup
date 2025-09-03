#include "square_root.h"

inline static uint16_t improve_guess(uint16_t guess, uint16_t radicand){
	return (guess + radicand/guess)/2;
}

uint16_t square_root(uint16_t radicand){
	if(radicand <= 1) return radicand;

	double last = radicand/2;
	double current = improve_guess(last,radicand);

	while(current < last){
		last = current;
		current = improve_guess(current,radicand);
	}
	return last;
}