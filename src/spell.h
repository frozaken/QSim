#include <string>

struct Action;
class Unit;

class Spell{
private:
    double next_availabe_cast;
    double cooldown;
    double damage;
public:
    std::string Name;
    Spell();
    Spell(std::string, double, double);
    static Spell SpellFromFile(std::string);
    Action* ToAction(Unit*, Unit*);
};