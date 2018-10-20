#include "stattemplate.h"

class Statframe{
private:
public:
    Statframe();
    Statframe(Stattemplate);

	int strength;
	int agility;
	int stamina;
	int intellect;
	int spirit;

	int armor;
	int health;

	int defense;
	int attack_power;
	int attack_power_ranged;
	int spell_power;
	int healing_done;

	/*
		effective resistance rating = Rb + max((Lt - Lc) * 5, 0) - min(P, Rb)

		Rb - target base resistance (as advertised on the character sheet)
		Lt - target level
		Lc - caster level
		P  - caster spell penetration (P is not relevant if Lt > Lc)
	*/
	int fire_resist;
	int frost_resist;
	int arcane_resist;
	int nature_resist;
	int shadow_resist;

	double hit;
	double hit_melee;
	double hit_ranged;
	double crit;
	double crit_melee; // Not sure if actually a thing
	double crit_ranged; // Not sure if actually a thing
};
