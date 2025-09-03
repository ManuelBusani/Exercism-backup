#include "spiral_matrix.h"

static spiral_matrix_t *spiral_matrix_allocate(int size){
	spiral_matrix_t *spiral = malloc(sizeof(spiral_matrix_t));
	if(!spiral) return NULL;

	if(size <= 0){
		spiral->matrix = NULL;
		spiral->size = 0;
		return spiral;
	}

	spiral->size = size;
	spiral->matrix = malloc(size*sizeof(int*));
	if(!spiral->matrix){
		free(spiral);
		return NULL;
	}

	spiral->matrix[0] = malloc(size*size*sizeof(int));
	if(!spiral->matrix[0]){
 		free(spiral->matrix);
		free(spiral);
		return NULL;
 	}
  	
  	for(int i = 1; i < size; i++){
		spiral->matrix[i] = spiral->matrix[i-1] + size;
	}

	return spiral;
}

static void spiral_matrix_fill(spiral_matrix_t *spiral){
	int number = 1, limit = spiral->size-1, layer = 0;

	for(; limit > 0; limit -= 2){
		for(int i = 0; i < limit; i++){
			spiral->matrix[layer][layer+i] = number++;
		}
		for(int i = 0; i < limit; i++){
			spiral->matrix[layer+i][layer+limit] = number++;
		}
		for(int i = limit; i > 0; i--){
			spiral->matrix[layer+limit][layer+i] = number++;
		}
		for(int i = limit; i > 0; i--){
			spiral->matrix[layer+i][layer] = number++;
		}
		layer++;
	}

	if(limit == 0){
		spiral->matrix[layer][layer] = number;
	}
}

spiral_matrix_t *spiral_matrix_create(int size){
	spiral_matrix_t *spiral = spiral_matrix_allocate(size);
	if(!spiral) return NULL;
	spiral_matrix_fill(spiral);
	return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *spiral){
	if(spiral->size > 0){
		free(*(spiral->matrix));
		free(spiral->matrix);
	}
   	free(spiral);
}