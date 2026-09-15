#pragma ONCE
#include <string>
#include <vector>

using namespace std;

class Ability{
private:
    string name;
    string text;
    string prereq;
    bool optional;
    bool hidden;
    class Scaler{
        string name;
        vector<string> scaling;
    }
    class Charges{
        int count;
        vector<string> rechargeType;
        string rechargeVal;
    }
    vector<string> tags;
    vector<Abilities*> subAbilities;
    string origin;
}