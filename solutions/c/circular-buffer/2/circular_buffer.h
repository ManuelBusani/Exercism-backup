#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stddef.h>

typedef int16_t buffer_value_t;

typedef struct{
	buffer_value_t *values;
	size_t capacity;    // maximum number of values that can be stored
	size_t size;		// number of values currently in the buffer
	size_t new_idx;		// index where the newest value was added
	size_t old_idx;		// index where the oldest value was added
}circular_buffer_t;

/* Allocates memory for an empty buffer of the given capacity.
 *
 * Return values:
 *   If the capacity is 0 or the buffer couldn't be allocated it returns NULL
 *
 *   In other case returns the allocated buffer.
 */
circular_buffer_t *new_circular_buffer(size_t capacity);

/* Frees memory used by the buffer.
 */
void delete_buffer(circular_buffer_t *buffer);

/* Modifies buffer as if it was a newly created buffer.
 */
void clear_buffer(circular_buffer_t *buffer);

/* Stores `value' at the buffer.
 * 
 * Returns values:
 *   If buffer is NULL returns EXIT_FAILURE.
 *
 *   If buffer is full errno is set to ENOBUFS and returns EXIT_FAILURE.
 *
 *   In other case returns EXIT_SUCCESS.
 */
int16_t write(circular_buffer_t *buffer, buffer_value_t value);

/* Stores `value' at the buffer, if the buffer is full it ovewrites 
 * the oldest value.
 * 
 * Return values:
 *   If buffer is NULL returns EXIT_FAILURE
 *
 *   In other case returns EXIT_SUCCESS
 */
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

/* Stores in `read_value' the oldest value written at the buffer.
 *
 * Return values:
 *   If buffer is NULL the return value is EXIT_FAILURE.
 *
 *   If the buffer is empty errno is set to ENODATA and 
 *   the return value is EXIT_FAILURE.
 *
 *   In other case returns EXIT_SUCCESS.
 */
int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value);

#endif
