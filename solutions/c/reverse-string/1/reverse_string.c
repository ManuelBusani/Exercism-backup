#include "reverse_string.h"

char *reverse(const char *value){
	if(!value) return NULL;

	size_t length = strlen(value);
	char *result = malloc((length + 1)*sizeof(char));

	if(!result) return NULL;

	for(size_t i = length; i > 0; i--, value++){
		result[i-1] = *value;
	}
	result[length] = '\0';

	return result;
}