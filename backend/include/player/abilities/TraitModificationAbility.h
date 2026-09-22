#pragma once
#include "Ability.h"
#include <variant>
class TraitModificationAbility : public Ability {
private:
	vector<string> targetTraits;
	//it can either be a constant value, a value that grows with level, or a formula
	variant<int, vector<int>, string> value;
	~TraitModificationAbility();
public:
	const vector<string>& getTargetTrait() const {return this->targetTraits;}
	const variant<int, vector<int>, string> getValue() const {return this->value;}
};
