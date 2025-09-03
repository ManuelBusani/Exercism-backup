#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#define MAX_STRING_SIZE sizeof("A:X C:X G:X T:X") + 16

#include <stdio.h>
#include <stdlib.h>

char *count(const char *dna_strand);

#endif
