#pragma once
#include <fstream>
#include "tableau2D.h"

struct Vec3 {
	unsigned int x;
	unsigned int y;
	unsigned int z;
};

struct Laby {
	enum {NBFACE = 2};
	Tab2 faces[NBFACE];
};

void initialiser(char* path, Laby& laby);
void afficher(Laby& laby);
void detruire(Laby& laby);
