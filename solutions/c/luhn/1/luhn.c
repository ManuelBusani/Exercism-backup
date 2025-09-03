#include "luhn.h"

typedef enum {		// expecting to read:
	EVEN = 0,	 	// 		a digit in an even position
	ODD = 1,		// 		a digit in an odd position
	SECOND = 2, 	// 		the second digit from right to left
	FIRST = 3 		// 		the first digit from right to left
} state_t;

bool luhn(const char *num){
	if(!num) return false;
	size_t length = strlen(num);
	if(length <= 1) return false;	

	int sum = 0;
	state_t state = FIRST;

	while(length > 0){
		char element = num[length - 1];

		if(element != ' ') {
			if(element < '0' || element > '9') return false;
			int digit = (int)(element - '0');

			switch(state){
				case ODD:
					sum += digit;
					state = EVEN;
					break;

				case EVEN:
				case SECOND:
					sum += (digit >= 5 ? 2*digit - 9: 2*digit);
					state = ODD;
					break;
				
				case FIRST:
					sum += digit;
					state = SECOND;
			}
		}

		length--;
	}

	return state < SECOND && sum%10 == 0;
}