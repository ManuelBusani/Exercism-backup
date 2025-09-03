#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t color[static 3]){

	resistor_value_t output;

	int exponent = color[2] + (color[1] == BLACK);

	if(color[1] == BLACK)
		output.value = color[0];
	else output.value = color[0]*10 + color[1];
	
	output.value *= pow(10,exponent%3);
	output.unit = exponent/3;

	return output;
}