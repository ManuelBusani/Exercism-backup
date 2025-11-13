#include "list_ops.h"

/************************************************************************/
list_t *new_list(size_t length, list_element_t elements[]){
	size_t size = sizeof(list_t) + length*sizeof(list_element_t);
	list_t *list = malloc(size);
	if(!list) return NULL;

	list->length = length;
	for(size_t i = 0; i < length; i++){
		list->elements[i] = elements[i];
	}
	return list;
}
/************************************************************************/
list_t *append_list(list_t *list1, list_t *list2){
	if(!list1 || !list2) return NULL;

	size_t length = list1->length + list2->length;
	size_t size = sizeof(list_t) + length*sizeof(list_element_t);
	list_t *list = malloc(size);
	if(!list) return NULL;

	size_t i = 0;
	for(; i < list1->length; i++){
		list->elements[i] = list1->elements[i];
	}
	for(size_t j = 0; i < length; i++, j++){
		list->elements[i] = list2->elements[j];
	}
	list->length = length;

	return list;
}
/************************************************************************/
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
	if(!list || !filter) return NULL;

	size_t size = sizeof(list_t)+list->length*sizeof(list_element_t);
	list_t *filtered = malloc(size); // could maybe realloc filtered later
	if(!filtered) return NULL;

	filtered->length = 0;
	for(size_t i = 0; i < list->length; i++){
		if(filter(list->elements[i])){
			filtered->elements[(filtered->length)++] = list->elements[i];
		}
	}
	return filtered;
}
/************************************************************************/
size_t length_list(list_t *list){
	if(!list) return 0;
	return list->length;
}
/************************************************************************/
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
	if(!list || !map) return NULL;
	
	size_t size = sizeof(list_t)+list->length*sizeof(list_element_t);
	list_t *mapped = malloc(size);
	if(!mapped) return NULL;

	mapped->length = list->length;
	for(size_t i = 0; i < list->length; i++){
		mapped->elements[i] = map(list->elements[i]);
	}
	return mapped;
}
/************************************************************************/
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)){
	if(!foldl || !list) return initial;

	for(size_t i = 0; i < list->length; i++){
		initial = foldl(initial, list->elements[i]);
	}
	return initial;
}
/************************************************************************/
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)){
	if(!foldr || !list) return initial;

	for(size_t i = list->length; i != 0;){
		initial = foldr(list->elements[--i], initial);
	}
	return initial;
}
/************************************************************************/
list_t *reverse_list(list_t *list){
	if(!list) return NULL;
	
	size_t size = sizeof(list_t)+list->length*sizeof(list_element_t);
	list_t *reversed = malloc(size);
	if(!reversed) return NULL;

	reversed->length = list->length;
	for(size_t i = 0, offset = list->length-1; i < list->length; i++){
		reversed->elements[i] = list->elements[offset-i];
	}
	return reversed;
}
/************************************************************************/
void delete_list(list_t *list){
	free(list);
}