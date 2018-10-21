#include "spell.h"
#include "action.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Unit;
struct Action;

Spell::Spell(){
    
}

void Spell::Use(){
    this->time_to_next = cooldown;
}

void Spell::RegisterTimeDelta(double delta){
    this->time_to_next = max(0.0, this->time_to_next - delta);
}

int Spell::IsCastable(){
    return this->time_to_next <= 0.0;
}

Action* Spell::ToAction( Unit& caster, Unit& target){
    Action* retact = new Action();

    retact->Target = &target;
    retact->Caster = &caster;

    retact->Damage = this->damage;

    retact->Name = this->Name;

    return retact;
}


Spell::Spell(const string& name, double cd, double dmg, MagicSchool _school){
    this->Name = name;
    this->damage = dmg;
    this->cooldown = cd;
    this->school = _school;
}
