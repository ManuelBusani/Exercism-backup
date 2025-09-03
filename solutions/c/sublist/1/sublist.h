#ifndef SUBLIST_H
#define SUBLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef enum { EQUAL, UNEQUAL, SUBLIST, SUPERLIST } comparison_result_t;

comparison_result_t check_lists(int *a, int *b, size_t legnth_a, size_t length_b);

#endif
