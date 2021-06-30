#pragma once
#include "Hero.h"
#include "Monster.h"
class GameManager
{
public:
	bool startGame();

private:
	void welcome();
	Hero* chooseOfTheHero();
	void fight(Hero* hero, Monster* monster);
	void herosAttack(Hero* hero, Monster* monster);
	void levelUp(Hero* hero);
};
