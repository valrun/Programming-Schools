#pragma once
#include "Hero.h"

class JakeTheDog : public Hero
{
public:
	JakeTheDog();
	const char* getName();
	void attack(Creature* enemy);
	void specialAttack(Creature* enemy);
};

class FinnTheHuman : public Hero
{
public:
	FinnTheHuman();
	const char* getName();
	void attack(Creature* enemy);
	void specialAttack(Creature* enemy);
};

class PrincessBubblegum : public Hero
{
public:
	PrincessBubblegum();
	const char* getName();
	void attack(Creature* enemy);
	void specialAttack(Creature* enemy);
};