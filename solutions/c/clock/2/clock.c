#include "clock.h"

static void normalize_time(int *hour, int* minute){
	*hour += (*minute - (*minute < 0 ? MAX_MINUTE - 1 : 0))/MAX_MINUTE;
	*hour %= MAX_HOUR;
	if(*hour < 0) *hour += MAX_HOUR;

	*minute %= MAX_MINUTE;
	if(*minute < 0) *minute += MAX_MINUTE;
}

static void get_hour_and_minute(const clock_t *clock, int *hour, int *minute){
	*hour = (int)(clock->text[0] - '0')*10 + (int)(clock->text[1] - '0');
	*minute = (int)(clock->text[3] - '0')*10 + (int)(clock->text[4] - '0');
}

clock_t clock_create(int hour, int minute){
	normalize_time(&hour, &minute);
	clock_t clock;
	sprintf(clock.text, "%2.2d:%2.2d", hour, minute);
	return clock;
}

clock_t clock_add(clock_t clock, int minute_add){
	int hour, minute;
	get_hour_and_minute(&clock, &hour, &minute);
	return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract){
	int hour, minute;
	get_hour_and_minute(&clock, &hour, &minute);
	return clock_create(hour, minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b){
	return strcmp(a.text, b.text) == 0;
}