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
		vector<string> _hooks;
		bool _listIsInternal;
		variant<string, int> _count;
		variant<vector<Ability*>/*, *Spells*/> _selection_list;


	public:
		ListBuilder& hooks(const vector<string>& hooks) {this->_hooks = hooks; return *this;}
		ListBuilder& isInternal(bool isInternal) {this->_listIsInternal = isInternal; return *this;}
		ListBuilder& count(const variant<string, int>& _count) {this->_count = _count; return *this;}
		ListBuilder& selection_list(const variant<vector<Ability*>/*, *Spells*/>& _selection_list) {this->_selection_list = _selection_list; return *this;}
		ListSelectionAbility build() {return ListSelectionAbility(this);}
	};

	ListSelectionAbility(ListBuilder* builder) : Ability(builder) {
		//
	}
};
