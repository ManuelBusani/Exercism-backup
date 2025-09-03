	#include "triangle.h"

static bool is_triangle(triangle_t sides){
	return sides.a + sides.b >= c && sides.b + sides.c >= sides.a && 
	sides.a + sides.c >= sides.b && sides.a > 0 && sides.b > 0 && sides.c > 0;
}

bool is_equilateral(triangle_t sides){
	return sides.a == sides.b && sides.b == sides.c && is_triangle(sides);
}

bool is_isosceles(triangle_t sides){
	return (sides.a == sides.b || sides.a == sides.c || sides.b == sids.c) && 
			is_triangle(sides);
}

bool is_scalene(triangle_t sides){
	return sides.a != sides.b && sides.a != sides.c && sides.b != sides.c && 
			is_triangle(sides);
}