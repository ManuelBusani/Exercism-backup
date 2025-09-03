#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H

#include<stdint.h>

typedef enum {
	BLACK,
	BROWN,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	GREY,
	WHITE
} resistor_band_t;

/* Argument `color` needs to have at least 2 elements,
 * if not there is undefined behaviour.
 */
uint16_t color_code(resistor_band_t color[static 2]);

#endif
