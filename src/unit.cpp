#include "unit.h"
#include <list>
#include <stdio.h>
#include <iostream>

using namespace std;

Unit* Unit::DeadTarget = new Unit("NoneTarget");

Unit::Unit(){
    Name = "Default Unit";
    Target = Unit::DeadTarget;
}

Unit::Unit(string tarname){
    Name = tarname;
    Target = Unit::DeadTarget;
}

void Unit::SetFixedTarget(Unit* tar){
    is_target_fixed = 1;
    Target = tar;
}

void Unit::PickTarget(list< Unit* > units){
    if(!is_target_fixed){
        
        //do nothing for now    
    }
}

ostream& operator << (ostream &stream, const Unit &unt){
    stream << unt.Name;
}