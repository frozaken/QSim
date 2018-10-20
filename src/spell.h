#include <string>
#include "shareddefines.h"
struct Action;
class Unit;

class Spell{
private:
    double time_to_next;
    double cooldown;
    double damage;
    int school; // MagicSchool
public:
    std::string Name;
    Spell();
    Spell(std::string name, double cooldown, double damage, MagicSchool);
    static Spell SpellFromFile(std::string);
    Action* ToAction(Unit*, Unit*);
    void Use();
    void RegisterTimeDelta(double delta);
    int IsCastable();
};