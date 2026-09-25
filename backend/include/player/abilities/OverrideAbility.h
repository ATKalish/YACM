#pragma once
#include "Ability.h"

class OverrideAbility : public Ability {
private:
	Ability* target;
	Ability* newAbility;

public:
	class Builder: public Ability::Builder {
		Ability* _target;
		Ability* _newAbility;

	public:
		Builder& target(Ability* target) {this->_target = target; return *this;}
		Builder& newAbility(Ability* newAbility) {this->_newAbility = newAbility; return *this;}
		OverrideAbility build() {return OverrideAbility(this);}

		friend class OverrideAbility;
	};
private:
	OverrideAbility(OverrideAbility::Builder* builder) : Ability(builder) {
		this->target = builder->_target;
		this->newAbility = builder->_newAbility;
	}


public:
	const Ability* getTarget() const {return this->target;}
	const Ability* getNewAbility() const {return this->target;}
	~OverrideAbility();
};
