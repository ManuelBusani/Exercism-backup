#ifndef SQUARE_ROOT_H
#define SQUARE_ROOT_H

#include <stdint.h>

/* Implementation of integer square root using Newton-Rapshon's method, taken from
https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method */
uint16_t square_root(uint16_t radicand);

#endif
