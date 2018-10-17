#include <sys/types.h>
#include "unit.h"
#include <list>

class Simulator{
    uint steps_pr_second;
    std::list< Unit* > units;
public:
    Simulator(uint);
    void RunSimulation(uint);
    void AddUnit( Unit* );
};