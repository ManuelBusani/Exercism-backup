#include "pangram.h"

bool is_pangram(const char *sentence){
	if(sentence == NULL) return false;

	bool used_letters[26] = {false};

	for(; *sentence; ++sentence){
		int letter_index= *sentence-(*sentence < 'a'?'A':'a');
		if(letter_index >= 0 && letter_index <=25)
			used_letters[letter_index] = true;
	}

	for(int i = 0; i < 26; ++i){
		if(!used_letters[i]) return false;
	}
	
	return true;
}