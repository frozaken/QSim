class Unit;
struct Aura;
class Spell;

struct Action{
public:
    
    Action();
    Action(Spell);

    Unit* Target;
    Unit* Caster;

    int Damage;
    Aura** auras;
    int AuraId;
};