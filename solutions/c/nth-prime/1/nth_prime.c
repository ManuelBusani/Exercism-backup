#include "nth_prime.h"

typedef struct node node;

struct node{
	uint32_t value;
	struct node *next;
};

static node* create_node(uint32_t value){
	node *output = malloc(sizeof(node));
	output->value = value;
	output->next = NULL;
	return output;
}

static void free_nodes(node* first){
	node *temp;
	while(first != NULL){
		temp = first;
		first = first->next;
		free(temp);
	}
}

static bool is_prime(node *first, uint32_t num){
	do{
		if(num%(first->value) == 0) return false;
		first = first->next;
	} while(first != NULL);

	return true;
}

uint32_t nth(uint32_t n){
	if(n == 0) return 0;

	// create nodes of a linked list to store prime numbers
	node *first = create_node(2);
	node *last = first;

	uint32_t candidate = 3;
	while(n > 1){
		// if the number is prime add it to the list
		if(is_prime(first, candidate)){
			node *temp = last;
			last = create_node(candidate);
			temp->next = last;
			n--;
		}
		candidate += 2;
	}

	uint32_t output = last->value;
	free_nodes(first);
	return output;
}