#include "kindergarten_garden.h"

#define NUMBER_OF_STUDENTS sizeof(students_list)/sizeof(char*)
#define ERROR (plants_t){.plants = 0};

// When adding a student to `students_list' the list should mantain alphabetical order
const char *students_list[] = {
	"Alice", "Bob", "Charlie", "David",
	"Eve", "Fred","Ginny", "Harriet",
	"Ileana", "Joseph", "Kincaid", "Larry"};

// Use binary search to search `student' in `students_list'
static size_t get_index(const char *student){
	size_t bottom = 0, top = NUMBER_OF_STUDENTS;

	while(bottom < top){
		size_t middle = bottom + (top - bottom)/2;
		int comparision = strcmp(students_list[middle],student);

		if(comparision == 0)
			return middle;

		if(comparision < 0)
			bottom = middle + 1;
		
		else top = middle;
	}
	// case in which `student' was not found
	return NUMBER_OF_STUDENTS;
}

static plant_t map_letter(char character){
	switch(character){
		case 'G':
			return GRASS;
		case 'C':
			return CLOVER;
		case 'R':
			return RADISHES;
		default:
			return VIOLETS;
	}
}

plants_t plants(const char *diagram, const char *student){
	if(diagram == NULL || student == NULL) 
		return ERROR;

	size_t student_index = get_index(student);

	if(student_index == NUMBER_OF_STUDENTS)
		return ERROR;

	size_t length = strlen(diagram), offset = length/2+1;
	student_index *= 2;

	if(student_index + offset + 1 > length)
		return ERROR;

	return (plants_t){
		.plants = { map_letter(diagram[student_index]),
					map_letter(diagram[student_index + 1]),
					map_letter(diagram[student_index + offset]),
					map_letter(diagram[student_index + offset + 1])}
	};
}