#include "statframe.h"
#include <string>
#include <list>
#include "spell.h"
#include <vector>
#include "shareddefines.h"

class Spell;

class Unit{
private:
    Statframe stats;
    int is_target_fixed;
    static Unit* DeadTarget;
    std::vector< Spell > spells;
    Spell* GetSpellToCast();

public:
    Unit* Target;
    std::string Name;
    Unit();
    //Unit(Stattemplate);
    Unit(std::string);
    void AddSpells( Spell* , int);
    void AddSpell( const Spell& );
    friend std::ostream& operator << (std::ostream &stream, const Unit &unt);
    void ProgressTime(double currenttime);
    std::list< Action > GetActions();
    void SetFixedTarget( Unit* );
    void PickTarget(std::list< Unit* >);
	float MeleeSpellMissChance(Unit* pVictim, WeaponAttackType attType, int skillDiff, Spell const* spell);
}; 