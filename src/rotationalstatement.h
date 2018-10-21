#include "shareddefines.h"
#include "spell.h"

class RotationalStatement{
private:
    Spell resultingspell;


public:
    RotationalStatement(Spell);
    void AddCooldownConditional(const int& refspell, const int& cd, const Conditional& cond);
    int EvaluateCondition();
};