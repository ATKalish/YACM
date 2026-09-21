#pragma once
#include "Ability.h"
#include <variant>

class ListSelectionAbility : public Ability {
private:
	vector<string> hooks;
	bool listIsInternal; //not 100% sure what the intention for this is
	variant<string, int> count;
	variant<vector<Ability*> /*, vector<Spell>*/> selectionList;

public:
	class ListSelectionBuilder : public Builder {
		vector<string> _hooks;
		bool _listIsInternal;
		variant<string, int> _count;
		variant<vector<Ability*>/*, *Spells*/> _selectionList;


	public:
		ListSelectionBuilder& hooks(const vector<string>& hooks) {this->_hooks = hooks; return *this;}
		ListSelectionBuilder& isInternal(bool isInternal) {this->_listIsInternal = isInternal; return *this;}
		ListSelectionBuilder& count(const variant<string, int>& _count) {this->_count = _count; return *this;}
		ListSelectionBuilder& selectionList(const variant<vector<Ability*>/*, *Spells*/>& _selectionList) {this->_selectionList = _selectionList; return *this;}
		ListSelectionAbility build() {return ListSelectionAbility(this);}

		friend class ListSelectionAbility;
	};

private:
	ListSelectionAbility(ListSelectionBuilder* builder) : Ability(builder) {
		this->hooks = builder->_hooks;
		this->listIsInternal = builder->_listIsInternal;
		this->count = builder->_count;
		this->selectionList = builder->_selectionList;
	}

	// TODO: this is too complicated to define in the header-- but selection_list needs to be deallocated
	~ListSelectionAbility();

public:
	const vector<string>& getHooks() const {return this->hooks;}
	bool isInternalList() const {return this->listIsInternal;}
	const variant<string, int>& getCount() const {return this->count;}
	const variant<vector<Ability*> /*, vector<Spell>*/>& getList() const {return this->selectionList;}

};
