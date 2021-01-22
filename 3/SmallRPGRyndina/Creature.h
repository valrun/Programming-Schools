#pragma once
class Creature
{
protected:
	int health;
public:
	Creature(int health) { this->health = health; }
	~Creature() {}

	virtual void attack(Creature* enemy) = 0;
	virtual const char* getName() = 0;

	int getHealth() { return health; }
	
	void subtractHealth(int damage) {
		if (damage >= 0) {
			health -= damage;
				if (health < 0) {
					health = 0;
				}
		}
	}
		
	bool isAlive() {
		return health > 0;
	}
};