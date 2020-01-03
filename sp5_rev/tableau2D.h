/**
 * @file tableau2D.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant tableau à 2 dimensions
 * Structures de données et algorithmes
 */

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