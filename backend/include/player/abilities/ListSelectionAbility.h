#pragma once
#include "Ability.h"

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool listIsInternal; //not 100% sure what the intention for this is
	// TODO: convert to a std::variant
	bool isString; //which union field to use
	union count_{ //either it is a string id, or a set value
		string id;
		int value;
	} count;

	// TODO: convert to a std::variant
	bool forSpells;
	union selection_list_ {
		vector<Ability*>;
		//vector<Spell>
	} selection_list;

};
