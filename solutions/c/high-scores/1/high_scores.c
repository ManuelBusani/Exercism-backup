#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len){
	return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
	int32_t best = 0;

	for(size_t i = 0; i < scores_len; ++i){
		if(scores[i] > best)
			best = scores[i];
	}

	return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output){

	for(size_t i = 0; i < scores_len; ++i){

		int32_t current_score = scores[i];

		if(current_score > output[2]){

			if(current_score > output[1]){
				output[2] = output[1];

				if(current_score > output[0]){
					output[1] = output[0];
					output[0] = current_score;

				} else output[1] = current_score;

			} else output[2] = current_score;
		}
	}
	return scores_len >= 3 ? 3 : scores_len;
}