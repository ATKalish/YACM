#pragma once
#include <string>
#include <vector>

using namespace std;

class Item{
private:
    string name;
    string description;
    vector<string> abilities;

public:
    Item() = default;
    Item(const string& name, const string& description, const vector<string>& abilities){
        this->name = name;
        this->description = description;
        this->abilities = abilities;
    }

    const string& getName(){return this->name;}
    const string& getDescription(){return this->description;}
    const vector<string>* getAbilities(){return this->abilities;}
}