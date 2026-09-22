#pragma once
#include "Ability.h"

class OverrideAbility : public Ability {
private:
	Ability* target;
	Ability* newAbility;

public:
public:
	const Ability* getTarget() const {return this->target;}
	const Ability* getNewAbility() const {return this->target;}
};
