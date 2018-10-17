#include "statframe.h"
#include <string>
#include "action.h"
#include <list>
#include "spell.h"

using namespace std;

class Spell;

class Unit{
private:
    Statframe stats;
    int is_target_fixed;
    static Unit* DeadTarget;
    Spell* spells;
public:
    Unit* Target;
    string Name;
    Unit();
    //Unit(Stattemplate);
    Unit(string);
    friend ostream& operator << (ostream &stream, const Unit &unt);
    void ProgressTime(double currenttime);
    Action* GetAction();
    void SetFixedTarget( Unit* );
    void PickTarget(list< Unit* >);
}; 