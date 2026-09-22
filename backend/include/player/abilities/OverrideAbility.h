#pragma once
#include "Ability.h"

class OverrideAbility : public Ability {
private:
	Ability* target;
	Ability* newAbility;

public:
	class OverrideBuilder : public Builder {
		Ability* _target;
		Ability* _newAbility;

	public:
		OverrideBuilder& target(Ability* target) {this->_target = target; return *this;}
		OverrideBuilder& newAbility(Ability* newAbility) {this->_newAbility = newAbility; return *this;}
		OverrideAbility build() {return OverrideAbility(this);}

		friend class OverrideAbility;
	};
private:
	OverrideAbility(OverrideBuilder* builder) : Ability(builder) {
		this->target = builder->_target;
		this->newAbility = builder->_newAbility;
	}

	~OverrideAbility();

public:
	const Ability* getTarget() const {return this->target;}
	const Ability* getNewAbility() const {return this->target;}
};
