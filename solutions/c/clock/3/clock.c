#include "clock.h"

static void normalize_time(int *hour, int* minute){
	*hour += (*minute - (*minute < 0 ? MAX_MINUTE - 1 : 0))/MAX_MINUTE;
	*hour %= MAX_HOUR;
	if(*hour < 0) *hour += MAX_HOUR;

	*minute %= MAX_MINUTE;
	if(*minute < 0) *minute += MAX_MINUTE;
}

clock_t clock_create(int hour, int minute){
	normalize_time(&hour, &minute);
	clock_t clock;
	sprintf(clock.text, "%2.2d:%2.2d", hour, minute);
	return clock;
}

clock_t clock_add(clock_t clock, int minute_add){
	int hour, minute;
	sscanf(clock.text, "%d:%d", &hour, &minute);
	return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract){
	int hour, minute;
	sscanf(clock.text, "%d:%d", &hour, &minute);
	return clock_create(hour, minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b){
	return strcmp(a.text, b.text) == 0;
}