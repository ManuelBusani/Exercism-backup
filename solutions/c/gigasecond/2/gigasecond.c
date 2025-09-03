#include "gigasecond.h"

//"YYYY-mm-dd HH:MM:SS"

void gigasecond(time_t input, char *output, size_t size){
	time_t epoch_time = input + 1e9;
	struct tm* calendar_time = gmtime(&epoch_time);

	strftime(output, size, "%F %T", calendar_time);

}