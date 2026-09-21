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

		friend class ListSelectionAbility;
	};

private:
	ListSelectionAbility(ListBuilder* builder) : Ability(builder) {
		this->hooks = builder->_hooks;
		this->listIsInternal = builder->_listIsInternal;
		this->count = builder->_count;
		this->selection_list = builder->_selection_list;
	}

	// TODO: this is too complicated to define in the header-- but selection_list needs to be deallocated
	~ListSelectionAbility();

public:
	const vector<string>& getHooks() const {return this->hooks;}
	bool isInternalList() const {return this->listIsInternal;}
	const variant<string, int>& getCount() {return this->count;}
	const variant<vector<Ability*> /*, vector<Spell>*/>& getList() {return this->selection_list;}

};
