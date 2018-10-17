#include "spell.h"
#include "action.h"
#include <string>


using namespace std;

class Unit;
struct Action;

Spell::Spell(){
    
}

Action* Spell::ToAction( Unit* caster, Unit* target){
    Action* retact = new Action();

    retact->Target = target;
    retact->Caster = caster;

    retact->Damage = this->damage;

    return retact;
}

Spell::Spell(string name, double cd, double dmg){
    this->Name = name;
    this->damage = dmg;
    this->cooldown = cd;
}