#pragma once
#include "monster.h"
#include "utils.h"

class TheIceKing : public Monster
{
public:
	TheIceKing();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class KingOfOoo : public Monster
{
public:
	KingOfOoo();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class EarlOfLemongrab : public Monster
{
public:
	EarlOfLemongrab();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class MartinMertens : public Monster
{
public:
	MartinMertens();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class HunsonAbadeer : public Monster
{
public:
	HunsonAbadeer();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class PatienceStPim : public Monster
{
public:
	PatienceStPim();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class UncleGumbald : public Monster
{
public:
	UncleGumbald();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class Orgalorg : public Monster
{
public:
	Orgalorg();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class TheLich : public Monster
{
public:
	TheLich();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};

class GOLB : public Monster
{
public:
	GOLB();
	const char* getName();
	void attack(Creature* enemy);
	Drop getDrop();
};