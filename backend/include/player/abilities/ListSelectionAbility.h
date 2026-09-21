#pragma once
#include "Ability.h"
#include <variant>

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool listIsInternal; //not 100% sure what the intention for this is
	//bool isString; <-- implicit in count
	variant<string, int> count;

	//bool forSpells; <-- this is implicit to selection_list
	variant<vector<Ability*> /*, vector<Spell>*/> selection_list;

public:
	class ListBuilder : public Builder {
		string _name;

		ListBuilder& name(const string& name) {this->_name = name; return *this;}
		ListSelectionAbility build() {return ListSelectionAbility(this);}
	};

	ListSelectionAbility(ListBuilder* builder) : Ability(builder) {
		//
	}
};
