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
 * I don't know if I should be checking or not,
 * gonna check community solutions.
 */
uint16_t color_code(resistor_band_t *color);
resistor_band_t *colors();

#endif
