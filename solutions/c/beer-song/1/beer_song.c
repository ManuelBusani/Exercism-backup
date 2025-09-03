#include "beer_song.h"

static inline void recite_generic_verse(uint8_t bottles, char **song){
	sprintf(*(song++), "%d bottles of beer on the wall, %d bottles of beer.", bottles, bottles);
	sprintf(*song, "Take one down and pass it around, %d bottles of beer on the wall.", bottles-1);
}

static inline void recite_2_bottles(char **song){
	sprintf(*(song++), "2 bottles of beer on the wall, 2 bottles of beer.");
	sprintf(*song, "Take one down and pass it around, 1 bottle of beer on the wall.");
}

static inline void recite_1_bottle(char **song){
	sprintf(*(song++), "1 bottle of beer on the wall, 1 bottle of beer.");
	sprintf(*song, "Take it down and pass it around, no more bottles of beer on the wall.");
}

static inline void recite_0_bottle(char **song){
	sprintf(*(song++), "No more bottles of beer on the wall, no more bottles of beer.");
	sprintf(*song, "Go to the store and buy some more, 99 bottles of beer on the wall.");
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song){

	while(start_bottles >= 3){
		if(take_down == 0) return;
		recite_generic_verse(start_bottles--, song);
		song += 2;
		**(song++) = '\0';
		take_down--;
	}
	
	if(take_down == 0) return;
	
	switch(start_bottles){
		case 2:
			recite_2_bottles(song);
			if(--take_down == 0) return;
			song += 2;
			**(song++) = '\0';
			/* FALLTHRU */
		case 1:
			recite_1_bottle(song);
			if(--take_down == 0) return;
			song += 2;
			**(song++) = '\0';
			/* FALLTHRU */
		case 0:
			recite_0_bottle(song);
	}
}