#ifndef ROTATIONAL_CIPHER_H
#define ROTATIONAL_CIPHER_H

#define ERROR NULL
#define ALPHABET_LENGTH 26

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *rotate(const char *text, int shift_key);

#endif
