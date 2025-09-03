#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
	return (robot_status_t) { 
		.direction = direction,
		.position = (robot_position_t) {.x = x, .y = y}
	};
}

void robot_move(robot_status_t *robot, const char *commands){
	for(; *commands != '\0'; commands++){
		switch(*commands){
			case 'A':
				if(robot->direction%2 == 0)
					robot->position.y += 1 - robot->direction;
				else robot->position.x += 2 - robot->direction;
				break;
			case 'R':
				robot->direction = (robot->direction + 1)&3;
				break;
			case 'L':
				robot->direction = (robot->direction - 1)&3;
		}
	}
}