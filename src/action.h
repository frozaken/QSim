#include <list>
#include <string>

class Unit;

struct Action{
public:
    
    Action();
    
    std::string Name;

    Unit* Target;
    Unit* Caster;

    int Damage;
};