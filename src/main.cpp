#include <stdio.h>
#include <iostream>
#include "simulator.h"

using namespace std;

int main(int argc, char** argv){

    Unit player;

    Simulator sim (4);

    sim.AddUnit(&player);

    sim.RunSimulation(30);

    cout << "Success!" << endl;

    return 0;
}