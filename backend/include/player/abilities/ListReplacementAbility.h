#pragma once
#include "Ability.h"
#include <variant>

class ListReplacementAbility : public Ability {
private:
	vector<string> hooks;
	variant<Formula, int> count;
	variant<vector<Ability*>/*, Spell*/> selectionList;
	string targetAbility; //should this be a reference? dangerous with various containers

public:
	class Builder : public Ability::Builder {
		vector<string> _hooks;
		variant<Formula, int> _count;
		variant<vector<Ability*>/*, Spell*/> _selectionList;
		string _targetAbility;


		Builder& hooks(const vector<string>& hooks) {this->_hooks = hooks; return *this;}
		Builder& count(const variant<Formula, int>& count) {this->_count = count; return *this;}
		Builder& selectionList(const variant<vector<Ability*>/*, *Spells*/>& selection_list) {this->_selectionList = selection_list; return *this;}
		Builder& targetAbility(const string& target) {this->_targetAbility = target; return *this;}
		ListReplacementAbility build() {return ListReplacementAbility(this);}

		friend class ListReplacementAbility;
	};
private:
	ListReplacementAbility(ListReplacementAbility::Builder* builder) : Ability(builder) {
		this->hooks = builder->_hooks;
		this->count = builder->_count;
		this->selectionList = builder->_selectionList;
		this->targetAbility = builder->_targetAbility;
	}


public:
	const vector<string>& getHooks() const {return this->hooks;}
	const variant<Formula, int>& getCount() const {return this->count;}
	const variant<vector<Ability*>/*, Spell*/> getSelectionList() const {return this->selectionList;}
	const string& getTargetAbility() const {return this->targetAbility;}


	ListReplacementAbility() = default;
	~ListReplacementAbility();
};
