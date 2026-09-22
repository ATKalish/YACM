#pragma once
#include <string>
#include <vector>

using namespace std;

class Spell{
private:
    string name;
    string source;
    string school;
    bool ritual;
    string castingTime;
    string range;
    string components;
    string duration;
    string description;
    string higherLevel;
    vector<string> tags;

public:
    class Builder{
    private:
        string _name;
        string _source;
        string _school;
        bool _ritual;
        string _castingTime;
        string _range;
        string _components;
        string _duration;
        string _description;
        string _higherLevel;
        vector<string> tags;

        //TODO complete builder:wq
    };

};