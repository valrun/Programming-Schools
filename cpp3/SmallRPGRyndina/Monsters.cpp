#include "Monsters.h"
#include "Utils.h"

TheIceKing::TheIceKing() : Monster(30) {}
const char* TheIceKing::getName() {
	return "The Ice King";
}
void TheIceKing::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(1, 15);
	printf("<-The Ice King is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	enemy->subtractHealth(damage);
}
Drop TheIceKing::getDrop() {
	return { RPGUtils::getRandom(5, 15),  (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(0) };
}

KingOfOoo::KingOfOoo() : Monster(80) {}
const char* KingOfOoo::getName() {
	return "King Of Ooo";
}
void KingOfOoo::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(15, 25);
	printf("<-King Of Ooo is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	enemy->subtractHealth(damage);
}
Drop KingOfOoo::getDrop() {
	return { RPGUtils::getRandom(15, 30), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(0) };
}

EarlOfLemongrab::EarlOfLemongrab() : Monster(150) {}
const char* EarlOfLemongrab::getName() {
	return "Earl Of Lemongrab";
}
void EarlOfLemongrab::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(25, 40);
	printf("<-Earl Of Lemongrab is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop EarlOfLemongrab::getDrop() {
	return { RPGUtils::getRandom(30, 50), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(1) };
}

MartinMertens::MartinMertens() : Monster(250) {}
const char* MartinMertens::getName() {
	return "Martin Mertens";
}
void MartinMertens::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(40, 60);
	printf("<-Martin Mertens is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop MartinMertens::getDrop() {
	return { RPGUtils::getRandom(50, 100), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(1) };
}

HunsonAbadeer::HunsonAbadeer() : Monster(300) {}
const char* HunsonAbadeer::getName() {
	return "Hunson Abadeer";
}
void HunsonAbadeer::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(60, 90);
	printf("<-Hunson Abadeer is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop HunsonAbadeer::getDrop() {
	return { RPGUtils::getRandom(100, 145), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(2) };
}

PatienceStPim::PatienceStPim() : Monster(400) {}
const char* PatienceStPim::getName() {
	return "Patience St Pim";
}
void PatienceStPim::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(90, 110);
	printf("<-Patience St Pim is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop PatienceStPim::getDrop() {
	return { RPGUtils::getRandom(145, 165), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(2) };
}

UncleGumbald::UncleGumbald() : Monster(500) {}
const char* UncleGumbald::getName() {
	return "Uncle Gumbald";
}
void UncleGumbald::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(110, 130);
	printf("<-Uncle Gumbald is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop UncleGumbald::getDrop() {
	return { RPGUtils::getRandom(165, 200), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(1,2) };
}

Orgalorg::Orgalorg() : Monster(600) {}
const char* Orgalorg::getName() {
	return "Orgalorg";
}
void Orgalorg::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(130, 170);
	printf("<-Orgalorg is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop Orgalorg::getDrop() {
	return { RPGUtils::getRandom(200, 250), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(1, 2) };
}

TheLich::TheLich() : Monster(800) {}
const char* TheLich::getName() {
	return "The Lich";
}
void TheLich::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(170, 190);
	printf("<-The Lich is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop TheLich::getDrop() {
	return { RPGUtils::getRandom(250, 300), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(2, 2) };
}

GOLB::GOLB() : Monster(1600) {}
const char* GOLB::getName() {
	return "GOLB";
}
void GOLB::attack(Creature* enemy) {
	int damage = RPGUtils::getRandom(190, 210);
	printf("<-GOLB is beatting the enemy:\n");
	printf("      %s's health -%d\n", enemy->getName(), damage);
	if (enemy->isAlive()) {
		enemy->subtractHealth(damage);
	}
}
Drop GOLB::getDrop() {
	return { RPGUtils::getRandom(300, 400), (DropType)RPGUtils::getRandom(1), (DropGrade)RPGUtils::getRandom(2, 2) };
}