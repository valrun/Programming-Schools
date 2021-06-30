#include "Heros.h"
#include "Utils.h"

JakeTheDog::JakeTheDog() : Hero(100) {
	intelligence = 10;
	strength = 20;
	agility = 10;
}

const char* JakeTheDog::getName() {
	return "Jake The Dog";
}

void JakeTheDog::attack(Creature* enemy) {
	if (enemy->isAlive()) {
		int damage = strength + 0.1 * (intelligence + agility) + RPGUtils::getRandom(-5, 5);
		damage += damage * sqrt(getLevel());
		printf("->Jake is beatting the enemy:\n");
		printf("      %s's health -%d\n", enemy->getName(), damage);
		enemy->subtractHealth(damage);
	}
}

void JakeTheDog::specialAttack(Creature* enemy) {
	if (enemy->isAlive()) {
		int damage = 7 * strength + intelligence + agility + RPGUtils::getRandom(-10, 10);
		damage += damage * sqrt(getLevel());
		printf("->Jake is growing a height and weight and beatting the enemy:\n");
		printf("      %s's health -%d\n", enemy->getName(), damage);
		enemy->subtractHealth(damage);
	}
}

//=============================================

FinnTheHuman::FinnTheHuman() : Hero(80) {
	intelligence = 10;
	strength = 15;
	agility = 20;
}

const char* FinnTheHuman::getName() {
	return "Finn The Human";
}

void FinnTheHuman::attack(Creature* enemy) {
	if (enemy->isAlive()) {
		int damage = strength + 0.1 * (intelligence + agility) + RPGUtils::getRandom(-5, 5);
		damage += damage * sqrt(getLevel());
		printf("Finn is attacking the enemy with his sword:\n");
		printf("      %s's health -%d\n", enemy->getName(), damage);
		enemy->subtractHealth(damage);
	}
}

void FinnTheHuman::specialAttack(Creature* enemy) {
	if (enemy->isAlive()) {
		int damage = 3 * strength + intelligence + agility + RPGUtils::getRandom(-10, 10);
		damage += damage * sqrt(getLevel());
		printf("Finn is using the Grass Sword:\n");
		printf("      %s's health -%d\n", enemy->getName(), damage);
		enemy->subtractHealth(damage);
	}
}

//=============================================
PrincessBubblegum::PrincessBubblegum() : Hero(80) {
	intelligence = 20;
	strength = 15;
	agility = 10;
}
const char* PrincessBubblegum::getName() {
	return "Princess Bubblegum";
}

void PrincessBubblegum::attack(Creature* enemy) {
	if (enemy->isAlive()) {
		int damage = strength + 0.1 * (intelligence + agility) + RPGUtils::getRandom(-5, 5);
		damage += damage * sqrt(getLevel());
		printf("Bubblegum is using chemical weapon:\n");
		printf("      %s's health -%d\n", enemy->getName(), damage);
		enemy->subtractHealth(damage);
	}
}

void PrincessBubblegum::specialAttack(Creature* enemy) {
	if (enemy->isAlive()) {
		int damage = 3 * strength + intelligence + agility + RPGUtils::getRandom(-10, 10);
		damage += damage * sqrt(getLevel());
		printf("Bubblegum is using her elemental powers:\n");
		printf("      %s's health -%d\n", enemy->getName(), damage);
		enemy->subtractHealth(damage);
	}
}