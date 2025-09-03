#include "triangle.h"

static bool is_triangle(triangle_t sides){
	double a = sides.a, b = sides.b, c = sides.c;
	return a + b >= c && b + c >= a && a + c >= b &&
		   a > 0 && b > 0 && c > 0;
}

bool is_equilateral(triangle_t sides){
	double a = sides.a, b = sides.b, c = sides.c;
	return a == b && b == c && is_triangle(sides);
}

bool is_isosceles(triangle_t sides){
	double a = sides.a, b = sides.b, c = sides.c;
	return (a == b || a == c || b == c) && is_triangle(sides);
}

bool is_scalene(triangle_t sides){
	double a = sides.a, b = sides.b, c = sides.c;
	return a != b && a != c && b != c && is_triangle(sides);
}