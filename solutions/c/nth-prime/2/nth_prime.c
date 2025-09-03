#include "nth_prime.h"

typedef struct node node;

struct node{
	uint32_t value;
	struct node *next;
};

static node* create_node(uint32_t value){
	node *output = malloc(sizeof(node));
	if(output == NULL) return NULL;
	output->value = value;
	output->next = NULL;
	return output;
}

static void free_nodes(node* first){
	while(first != NULL){
		node *temp = first;
		first = first->next;
		free(temp);
	}
}

static bool is_prime(node *first, uint32_t num){
	while(first != NULL && (first->value)*(first->value) <= num){
		if(num%(first->value) == 0) return false;
		first = first->next;
	}
	return true;
}

uint32_t nth(uint32_t n){
	if(n == 0) return 0;

	// create nodes of a linked list to store prime numbers
	node *first = create_node(2);
	if(first == NULL) return ERROR;
	node *last = first;

	for(uint32_t candidate = 3; n > 1; candidate += 2){
		// if the number is prime add it to the list
		if(is_prime(first, candidate)){
			node *temp = last;
			last = create_node(candidate);
			if(last == NULL) return ERROR;
			temp->next = last;
			n--;
		}
	}

	uint32_t output = last->value;
	free_nodes(first);
	return output;
}