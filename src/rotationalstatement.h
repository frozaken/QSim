#include "shareddefines.h"
#include "spell.h"

class RotationalStatement{
private:
    Spell resultingspell;


public:
    RotationalStatement(Spell);
    void AddCooldownConditional(int refspell, int cd, Conditional cond);
    int EvaluateCondition();
};