#include "gigasecond.h"

//"yyyy-mm-dd hh:mm:ss"
static const size_t DATE_SIZE = 20;

void gigasecond(time_t input, char *output, size_t size){
	if(size < DATE_SIZE) return;

	time_t epoch_time = input + 1000000000;
	struct tm* calendar_time = gmtime(&epoch_time);

	// temporal solution, this `36` is probably wrong?
	snprintf(output, 36, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d", 
		calendar_time->tm_year + 1900,
		calendar_time->tm_mon + 1,
		calendar_time->tm_mday,
		calendar_time->tm_hour,
		calendar_time->tm_min,
		calendar_time->tm_sec
	);

}