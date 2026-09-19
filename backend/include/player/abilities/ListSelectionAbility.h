#pragma once
#include "Ability.h"

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool listIsInternal;
	// TODO: convert to a std::variant
	bool isString; //which union field to use
	union count_{ //either it is a string id, or a set value
		string id;
		int value;
	} count;
};
