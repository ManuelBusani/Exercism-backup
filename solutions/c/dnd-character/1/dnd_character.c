#include "dnd_character.h"

int ability(void){
	srand(time(NULL));
	int rolls[] = {0,0,0,0};
	int indexMin = 0;

	for(int i = 0; i < 4; ++i){
		rolls[i] = rand()%6 + 1;
		if(rolls[i] < rolls[indexMin])
			indexMin = i;
	}

	int sum = 0;
	for(int i = 0; i != indexMin; ++i){
		sum += rolls[i];
	}
	for(int i = indexMin+1; i < 4; ++i){
		sum += rolls[i];
	}

	return sum;
}

int modifier(int score){
	return score/2 - 5;
}
dnd_character_t make_dnd_character(void){
	dnd_character_t character;
	character.strength = ability();
	character.dexterity = ability();
	character.constitution = ability();
	character.intelligence = ability();
	character.wisdom = ability();
	character.charisma = ability();
	character.hitpoints = 10 + modifier(character.constitution);
	return character;
}