#include <stdio.h>
#include <iostream>
#include "simulator.h"
#include "shareddefines.h"

using namespace std;

int main(int argc, char** argv){

    Unit player;
    Unit enemy;
    Unit* DeadTarget = new Unit();

    Spell testspell("fireball", 3, 200, SCHOOL_FIRE );
    Spell testspell2("frostblast", 2, 300, SCHOOL_FIRE);

    player.SetFixedTarget(&enemy);
    player.Name = "TestPlayer";
    player.AddSpells(new Spell[2]{testspell,testspell2}, 2);

    Simulator sim (1);

    sim.AddUnit(&player);
    sim.AddUnit(&enemy);

    sim.RunSimulation(10);

    cout << "Success!" << endl;

    return 0;
}