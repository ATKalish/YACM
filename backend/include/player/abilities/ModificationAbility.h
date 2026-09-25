#pragma once

#include "Ability.h"
#include "../spellcasting/Spell.h"
#include "../Item.h"

#include <variant>


typedef variant<vector<Ability*>, vector<Spell>, vector<Item>> SelectionList;
typedef variant<Formula, int, vector<int>> SelectionCount;

class ModificationAbility: public Ability {
private:
	string targetID;
	vector<string> hookIDs;

	SelectionList selectionList;
	SelectionCount minCount;
	SelectionCount maxCount;


public:
	class Builder : public Ability::Builder {
	private:
		string _targetID;
		vector<string> _hookIDs;

		SelectionList _selectionList;
		SelectionCount _minCount;
		SelectionCount _maxCount;

	public:
		Builder() = default;
		Builder& targetID(const string& targetID) {this->_targetID = targetID; return *this;}
		Builder& hookIDs(const vector<string>& hookIDs) {this->_hookIDs = hookIDs; return *this;}
		Builder& selectionList(const SelectionList& selectionList) {this->_selectionList = selectionList; return *this;}
		Builder& maxCount(const SelectionCount& maxCount) {this->_maxCount = maxCount; return *this;}
		Builder& minCount(const SelectionCount& minCount) {this->_minCount = minCount; return *this;}
		ModificationAbility build() {return ModificationAbility(this);}

		friend class ModificationAbility;
	};
	ModificationAbility() = default;
	~ModificationAbility();

	const string& getTargetID() const {return this->targetID;}
	const vector<string>& getHookIDs() const {return this->hookIDs;}
	const SelectionList& getSelectionList() const {return this->selectionList;}
	const SelectionCount& getMaxCount() const {return this->maxCount;}
	const SelectionCount& getMinCount() const {return this->minCount;}


protected:
	ModificationAbility(ModificationAbility::Builder* builder) {
		this->targetID = builder->_targetID;
		this->hookIDs = builder->_hookIDs;
		this->selectionList = builder->_selectionList;
		this->maxCount = builder->_maxCount;
		this->minCount = builder->_minCount;
	}
};
