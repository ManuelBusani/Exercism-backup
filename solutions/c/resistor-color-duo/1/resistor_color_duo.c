#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *color){
	return 10*color[0] + color[1];
}

resistor_band_t *colors()
{
	static resistor_band_t color_array[10]
	= { BLACK,
	  	BROWN,
		RED,
		ORANGE,
		YELLOW,
		GREEN,
		BLUE,
		VIOLET,
		GREY,
		WHITE };

   return color_array;
}