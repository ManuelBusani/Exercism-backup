#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <errno.h>

typedef int16_t buffer_value_t;

typedef struct{
	buffer_value_t *values;
	size_t capacity;
	size_t size;		// number of values currently in the buffer
	size_t add_idx;		// index where the newest value was added
	size_t rmv_idx;		// index where the oldest value was added
}circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *buffer);

void clear_buffer(circular_buffer_t *buffer);

int16_t write(circular_buffer_t *buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

/* stores stuff in `read_value' and data in the buffer is deleted?
 *
 * if this function is called with an empty buffer 
 * errno is set to ENODATA and the return value is EXIT_FAILURE
 */
int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value);

#endif
