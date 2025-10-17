#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

// sets roster count to 0
void init_roster(roster_t *roster);

// adds student to the students array while maintaining order,
// name is case sensitive
bool add_student(roster_t *roster, const char *name, int grade);

// returns roster with students of the desired grade
roster_t get_grade(roster_t *roster, int desired_grade);

#endif
