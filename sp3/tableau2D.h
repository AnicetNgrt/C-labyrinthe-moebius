#pragma once
#include "item.h"

struct Tab2 {
	Item** mat; // [ligne] [colone]
	bool** used;
	int nbC;
	int nbL;
};

void initialiser(int nbL, int nbC, Tab2& t);
void write(Item it, int l, int c, Tab2& t);
Item* get(Tab2& t, int l, int c);
const Item read(const Tab2& t, int l, int c);
void afficher(const Tab2& t);
void detruire(Tab2& t);