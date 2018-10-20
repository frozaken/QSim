#include <list>
#include <string>
#include "rotationalstatement.h"

class Spell;

class Rotation{
private:
    std::list<Spell> spells;
    std::list<RotationalStatement> rotation;
public:
    Rotation(std::list<Spell> availablespells);
    void GenerateStatementsFromString(std::string script);
};