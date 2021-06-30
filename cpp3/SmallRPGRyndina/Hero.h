#pragma once
#include "Creature.h"
#include <stdio.h>
#include "Utils.h"
class Hero : public Creature
{
private:
	int experience;
	int level;;
	int MAXhealth;
	int MAXmp;
	int mp;
protected:
	int strength;
	int intelligence;
	int agility;
public:
	Hero(int health) : Creature(health) {
		MAXhealth = health;
		level = 1;
		experience = 0;
		mp = 0;
		MAXmp = 100;
	}
	virtual void specialAttack(Creature* enemy) = 0;

	int getLevel() {
		return level;
	}
	int getExperience() {
		return experience;
	}
	int getMaxHealth() {
		return MAXhealth;
	}
	int getMaxMP() {
		return MAXmp;
	}
	int getMP() {
		return mp;
	}
	int getAgility() {
		return agility;
	}
	int getIntelligence() {
		return intelligence;
	}

	void addHealth(int health) {
		if (health >= 0) {
			this->health += health;
			if (this->health > MAXhealth) {
				this->health = MAXhealth;
			}
		}
	}

	void addMP(int mp) {
		if (mp >= 0) {
			this->mp += mp;
			if (this->mp > MAXmp) {
				this->mp = MAXmp;
			}
		}
	}

	void resetMP() {
		mp = 0;
	}
	
	void addExperience(int experience) {
		this->experience += experience;
	}

	void levelUp(int tmp) {
		level++;
		MAXhealth += MAXhealth * RPGUtils::getRandom(5, 10) / 10;
		health = MAXhealth;

		switch (tmp) {
		case 1:
			strength += (int)(strength * 0.5);
			break;
		case 3:
			agility += (int)(agility * 0.4);
			break;
		case 2:
			intelligence += (int)(intelligence * 0.4);
			break;
		default:
				
			break;
		}

		this->print();
	}

	void print() {
		printf(" %s\n",this->getName());
		printf("HP %d, MP %d\n", this->getHealth(), this->getMP());
		printf("st %d, in %d, ag %d\n", this->strength, this->intelligence, this->agility);
	}
};

