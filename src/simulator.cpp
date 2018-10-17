#include "simulator.h"
#include <iostream>
#include <sys/types.h>

using namespace std;

Simulator::Simulator(uint _steps_pr_second){
    steps_pr_second = _steps_pr_second;
}

void Simulator::RunSimulation(uint steps){
    cout << "Running for " << steps << " steps" << endl;
}