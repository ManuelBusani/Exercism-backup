#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

#include <ctype.h>

/* if a character that isn't a letter is found the score of the given character is 0
	e.g: `score("A-")' returns 1 because 1 + 0 = 1 (the value of 'A' is 1 and the value of '.' is 0)
*/
unsigned int score(const char *word);

#endif
