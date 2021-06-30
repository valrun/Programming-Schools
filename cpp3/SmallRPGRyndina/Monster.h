#pragma once
#include "Creature.h"
#include "Utils.h"

class Monster : public Creature
{
public:
	Monster(int health) : Creature(health) {}
	virtual Drop getDrop() = 0;
};