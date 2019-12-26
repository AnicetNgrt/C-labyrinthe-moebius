#pragma once
#include "item.h"

struct Tab2 {
	Item** mat; // [ligne] [colone]
	bool** used;
	unsigned int nbC;
	unsigned int nbL;
};

void initialiser(unsigned int nbL, unsigned int nbC, Tab2& t);
void write(Item it, unsigned int l, unsigned int c, Tab2& t);
Item read(const Tab2& t, unsigned int l, unsigned int c);
void afficher(const Tab2& t);
void detruire(Tab2& t);