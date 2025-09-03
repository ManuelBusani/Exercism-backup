#include "space_age.h"

float age(planet_t planet, int64_t seconds){
	if (planet < 0 || planet > 7)
		return ERROR;

	static float orbital_period[] =
	{
		0.2408467, 	// Mercury
		0.61519726, // Venus
		1.0,		// Earth
		1.8808158,	// Mars
		11.862615,	// Jupiter
		29.447498,	// Saturn
		84.016846,	// Uranus
		164.79132	// Neptune
	};

	return seconds / (orbital_period[planet] * EARTH_SECONDS);
}