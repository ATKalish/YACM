#pragma once

#include <string>
#include <vector>
#include "abilities/ModificationAbility.h"
#include "Item.h"

using namespace std;

class Background{
private:
    string name;
    string description;
    ModificationAbility skillProfiencies;
    ModificationAbility toolProficiencies;
    ModificationAbility languages;
    vector<Item> equipment;
    vector<Ability*> features;
    string suggestedCharacteristics;

public:
    class Builder{
    private:
        string _name;
        string _description;
        ModificationAbility _skillProfiencies;
        ModificationAbility _toolProficiencies;
        ModificationAbility _languages;
        vector<Item> _equipment;
        vector<Ability*> _features;
        string _suggestedCharacteristics;

    public:
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& description(const string& description){this->_description = description; return *this;}
        Builder& skillProfiencies(const ModificationAbility& skillProfiencies){this->_skillProfiencies = skillProfiencies; return *this;}
        Builder& toolProficiencies(const ModificationAbility& toolProficiencies){this->_toolProficiencies = toolProficiencies; return *this;}
        Builder& languages(const ModificationAbility& languages){this->_languages = languages; return *this;}
        Builder& equipment(const vector<Item> equipment){this->_equipment = equipment; return *this;}
        Builder& features(const vector<Ability*> features){this->_features = features; return *this;}
        Builder& suggestedCharacteristics(const string& suggestedCharacteristics){this->_suggestedCharacteristics = suggestedCharacteristics; return *this;}
        Background build(){return Background(this);}
        friend class Background;
    };

private:
    Background(Background::Builder* builder){
        this->name = builder->_name;
        this->description = builder->_description;
        this->skillProfiencies = builder->_skillProfiencies;
        this->toolProficiencies = builder->_toolProficiencies;
        this->languages = builder->_languages;
        this->equipment = builder->_equipment;
        this->features = builder->_features;
        this->suggestedCharacteristics = builder->_suggestedCharacteristics;
    }

public:
    Background() = default;
    ~Background();

    const string& getname(){return this->name;}
    const string& getDescription(){return this->description;}
    const ModificationAbility& getSkillProficiencies(){return this->skillProfiencies;}
    const ModificationAbility& getToolProficiencies(){return this->toolProficiencies;}
    const ModificationAbility& getLanguages(){return this->languages;}
    const vector<Item>& getEquipment(){return this->equipment;}
    const string getSuggestedCharacteristics(){return this->suggestedCharacteristics;}
};
