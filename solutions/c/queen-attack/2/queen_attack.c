#include "queen_attack.h"
#include <stdbool.h>
#include <stdlib.h>

// checks if `queen_1 or `queen_2 positions are invalid.
static bool is_invalid(position_t queen_1, position_t queen_2){
	return queen_1.row > 7 || queen_1.column > 7 ||
		   queen_2.row > 7 || queen_2.column > 7 ||
		   (queen_1.row == queen_2.row && 
		   	queen_1.column == queen_2.column);
}

// checks if `queen_1 and `queen_2 are in the same row, column or diagonal.
static bool is_same_line(position_t queen_1, position_t queen_2){
	return queen_1.row == queen_2.row ||
		   queen_1.column == queen_2.column ||
		   abs(queen_1.row - queen_2.row) == 
		   abs(queen_1.column - queen_2.column);
}

attack_status_t can_attack(position_t queen_1, position_t queen_2){

	if(is_invalid(queen_1, queen_2))
		return INVALID_POSITION;

	if(is_same_line(queen_1, queen_2))
		return CAN_ATTACK;

	return CAN_NOT_ATTACK;			
}