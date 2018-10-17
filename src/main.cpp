#include <stdio.h>
#include <iostream>
#include "simulator.h"


using namespace std;

int main(int argc, char** argv){

    Simulator sim (4);

    sim.RunSimulation(30);

    cout << "Success!" << endl;

    return 0;
}