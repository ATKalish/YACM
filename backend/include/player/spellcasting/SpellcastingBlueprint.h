#pragma once
#include <string>
#include <vector>
#include "Spell.h"

using namespace std;
typedef string Formula;

class SpellcastingBlueprint{
private:
    string focus;
    vector<Spell> spellList;
    bool ritual;
    string spellAbilityInfo;
    Formula spellSaveFormula;
    Formula spellAttackFormula;
    string spellPreparation;

    // may only be applicable for class spellcasting
    string spellsKnown;
    int spellSlots[20][10]; // 20 levels, 10 spell level (including cantrips)

public:
    class Builder {
    private:
        string _focus;
        vector<Spell> _spellList;
        bool _ritual;
        string _spellAbilityInfo;
        Formula _spellAttackFormula;
        Formula _spellSaveFormula;
        string _spellPreparation;

    public:
        Builder() = default;

        Builder& focus(const string& focus){this->_focus = focus;}
        Builder& spellList(const vector<Spell> spellList){this->_spellList = spellList;}
        Builder& ritual(bool ritual){this->_ritual = ritual;}
        Builder& spellcastingAbilty(const string& spellAbiltyInfo){this->_spellAbilityInfo = spellAbiltyInfo;}
        Builder& spellAttackFormula(const Formula& spellAttackFormula){this->_spellAttackFormula = spellAttackFormula;}
        Builder& spellSaveFormula(const Formula& spellSaveFormula){this->_spellSaveFormula = spellSaveFormula;}
        Builder& spellPreparation(const string& spellPreparation){this->_spellPreparation = spellPreparation;}
        SpellcastingBlueprint build(){return SpellcastingBlueprint(this);}
        friend class SpellcastingBlueprint;
    };

    SpellcastingBlueprint(SpellcastingBlueprint::Builder* builder){
        this->focus = builder->_focus;
        this->spellList = builder->_spellList;
        this->ritual = builder->_ritual;
        this->spellAbilityInfo = builder->_spellAbilityInfo;
        this->spellAttackFormula = builder->_spellAttackFormula;
        this->spellSaveFormula = builder->_spellAttackFormula;
        this->spellPreparation = builder->_spellPreparation;
    }

    const string& getFocus(){return this->focus;}
    const vector<Spell>& getSpellList(){return this->spellList;};
    bool isRitual(){return this->ritual;}
    const string& getSpellAbility(){return this->spellAbilityInfo;}
    const string& getSpellPreparation(){return this->spellPreparation;}
};