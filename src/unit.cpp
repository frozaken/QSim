#include "unit.h"
#include <list>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "action.h"

using namespace std;

Unit* Unit::DeadTarget = new Unit("NoneTarget");


void Unit::ProgressTime(double delta){
	for(std::vector<Spell>::iterator it = spells.begin(); it != spells.end(); ++it){
		it->RegisterTimeDelta(delta);
	}
}


Unit::Unit(){
    Name = "Default Unit";
    Target = Unit::DeadTarget;
	Statframe* stats = new Statframe();
}

Unit::Unit(string tarname){
    Name = tarname;
    Target = Unit::DeadTarget;
}

Spell* Unit::GetSpellToCast(){
	for (std::vector< Spell >::iterator it = spells.begin(); it != spells.end(); ++it){
		if(it->IsCastable()){
			return &(*it);
		}
	}

	return nullptr;
}

list< Action > Unit::GetActions(){

	list< Action > toret;

	Spell* tocast = this->GetSpellToCast();

	if(tocast != nullptr){
		tocast->Use();
		toret.push_back(*tocast->ToAction(this,this->Target));
	}

	return toret;
}

void Unit::SetFixedTarget(Unit* tar){
    is_target_fixed = 1;
    Target = tar;
}

void Unit::AddSpells(Spell* _spells, int count){
    for (int i = 0; i < count; ++i){
        this->AddSpell(_spells[i]);
    }
}

void Unit::AddSpell(const Spell& _spell){
    this->spells.push_back(_spell);
}

void Unit::PickTarget(list< Unit* > units){
    if(!is_target_fixed){        
        //do nothing for now    
    }
}

ostream& operator << (ostream &stream, const Unit &unt){
    stream << unt.Name;
	return stream;
}

/*
	From MaNGOS:
	pVictim = The victim of the spell
	attType = Main hand, off hand or ranged
	skillDiff = attacker weapon skill - pVictim's defensive skill value
	Spell = the spell to check
*/
float Unit::MeleeSpellMissChance(Unit* pVictim, WeaponAttackType attType, int skillDiff, Spell const* spell)
{
	// Calculate hit chance (more correct for chance mod)
	float hitChance = 0.0f;

	if (skillDiff < -10)
	{
		hitChance = 93.0f + (skillDiff + 10) * 0.4f; // 7% base chance to miss for big skill diff (%6 in 3.x)
	}
	else
	{
		hitChance = 95.0f + skillDiff * 0.1f;
	}

	// Hit chance depends from victim auras -- NYI
	/*if (attType == RANGED_ATTACK)
	{
		hitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
	}
	else
	{
		hitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);
	}*/

	// Spellmod from SPELLMOD_RESIST_MISS_CHANCE --- NYI!
	/*if (Player* modOwner = GetSpellModOwner())
	{
		modOwner->ApplySpellMod(spell->Id, SPELLMOD_RESIST_MISS_CHANCE, hitChance);
	}*/

	// Miss = 100 - hit
	float missChance = 100.0f - hitChance;

	// Bonuses from attacker aura and ratings
	if (attType == WeaponAttackType::RANGED_ATTACK)
	{
		missChance -= stats.hit_ranged;
	}
	else
	{
		missChance -= stats.hit_melee;
	}

	// Limit miss chance from 0 to 60%
	if (missChance < 0.0f)
	{
		return 0.0f;
	}
	if (missChance > 60.0f)
	{
		return 60.0f;
	}
	return missChance;
}
