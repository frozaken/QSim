#include <iostream>
#include <sys/types.h>
#include "simulator.h"
using namespace std;

Simulator::Simulator(uint _steps_pr_second){
    std::list< Unit* > units ();
    steps_pr_second = _steps_pr_second;
}

void Simulator::RunSimulation(uint steps){
    cout << "Running for " << steps << " steps with " << units.size() << " units." << endl;
}

void Simulator::AddUnit(Unit* unit){
    units.push_back(unit);
}