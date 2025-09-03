#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

#define ERROR -1.0
#define EARTH_SECONDS 31557600   // earth year in seconds

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

float age(planet_t planet, int64_t seconds);

#endif
