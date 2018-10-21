#include <list>
#include <string>

class Unit;
struct Aura;
class Spell;

struct Action{
public:
    
    Action();
    
    std::string Name;

    Unit* Target;
    Unit* Caster;

    int Damage;
};