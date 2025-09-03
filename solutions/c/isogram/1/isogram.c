#include "isogram.h"

static const unsigned NOT_LETTER = 27;

// computes the letter index of an ascii character,
// when the character isnt a letter it returns `NOT_LETTER`
static unsigned get_letter_index(char letter){
	letter |= 32;

	if(letter < 'a' || letter > 'z')
		return NOT_LETTER;

	return letter - 'a';
}

bool is_isogram(const char phrase[]){
	if(!phrase) return false;
	bool seen_letters[26] = {false};

	for(;*phrase != '\0'; ++phrase){
		unsigned letter = get_letter_index(*phrase);
		if(letter != NOT_LETTER){
			if(seen_letters[letter]) return false;
			seen_letters[letter] = true;
		}
	}

	return true;
}