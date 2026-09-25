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
	class Builder : public Ability::Builder {};
	class Decision {};

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
