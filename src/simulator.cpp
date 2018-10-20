#include <iostream>
#include <sys/types.h>
#include "simulator.h"
#include <list>
#include "action.h"



using namespace std;


struct Action;

Simulator::Simulator(uint _steps_pr_second){
    list< Unit* > units;
    steps_pr_second = _steps_pr_second;
}

void Simulator::RunSimulation(uint steps){
    cout << "Running for " << steps << " steps with " << units.size() << " units." << endl;
    for(uint step = 0; step < steps; ++ step){

        list< Action* > stepactions;        

        for(std::list< Unit* >::iterator it = units.begin(); it != units.end(); ++it){
            //cout << "Simulating unit '" << **it << "' with target: '" << *((*it)->Target) << "'" << endl;
            //(*it)->PickTarget(units); 
            list< Action > unitactions = (*it)->GetActions();

            for(std::list< Action >::iterator ita = unitactions.begin(); ita != unitactions.end(); ++ita){
                cout << "Unit " << **it << " is now casting " << ita->Name << " at " << *ita->Target << endl;
            }
    
        }
        for(std::list< Unit* >::iterator it = units.begin(); it != units.end(); ++it){
            (*it)->ProgressTime(1/this->steps_pr_second);
        }

        cout << "Step: " << step + 1 << endl;
    }
}

void Simulator::AddUnit(Unit* unit){
    units.push_back(unit);
}