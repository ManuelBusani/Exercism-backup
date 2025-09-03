#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t color[static 2]){
	return 10 * color[0] + color[1];
}