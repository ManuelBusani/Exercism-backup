#include "queen_attack.h"
#include <stdbool.h>

bool is_invalid(position_t queen_1, position_t queen_2);
bool is_same_diagonal(position_t queen_1, position_t queen_2);

// checks if `queen_1 or `queen_2 position is invalid
bool is_invalid(position_t queen_1, position_t queen_2){
	return queen_1.row > 7 || queen_1.column > 7 ||
		   queen_2.row > 7 || queen_2.column > 7 ||
		   (queen_1.row == queen_2.row && 
		   	queen_1.column == queen_2.column);
}

// checks if `queen_1 and `queen_2 are in the same diagonal
bool is_same_diagonal(position_t queen_1, position_t queen_2){
	int row_distance = queen_1.row > queen_2.row ? 
					   queen_1.row - queen_2.row :
					   queen_2.row - queen_1.row;

	int column_distance = queen_1.column > queen_2.column ? 
						  queen_1.column - queen_2.column :
						  queen_2.column - queen_1.column;

	return row_distance == column_distance;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2){

	if (is_invalid(queen_1, queen_2))
		return INVALID_POSITION;

	if(queen_1.row == queen_2.row || 
	   queen_1.column == queen_2.column ||
	   is_same_diagonal(queen_1, queen_2))
		return CAN_ATTACK;

	return CAN_NOT_ATTACK;

			
}