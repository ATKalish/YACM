#pragma once
#include "Ability.h"
#include <variant>

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool listIsInternal; //not 100% sure what the intention for this is
	variant<string, int> count;
	variant<vector<Ability*> /*, vector<Spell>*/> selection_list;

public:
	class ListBuilder : public Builder {

		ListSelectionAbility build() {return ListSelectionAbility(this);}
	};

	ListSelectionAbility(ListBuilder* builder) : Ability(builder) {
		//
	}
};
