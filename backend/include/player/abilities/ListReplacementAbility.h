#pragma once
#include "Ability.h"
#include <variant>
class ListReplacementAbility : public Ability {
private:
	vector<string> hooks;
	variant<string, int> count;
	variant<vector<Ability*>/*, Spell*/> selectionList;
	string targetAbility; //should this be a reference? dangerous with various containers
};
