#pragma once
#include "Ability.h"
#include <variant>

class TraitModificationAbility : public Ability {
private:
	vector<string> targetTraits;
	//it can either be a constant value, a value that grows with level, or a formula
	variant<int, vector<int>, string> value;
public:
	class Builder : public Ability::Builder {
	private:
		vector<string> _targetTraits;
		variant<int, vector<int>, string> _value;

	public:
		Builder& targetTraits(const vector<string>& targetTraits) {this->_targetTraits = targetTraits; return *this;}
		Builder& value(const variant<int, vector<int>, string>& value) {this->_value = value; return *this;}
		TraitModificationAbility build() {return TraitModificationAbility(this);}
		friend class TraitModificationAbility;
	};

private:
	TraitModificationAbility(TraitModificationAbility::Builder* builder) : Ability(builder) {
		this->targetTraits = builder->_targetTraits;
		this->value = builder->_value;
	}
	~TraitModificationAbility();
public:
	const vector<string>& getTargetTrait() const {return this->targetTraits;}
	const variant<int, vector<int>, string> getValue() const {return this->value;}
};
