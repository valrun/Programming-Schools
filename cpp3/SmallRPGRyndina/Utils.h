#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
enum DropType { HP_POTION, MP_POTION };
enum DropGrade { SMALL, MEDIUM, LARGE };

struct Drop
{
	int experience;
	DropType type;
	DropGrade grade;
};

class RPGUtils
{
public:
	static int getRandom(int from, int to) { return rand() % (((to - from) + 1)) + from; };
	static int getRandom(int to) { return rand() % (to + 1); };
};