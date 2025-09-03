#include "kindergarten_garden.h"

#define NUMBER_OF_STUDENTS sizeof(students_list)/sizeof(char*)

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
	assert(0); // case in which `student' was not found
}

static plant_t map_letter(char character){
	switch(character){
		case 'G':
			return GRASS;
		case 'C':
			return CLOVER;
		case 'R':
			return RADISHES;
		case 'V':
			return VIOLETS;
	}
	assert(0);
}

plants_t plants(const char *diagram, const char *student){
	assert(diagram != NULL && student != NULL);

	size_t student_index = 2*get_index(student);
	size_t length = strlen(diagram), offset = length/2+1;

	assert(student_index + offset + 1 < length);

	return (plants_t){
		.plants = { map_letter(diagram[student_index]),
					map_letter(diagram[student_index + 1]),
					map_letter(diagram[student_index + offset]),
					map_letter(diagram[student_index + offset + 1])}
	};
}