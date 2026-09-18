#pragma once
#include <string>
#include <vector>

using namespace std;

class Ability{
public:
    class Scaler{
    private:
        string name;
        vector<string> scaling;
    public:
        Scaler() = default;
        Scaler(const string& name, const vector<string>& scaling){
            this->name = name;
            this->scaling = scaling;
        }
    };
    class ChargeType{
    private:
        int count;
        vector<string> rechargeType;
        string rechargeVal;
    public:
        ChargeType() = default;
        ChargeType(int count, const vector<string>& rechargeType, const string& rechargeVal){
            this->count = count;
            this->rechargeType = rechargeType;
            this->rechargeVal = rechargeVal;
        }
    };
private:
    string name;
    string text;
    string prereq;
    bool optional;
    bool hidden;
    
    Scaler scaler;
    
    ChargeType chargeType;
    vector<string> tags;
    vector<Ability*> subAbilities;
    string origin;

public:
    struct Builder{
        string _name;
        string _text;
        string _prereq;
        bool _optional;
        bool _hidden;
        Scaler _scaler;
        ChargeType _chargeType;
        vector<string> _tags;
        vector<Ability*> _subAbilities;
        string _origin;
        Builder() = default;

        Builder& name(const string& name){this->_name = name; return *this;}
        Builder& text(const string& text){this->_text = text; return *this;}
        Builder& prereq(const string& prereq){this->_prereq = prereq; return *this;}
        Builder& optional(bool optional){this->_optional = optional; return *this;}
        Builder& hidden(bool hidden){this->_hidden = hidden; return *this;}
        Builder& scaler(const Scaler& scaler){this->_scaler = scaler; return *this;}
        Builder& charges(const ChargeType& chargeType){this->_chargeType = chargeType; return *this;}
        Builder& tags(const vector<string>& tags){this->_tags = tags; return *this;}
        Builder& subAbilities(const vector<Ability*>& subAbilities){this->_subAbilities = subAbilities; return *this;}
        Builder& origin(const string& origin){this->_origin = origin; return *this;}
        Ability build(){return Ability(this);}
    };

    Ability(Builder* builder){
        this->name = builder->_name;
        this->text = builder->_text;
        this->prereq = builder->_prereq;
        this->optional = builder->_optional;
        this->hidden = builder->_hidden;
        this->scaler = builder->_scaler;
        this->chargeType = builder->_chargeType;
        this->tags = builder->_tags;
        this->subAbilities = builder->_subAbilities;
        this->origin = builder->_origin;
    }

    ~Ability(){for(int i = 0; i < this->subAbilities.size(); ++i) free(subAbilities[i]);}

    const string& getName(){return this->name;}
    const string& getText(){return this->text;}
    const string& getPrereq(){return this->prereq;}
    bool isOptional(){return this->optional;}
    bool isHidden(){return this->hidden;}
    const Scaler& getScaler(){return this->scaler;}
    const ChargeType& getChargeType(){return this->chargeType;}
    const vector<string>& getTags(){return this->tags;}
    const vector<Ability*>& getSubAbilities(){return this->subAbilities;}
    const string& getOrigin(){return this->origin;}
};