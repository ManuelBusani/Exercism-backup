#include "rotational_cipher.h"

static inline char rotate_letter(char letter, int shift_key){
	if(isupper(letter))
		return 'A' + (letter - 'A' + shift_key) % 26;
	if(islower(letter))
		return 'a' + (letter - 'a' + shift_key) % 26;
	return letter;
}

char *rotate(const char *text, int shift_key){
	if(!text) return ERROR;

	size_t length = strlen(text);
	char *result = malloc(sizeof(char)*(length + 1));
	if(result == NULL) return ERROR;

	shift_key %= ALPHABET_LENGTH;
	if(shift_key < 0) shift_key += ALPHABET_LENGTH;

	for(size_t i = 0; i < length; i++){
		result[i] = rotate_letter(text[i], shift_key);
	}
	result[length] = '\0';

	return result;
}