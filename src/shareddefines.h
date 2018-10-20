#pragma once

enum WeaponAttackType
{
	///Main-hand weapon
	BASE_ATTACK = 0,
	///Off-hand weapon
	OFF_ATTACK = 1,
	///Ranged weapon, bow/wand etc.
	RANGED_ATTACK = 2
};  

enum MagicSchool{
    SCHOOL_FIRE = 0
};

enum Conditional{
    COND_GTR = 0,
    COND_LT = 1,
    COND_GT = 2,
    COND_LE = 3,
    COND_GE = 4,
    COND_NE = 5
};