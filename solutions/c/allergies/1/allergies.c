#include "allergies.h"

bool is_allergic_to(allergen_t item, int score){
	return (bool)(score & (1 << item));
}


allergen_list_t get_allergens(int score){
	allergen_list_t list = (allergen_list_t){.count = 0};

	for(allergen_t item = 0; item < ALLERGEN_COUNT; item++){
		list.allergens[item] = is_allergic_to(item,score);
		if(list.allergens[item]) list.count++;
	}
	return list;
}