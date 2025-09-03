#include "yacht.h"

#define NUMBER_OF_DICE 5

static bool is_valid_dice(dice_t dice){
	for(unsigned i = 0; i < NUMBER_OF_DICE; i++){
		int face = dice.faces[i];
		if(face < 1 || face > 6) return false;
	}
	return true;
}

static int same_number_dice(dice_t dice, category_t category){
	int face = (int)category + 1;
	int score = 0;
	for(unsigned i = 0; i < NUMBER_OF_DICE; i++){
		if(face == dice.faces[i]){
			score += face;
		}
	}
	return score;
}

static int full_house(dice_t dice){
	int num1 = dice.faces[0], num2, score = dice.faces[0];
	unsigned num1_count = 1, i = 1;

	while(i < NUMBER_OF_DICE - 1){
		int face = dice.faces[i++];
		score += face;
		if(face == num1) {
			num1_count++;
		} else {
			num2 = face;
			break;
		}
	}
	if(num1_count == NUMBER_OF_DICE - 1) return 0;

	while(i < NUMBER_OF_DICE){
		int face = dice.faces[i++];
		score += face;
		if(face == num1){
			num1_count++;
		} else if(face != num2) return 0;
	}

	if(num1_count < 2 || num1_count > 3) return 0;
	return score;
}

static int four_of_a_kind(dice_t dice){
	int face = dice.faces[0];
	bool different_face = false; // when a face different to the first is found this is set to true
	unsigned i = 1;
	if(dice.faces[1] != face){
		if(dice.faces[2] != face){
			face = dice.faces[1];
			if(dice.faces[2] != face) return 0;
		}
		different_face = true;
		i = 3;
	}
	for(; i < NUMBER_OF_DICE; i++){
		if(dice.faces[i] != face){
			if(different_face) return 0;
			different_face = true;
		}
	}
	return 4*face;
}

static int little_straight(dice_t dice){
	bool numbers[5] = {false};
	for(unsigned i = 0; i < NUMBER_OF_DICE; i++){
		int face = dice.faces[i];
		if(face == 6 || numbers[face-1]) return 0;
		numbers[face-1] = true;
	}
	return 30;
}

static int big_straight(dice_t dice){
	bool numbers[5] = {false};
	for(unsigned i = 0; i < NUMBER_OF_DICE; i++){
		int face = dice.faces[i];
		if(face == 1 || numbers[face-2]) return 0;
		numbers[face-2] = true;
	}
	return 30;
}

static int choice(dice_t dice){
	int score = 0;
	for(unsigned i = 0; i < NUMBER_OF_DICE; i++){
		score += dice.faces[i];
	}
	return score;
}

static int yacht(dice_t dice){
	int face = dice.faces[0];
	for(unsigned i = 1; i < NUMBER_OF_DICE; i++){
		if(dice.faces[i] != face) return 0;
	}
	return 50;
}

int score(dice_t dice, category_t category){
	if(!is_valid_dice(dice)) return 0;
	
	switch(category){
		case FULL_HOUSE:
			return full_house(dice);
		case FOUR_OF_A_KIND:
			return four_of_a_kind(dice);
		case LITTLE_STRAIGHT:
			return little_straight(dice);
		case BIG_STRAIGHT:
			return big_straight(dice);
		case CHOICE:
			return choice(dice);
		case YACHT:
			return yacht(dice);
		default:
			return same_number_dice(dice,category);
	}
}