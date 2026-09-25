#pragma once
#include "Ability.h"
#include <variant>

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool listIsInternal; //not 100% sure what the intention for this is
	variant<Formula, int> count;
	variant<vector<Ability*> /*, vector<Spell>*/> selectionList;

public:
	class Builder : public Ability::Builder {
		vector<string> _hooks;
		bool _listIsInternal;
		variant<Formula, int> _count;
		variant<vector<Ability*>/*, *Spells*/> _selectionList;


	public:
		Builder& hooks(const vector<string>& hooks) {this->_hooks = hooks; return *this;}
		Builder& isInternal(bool isInternal) {this->_listIsInternal = isInternal; return *this;}
		Builder& count(const variant<Formula, int>& _count) {this->_count = _count; return *this;}
		Builder& selectionList(const variant<vector<Ability*>/*, *Spells*/>& _selectionList) {this->_selectionList = _selectionList; return *this;}
		ListSelectionAbility build() {return ListSelectionAbility(this);}

		friend class ListSelectionAbility;
	};
	~ListSelectionAbility();

private:
	ListSelectionAbility(ListSelectionAbility::Builder* builder) : Ability(builder) {
		this->hooks = builder->_hooks;
		this->listIsInternal = builder->_listIsInternal;
		this->count = builder->_count;
		this->selectionList = builder->_selectionList;
	}

	// TODO: this is too complicated to define in the header-- but selection_list needs to be deallocated

public:
	const vector<string>& getHooks() const {return this->hooks;}
	bool isInternalList() const {return this->listIsInternal;}
	const variant<Formula, int>& getCount() const {return this->count;}
	const variant<vector<Ability*> /*, vector<Spell>*/>& getList() const {return this->selectionList;}
};
