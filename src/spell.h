struct Action;

class Spell{
private:
    double next_availabe_cast;
    double cooldown;
    double damage;
public:
    Spell();
    Action* ToAction();
};