#include "two_fer.h"

void two_fer(char *buffer, const char *name){
	char *message = "One for _, one for me.";
	for(;*message != '_'; ++message, ++buffer)
		*buffer = *message;
	++message;

	if(name){
		for(; *name != '\0'; ++name, ++buffer)
			*buffer = *name;
	} else{
		buffer[0] = 'y';
		buffer[1] = 'o';
		buffer[2] = 'u';
		buffer += 3;
	}

	for(;*message != '\0'; ++message, ++buffer)
		*buffer = *message;
	*buffer = '\0';
}