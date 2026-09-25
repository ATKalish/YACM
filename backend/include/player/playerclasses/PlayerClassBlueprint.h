#pragma once

#include <string>
#include <vector>
#include "abilities/Ability.h"
#include "abilities/ModificationAbility.h"
#include "spellcasting/SpellcastingBlueprint.h"


typedef string Formula;
using namespace std;


class PlayerClassBlueprint{
private:
    string name;
    string description;
    string multiClassPrereqs;
    vector<vector<Ability*>> abilityTable;
    int hitDie;
    Formula firstLevelHitPoints;
    Formula higherLevelHitPoints;

    // proficiencies
    ModificationAbility armor;
    ModificationAbility weapons;
    ModificationAbility tools;
    ModificationAbility savingThrows;
    ModificationAbility skills;
    ModificationAbility equipment;

    SpellcastingBlueprint spellCastingBlueprint;

public:
    class Builder{
    private:
        string _name;
        string _description;
        string _multiClassPrereqs;
        vector<vector<Ability*>> _abilityTable;
        int _hitDie;
        Formula _firstLevelHitPoints;
        Formula _higherLevelHitPoints;
        ModificationAbility _armor;
        ModificationAbility _weapons;
        ModificationAbility _tools;
        ModificationAbility _savingThrows;
        ModificationAbility _skills;
        ModificationAbility _equipment;
        SpellcastingBlueprint _spellCastingBlueprint;

    public:
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& descripiton(const string& description){this->_description = description; return *this;}
        Builder& multiClassPrereqs(const string& multiClassPrereqs){this->_multiClassPrereqs = multiClassPrereqs; return *this;}
        Builder& abilityTable(vector<vector<Ability*>> abilityTable){this->_abilityTable = abilityTable; return *this;}
        Builder& hitDie(int hitDie){this->_hitDie = hitDie; return *this;}
        Builder& firstLevelHitPoints(const Formula& firstLevelHitPoints){this->_firstLevelHitPoints = firstLevelHitPoints; return *this;}
        Builder& higherlevelHitPoints(const Formula& higherlevelHitPoints){this->_higherLevelHitPoints = higherlevelHitPoints; return *this;}
        Builder& armor(const ModificationAbility& armor){this->_armor = armor; return *this;}
        Builder& weapons(const ModificationAbility& weapons){this->_weapons = weapons; return *this;}
        Builder& tools(const ModificationAbility& tools){this->_tools = tools; return *this;}
        Builder& savingThrows(const ModificationAbility& savingThrows){this->_savingThrows = savingThrows; return *this;}
        Builder& skills(const ModificationAbility& skills){this->_skills = skills; return *this;}
        Builder& equipment(const ModificationAbility& equipment){this->_equipment = equipment; return *this;}
        Builder& spellcastingBlueprint(const SpellcastingBlueprint& spellcastingBlueprint){this->_spellCastingBlueprint = spellcastingBlueprint; return *this;}
        PlayerClassBlueprint build(){return PlayerClassBlueprint(this);}
        friend class PlayerClassBlueprint;
    };

private:
    PlayerClassBlueprint(PlayerClassBlueprint::Builder* builder){
        this->name = builder->_name;
        this->description = builder->_description;
        this->multiClassPrereqs = builder->_multiClassPrereqs;
        this->abilityTable = builder->_abilityTable;
        this->hitDie = builder->_hitDie;
        this->firstLevelHitPoints = builder->_firstLevelHitPoints;
        this->higherLevelHitPoints = builder->_higherLevelHitPoints;
        this->armor = builder->_armor;
        this->weapons = builder->_weapons;
        this->tools = builder->_tools;
        this->savingThrows = builder->_savingThrows;
        this->skills = builder->_skills;
        this->equipment = builder->_equipment;
        this->spellCastingBlueprint = builder->_spellCastingBlueprint;
    }

public:
    PlayerClassBlueprint() = default;
    ~PlayerClassBlueprint();

    const string& getName(){return this->name;}
    const string& getDescription(){return this->description;}
    const string& getMultiClassPrereqs(){return this->multiClassPrereqs;}
    const vector<vector<Ability*>>& getAbilityTable(){return this->abilityTable;}
    int getHitDie(){return this->hitDie;}
    const Formula& getFirstLevelHitPoints(){return this->firstLevelHitPoints;}
    const Formula& getHigherLevelHitPoints(){return this->higherLevelHitPoints;}
    const ModificationAbility& getArmor(){return this->armor;}
    const ModificationAbility& getWeapons(){return this->weapons;}
    const ModificationAbility& getTools(){return this->tools;}
    const ModificationAbility& getSavingThrows(){return this->savingThrows;}
    const ModificationAbility& getSkills(){return this->skills;}
    const ModificationAbility& getEquipment(){return this->equipment;}
    const SpellcastingBlueprint getSpellCastingBlueprint(){return this->spellCastingBlueprint;}
};