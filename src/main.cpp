#include <stdio.h>
#include <iostream>
#include "simulator.h"

using namespace std;

int main(int argc, char** argv){

    Unit player;
    Unit enemy;
    Unit* DeadTarget = new Unit();

    Spell testspell("fireball", 1, 200);


    player.SetFixedTarget(&enemy);
    player.Name = "TestPlayer";
    player.AddSpells(new Spell[1]{testspell}, 1);

    Simulator sim (4);

    sim.AddUnit(&player);
    sim.AddUnit(&enemy);

    sim.RunSimulation(30);

    cout << "Success!" << endl;

    return 0;
}