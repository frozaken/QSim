#include "statframe.h"
#include <string>
#include "action.h"
#include <list>
#include "spell.h"
#include <vector>

class Spell;

enum WeaponAttackType
{
	///Main-hand weapon
	BASE_ATTACK = 0,
	///Off-hand weapon
	OFF_ATTACK = 1,
	///Ranged weapon, bow/wand etc.
	RANGED_ATTACK = 2
};

class Unit{
private:
    Statframe stats;
    int is_target_fixed;
    static Unit* DeadTarget;
    std::vector< Spell > spells;
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
    Action* GetAction();
    void SetFixedTarget( Unit* );
    void PickTarget(std::list< Unit* >);
	float MeleeSpellMissChance(Unit* pVictim, WeaponAttackType attType, int skillDiff, Spell const* spell);
}; 