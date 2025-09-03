#include "darts.h"

uint8_t score(coordinate_t landing_position){
	float squared_distance = landing_position.x * landing_position.x +
					         landing_position.y * landing_position.y;
	if(squared_distance <= 1.0F)
		return 10;
	if(squared_distance <= 25.0F)
		return 5;
	if(squared_distance <= 100.0F)
		return 1;
	return 0;
}