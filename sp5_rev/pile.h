/**
 * @file pile.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant Pile
 * Structures de données et algorithmes
 */

#include "tableau2D.h"

struct Pile {
	Vec3* tab;
	unsigned int nbEl;
	unsigned int pas;
	unsigned int cap;
};

void initialiser(unsigned int n, unsigned int p, Pile& pile);
void empiler(const Vec3& it, Pile& pile);
void depiler(Pile& pile);
Vec3 sommet(const Pile& pile);
void detruire(Pile& pile);
bool est_vide(const Pile& pile);
void afficher(const Pile& pile);