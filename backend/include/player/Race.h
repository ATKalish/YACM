#pragma once
#include "abilities/Ability.h"
#include "abilities/ListSelectionAbility.h"

class Race {
private:
	string name;
	int speed;
	string description;
	ListSelectionAbility languages;
	ListSelectionAbility proficiencies;
	vector<Ability*> abilities;
	~Race();

public:
	const string& getName() const {return this->name;}
	const string& getDescription() const {return this->description;}
	const int getSpeed() const {return this->speed; }
	const vector<Ability*>& getAbilities() const {return this->abilities;};
	const ListSelectionAbility& getLanguages() const {return this->languages;}
	const ListSelectionAbility& getProficiencies() const {return this->proficiencies;}
};
