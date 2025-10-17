#include "grade_school.h"

// function to establish order of students and check if the names are the same
// 0 means the names are the same
// negative number means a < b
// positive number means a > b
static int student_compare(student_t a, student_t b){
	int cmp = strcmp(a.name,b.name);
	if(cmp == 0) return 0;
	if(a.grade < b.grade) return -1;
	if(a.grade == b.grade) return cmp;
	return 1;
}

void init_roster(roster_t *roster){
	roster->count = 0;
}

bool add_student(roster_t *roster, const char *name, int grade){
	if(roster == NULL) return false;
	if(roster->count >= MAX_STUDENTS) return false;
	if(strlen(name)+1 > MAX_NAME_LENGTH) return false;

	// init student
	student_t student;
	student.grade = grade;
	strcpy(student.name, name);

	// check where to add student while checking if name is repeated
	student_t *students = roster->students;
	int i = roster->count;
	int index_to_insert = 0;
	while(i > 0){
		int cmp = student_compare(student, students[--i]);
		if(cmp < 0) continue;
		if(cmp == 0) return false;
		index_to_insert = i + 1;
		break;
	}

	// continue checking to see if name is repeated
	while(i > 0){
		if(strcmp(name, students[--i].name) == 0)
			return false;
	}

	// modify roster and add student
	for(int i = roster->count; i > index_to_insert; i--){
		students[i] = students[i-1];
	}
	students[index_to_insert] = student;
	roster->count++;

	return true;
}

roster_t get_grade(roster_t *roster, int desired_grade){
	if(!roster)	return (roster_t){.count = 0};

	roster_t result;
	result.count = 0;
	student_t *students = roster->students;

	size_t i = 0;
	while(i < roster->count && students->grade < desired_grade){
		i++;
		students++;
	}

	while(i < roster->count && students[result.count].grade == desired_grade){
		i++;
		result.count++;
	}

	memcpy(result.students, students, result.count*(sizeof(student_t)));
	return result;
}
