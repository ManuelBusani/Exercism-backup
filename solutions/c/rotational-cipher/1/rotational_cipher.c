#include "rotational_cipher.h"

static inline char rotate_letter(char letter, int shift_key){
	if(isupper(letter)){
		letter += shift_key;
		if(letter > 'Z') 
			letter -= ALPHABET_LENGTH;

	} else if(islower(letter)){
		if(letter > 'z' - shift_key) 
			letter -= ALPHABET_LENGTH;
		letter += shift_key;
	}

	return letter;
}

char *rotate(const char *text, int shift_key){
	if(!text) return ERROR;

	shift_key %= ALPHABET_LENGTH;
	if(shift_key < 0) shift_key += ALPHABET_LENGTH;

	size_t length = strlen(text);
	char *result = malloc(sizeof(char)*(length + 1));
	result[length] = '\0';

	for(size_t i = 0; i < length; i++){
		result[i] = rotate_letter(text[i], shift_key);
	}

	return result;
}