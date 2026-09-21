#pragma once
#include "Ability.h"
#include <variant>

class ListReplacementAbility : public Ability {
private:
	vector<string> hooks;
	variant<string, int> count;
	variant<vector<Ability*>/*, Spell*/> selectionList;
	string targetAbility; //should this be a reference? dangerous with various containers

public:
	class ListReplacementBuilder : public Builder {
		vector<string> _hooks;
		variant<string, int> _count;
		variant<vector<Ability*>/*, Spell*/> _selectionList;
		string _targetAbility;


		ListReplacementBuilder& hooks(const vector<string>& hooks) {this->_hooks = hooks; return *this;}
		ListReplacementBuilder& count(const variant<string, int>& count) {this->_count = count; return *this;}
		ListReplacementBuilder& selectionList(const variant<vector<Ability*>/*, *Spells*/>& selection_list) {this->_selectionList = selection_list; return *this;}
		ListReplacementBuilder& targetAbility(const string& target) {this->_targetAbility = target; return *this;}
		ListReplacementAbility build() {return ListReplacementAbility(this);}

		friend class ListReplacementAbility;
	};
private:
	ListReplacementAbility(ListReplacementBuilder* builder) : Ability(builder) {
		this->hooks = builder->_hooks;
		this->count = builder->_count;
		this->selectionList = builder->_selectionList;
		this->targetAbility = builder->_targetAbility;
	}

	~ListReplacementAbility();

public:
	const vector<string>& getHooks() const {return this->hooks;}
	const variant<string, int>& getCount() const {return this->count;}
	const variant<vector<Ability*>/*, Spell*/> getSelectionList() const {return this->selectionList;}
	const string& getTargetAbility() const {return this->targetAbility;}
};
