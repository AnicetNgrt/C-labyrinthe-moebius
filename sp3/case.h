#include "vecteur3D.h"

enum typeCase { MUR = '#', CHEMIN = '+', DRAGON = 'D', PLAN = 'P' };

struct Case {
	typeCase type;
	Vec3 crd;
	bool visite;
	unsigned int ordre;
};

bool est_valide(const typeCase tc);
char* string(const Case& c);
void afficher_crd(const Case& c);
Case initialiser(char c, Vec3 crd);