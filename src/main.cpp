#include <stdio.h>
#include <iostream>
#include "simulator.h"

using namespace std;

int main(int argc, char** argv){

    Unit player;
    Unit enemy;
    Unit* DeadTarget = new Unit();

    //Unit::DeadTarget = DeadTarget;


    player.SetFixedTarget(&enemy);
    player.Name = "TestPlayer";

    Simulator sim (4);

    cout << "Testing name " << player << endl;

    sim.AddUnit(&player);
    sim.AddUnit(&enemy);

    sim.RunSimulation(30);

    cout << "Success!" << endl;

    return 0;
}