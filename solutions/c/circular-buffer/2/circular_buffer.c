#include "circular_buffer.h"

#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#define next_idx(idx,capacity) (idx+1 < capacity? idx+1: 0)

circular_buffer_t *new_circular_buffer(size_t capacity){
	if(capacity == 0) return NULL;

	circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));
	if(!buffer) goto ALLOC_ERROR;
	
	buffer->values = malloc(capacity*sizeof(buffer_value_t));
	if(!buffer->values){
		free(buffer);
		goto ALLOC_ERROR;
	}

	buffer->capacity = capacity;
	buffer->size = 0;
	buffer->new_idx = capacity-1;
	buffer->old_idx = 0;
	return buffer;

	ALLOC_ERROR:
		return NULL;
}

void delete_buffer(circular_buffer_t *buffer){
	if(!buffer) return;
	free(buffer->values);
	free(buffer);
}

void clear_buffer(circular_buffer_t *buffer){
	if(!buffer) return;
	buffer->size = 0;
	buffer->new_idx = buffer->capacity-1;
	buffer->old_idx = 0;
}

static void generic_write(circular_buffer_t *buffer, buffer_value_t value){
	buffer->new_idx = next_idx(buffer->new_idx, buffer->capacity);
	buffer->values[buffer->new_idx] = value;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value){
	if(!buffer){
		// errno = somethin; add later
		return EXIT_FAILURE;
	}
	if(buffer->size == buffer->capacity){
		errno = ENOBUFS;
		return EXIT_FAILURE;
	}
	generic_write(buffer,value);
	buffer->size++;
	return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value){
	if(!buffer){
		// errno = somethin; add later
		return EXIT_FAILURE;
	}
	generic_write(buffer,value);

	if(buffer->size == buffer->capacity){
		buffer->old_idx = next_idx(buffer->old_idx, buffer->capacity);
	} else buffer->size++;

	return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value){
	if(!buffer){
		return EXIT_FAILURE;
	}

	if(buffer->size == 0){
		errno = ENODATA;
		return EXIT_FAILURE;
	}

	*read_value = buffer->values[buffer->old_idx];
	buffer->old_idx = next_idx(buffer->old_idx, buffer->capacity);
	buffer->size--;
	return EXIT_SUCCESS;
}