#include "unit.h"
#include <list>
#include <stdio.h>
#include <iostream>

using namespace std;

Unit* Unit::DeadTarget = new Unit("NoneTarget");


void Unit::ProgressTime(double currenttime){

}




Unit::Unit(){
    Name = "Default Unit";
    Target = Unit::DeadTarget;
}

Unit::Unit(string tarname){
    Name = tarname;
    Target = Unit::DeadTarget;
}

Action* Unit::GetAction(){
    for(int i = 0; i < this->spells.size(); ++i){
        cout << this->spells[i].Name << endl;
    }
}

void Unit::SetFixedTarget(Unit* tar){
    is_target_fixed = 1;
    Target = tar;
}

void Unit::AddSpells(Spell* _spells, int count){
    for (int i = 0; i < count; ++i){
        this->AddSpell(_spells[i]);
    }
}

void Unit::AddSpell(const Spell& _spell){
    this->spells.push_back(_spell);
}

void Unit::PickTarget(list< Unit* > units){
    if(!is_target_fixed){        
        //do nothing for now    
    }
}

ostream& operator << (ostream &stream, const Unit &unt){
    stream << unt.Name;
}