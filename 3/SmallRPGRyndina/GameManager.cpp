#include "GameManager.h"
#include "Heros.h"
#include "Monsters.h"


bool GameManager::startGame() {
	this->welcome();
		Hero* hero = this->chooseOfTheHero();
	if (!hero->isAlive()) {
		delete hero;
		printf("Exit?\n1 - yes\nother - no\n");
		int tmp;
		scanf_s("%d", &tmp);
		return tmp != 1;
	}
	printf("\nYou are ");
	hero->print();

	Monster* monster[10] = {new TheIceKing(), new KingOfOoo(), new EarlOfLemongrab (), new MartinMertens (), 
														new HunsonAbadeer(), new PatienceStPim(), new UncleGumbald(),
														new Orgalorg(), new TheLich(), new GOLB() };
		
	for (int i = 0; i < 10; i++) {
		if (hero->isAlive()) {
			this->fight(hero, monster[i]);
		}
		delete monster[i];
	}

	delete hero;
	printf("Exit?\n1 - yes\nother - no\n");
	int tmp;
	scanf_s("%d", &tmp);
	return tmp != 1;
}

void GameManager::welcome() {
	printf("Welcom to Earth Ooo\n");
}

Hero* GameManager::chooseOfTheHero() {
	printf(" Choose your hero:\n");
	printf("  1 - Jake The Dog\n");
	printf("  2 - Finn The Human\n");
	printf("  3 - PrincessBubblegum\n");
	printf("  other - end the game\n");
	int tmp;
	scanf_s("%d", &tmp);

	switch (tmp) {
	case 1:
		return new JakeTheDog();
		break;
	case 2:
		return new FinnTheHuman();
		break;
	case 3:
		return new PrincessBubblegum();
		break;
	default:
		Hero* tmp = new JakeTheDog();
		tmp->subtractHealth(tmp->getHealth());
		return tmp;
		break;
	}
}

void GameManager::fight(Hero* hero, Monster* monster) {
	printf("\n\n");
	hero->print();
	printf("___________________________%s vs %s___________________________\n",hero->getName(), monster->getName());
	bool tmp = RPGUtils::getRandom(7 + hero->getAgility()) >= 7;
	while (hero->isAlive() && monster->isAlive()) {
		if (tmp) {
			monster->attack(hero);
		}
		else {
			this->herosAttack(hero, monster);
		}

		tmp = !tmp;
		if (!hero->isAlive()) {
			printf("You dead\n");
			return;
		}

		if (!monster->isAlive()) {
			printf("%s is dead\n", monster->getName());
			printf("You win\n");
			Drop drop = monster->getDrop();
			hero->addExperience(drop.experience);
			printf("+%d experience, ", drop.experience);
			double k = 1;
			switch (drop.grade)
			{
			case  SMALL:
				k = 0.3;
				break;
			case MEDIUM:
				k = 0.5;
				break;
			case LARGE:
				k = 1.0;
				break;
			default:
				break;
			}
			if (drop.type == HP_POTION) {
				hero->addHealth((int)(k * hero->getMaxHealth()));
				printf("+%d hp\n", (int)(k * hero->getMaxHealth()));
			}
			else {
				hero->addMP((int)(k * hero->getMaxMP() * hero->getIntelligence() / 10));
				printf("+%d mp\n\n", (int)(k * hero->getMaxMP() * hero->getIntelligence() / 10));
			}

			if (hero->getExperience() >= (int)(pow(hero->getLevel(), 5))) {
				this->levelUp(hero);
			}
		}
	}
}

void GameManager::herosAttack(Hero* hero, Monster* monster) {
	bool mpMAX = hero->getMaxMP() == hero->getMP();

	printf("			Choose active:\n");
	printf("				1 - Attack %s\n", monster->getName());
	if (mpMAX) {
		printf("				2 - Special attack %s\n", monster->getName());
	}
	printf("				other - Pass\n");
	int tmp;
	scanf_s("%d", &tmp);
	printf("\n");

	switch (tmp) {
	case 1:
		hero->attack(monster);
		break;
	case 2:
		if (mpMAX) {
			hero->specialAttack(monster);
			hero->resetMP();
			break;
		}
	default:
		
		break;
	}
}

void GameManager::levelUp(Hero* hero) {
	printf("                                      !!!Level UP!!!\n");
	printf("			Choose your upgrade:\n");
	printf("				1 - Strength\n");
	printf("				2 - Intelligence\n");
	printf("				3 - Agility\n");
	printf("				other - pass\n");
	int tmp;
	scanf_s("%d", &tmp);
	hero->levelUp(tmp);
}