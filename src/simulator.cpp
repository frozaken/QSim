#include <iostream>
#include <sys/types.h>
#include "simulator.h"
#include <list>
using namespace std;

Simulator::Simulator(uint _steps_pr_second){
    std::list< Unit* > units ();
    steps_pr_second = _steps_pr_second;
}

void Simulator::RunSimulation(uint steps){
    cout << "Running for " << steps << " steps with " << units.size() << " units." << endl;
    for(uint step = 0; step < steps; ++ step){
        for(std::list< Unit* >::iterator it = units.begin(); it != units.end(); ++it){
            //cout << "Simulating unit '" << **it << "' with target: '" << *((*it)->Target) << "'" << endl;
            //(*it)->PickTarget(units); 
            (*it)->GetAction();
        }

        //cout << "Step: " << step + 1 << endl;
    }
}

void Simulator::AddUnit(Unit* unit){
    units.push_back(unit);
}