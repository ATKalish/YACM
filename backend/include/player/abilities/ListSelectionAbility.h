#pragma once
#include "Ability.h"

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool isString;
	bool listIsInternal;
	union count_{
		string id;
		int value;
	} count;
	// TODO: rest of list selection
};
