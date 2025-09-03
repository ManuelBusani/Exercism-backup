#include "collatz_conjecture.h"

int steps(int start){
	if(start <= 0) return ERROR_VALUE;

	int stepsCounter = 0, currentStep = start;

	while(currentStep != 1){
		if(currentStep % 2 == 0)
			currentStep /= 2;
		else
			currentStep = 3*currentStep + 1;

		stepsCounter++;
	}
	return stepsCounter;
}