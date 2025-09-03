#include "clock.h"

static void get_hour_and_minute(clock_t *clock, int *hour, int *minute){
	*hour = (int)(clock->text[0] - '0')*10 + (int)(clock->text[1] - '0');
	*minute = (int)(clock->text[3] - '0')*10 + (int)(clock->text[4] - '0');
}

clock_t clock_create(int hour, int minute){
	hour += (minute - (minute < 0 ? 59 : 0))/60;
	hour %= 24;
	if(hour < 0) hour += 24;

	minute %= 60;
	if(minute < 0) minute += 60;

	return (clock_t){
		.text[0] = (char)(hour/10) + '0',
		.text[1] = (char)(hour%10) + '0',
		.text[2] = ':',
		.text[3] = (char)(minute/10) + '0',
		.text[4] = (char)(minute%10) + '0'
	};
}

clock_t clock_add(clock_t clock, int minute_add){
	int hour, minute;
	get_hour_and_minute(&clock,&hour,&minute);
	minute += minute_add;
	return clock_create(hour,minute);
}
clock_t clock_subtract(clock_t clock, int minute_subtract){
	int hour, minute;
	get_hour_and_minute(&clock,&hour,&minute);
	minute -= minute_subtract;
	return clock_create(hour,minute);
}

bool clock_is_equal(clock_t a, clock_t b){
	int hour_a, hour_b, minute_a, minute_b;
	get_hour_and_minute(&a,&hour_a,&minute_a);
	get_hour_and_minute(&b,&hour_b,&minute_b);
	return hour_a == hour_b && minute_a == minute_b;
}