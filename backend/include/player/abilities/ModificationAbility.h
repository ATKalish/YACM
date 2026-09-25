#pragma once

#include "Ability.h"
#include "../spellcasting/Spell.h"
#include "../Item.h"

#include <variant>

class ModificationAbililty : public Ability {
private:
	string targetID;

	variant<vector<Ability*>, vector<Spell>, vector<Item>> selectionList;

	variant<Formula, int, vector<int>> maximumSelectionCount;
	variant<Formula, int, vector<int>> minimumSelectionCount;

	vector<string> hookIDs;

public:
	class Builder : public Ability::Builder {};
	class Decision {};

	ModificationAbililty() = default;
	~ModificationAbililty();
};
