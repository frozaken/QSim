#include <sys/types.h>


class Simulator{
    uint steps_pr_second;
public:
    Simulator(uint);
    void RunSimulation(uint);
};