#ifndef RNA_TRANSCRIPTION_H
#define RNA_TRANSCRIPTION_H

#include<stdlib.h>


/* getting something with memcheck, 
 * gonna check community solutions
 *
 * AddressSanitizer: heap-buffer-overflow rna_transcription.c:16 in to_rna
 */
char *to_rna(const char *dna);

#endif
