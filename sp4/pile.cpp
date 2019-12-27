#include "pile.h"

/** 
 * @brief Initialiser une pile vide
 * la pile est allou�e en m�moire dynamique
 * @see detruire pour une d�sallocation en fin d'utilisation
 * @param [in] n : la capacit� de la pile
 * @param [in] p : le pas d'extension de la pile
 * @param [out] pile : la pile � initialiser
 * @pre n>0
 */
void initialiser(unsigned int n, unsigned int p, Pile& pile) {
	pile.pas = p;
	pile.nbEl = 0;
	pile.cap = n;
	pile.tab = new Vec3[n];
}

/**
 * @brief Empiler un item sur une pile
 * @param [in] it : l'item � empiler
 * @param [in,out] pile : la pile
 */
void empiler(const Vec3& it, Pile& pile) {
	if (pile.nbEl >= pile.cap) {
		Vec3* nouv_tab = new Vec3[pile.cap+pile.pas];
		for (unsigned int i = 0; i < pile.nbEl; ++i) {
			nouv_tab[i] = pile.tab[i];
		}
		delete [] pile.tab;
		pile.tab = nouv_tab;
		pile.cap += pile.pas;
	}
	pile.nbEl++;
	pile.tab[pile.nbEl - 1] = it;
}

/**
 * @brief D�piler l'item au sommet de pile
 * @param [in, out] pile : la pile
 * @pre la pile n'est pas vide
 */
void depiler(Pile& pile) {
	assert(pile.nbEl > 0);
	pile.nbEl--;
}

/**
 * @brief Lire l'item au sommet de la pile
 * @param [in] pile : la pile
 * @return la valeur de l'item au sommet de la pile
 * @pre la pile n'est pas vide
 */
Vec3 sommet(const Pile& pile) {
	assert(pile.nbEl > 0);
	return pile.tab[pile.nbEl - 1];
}

/**
 * @brief D�sallouer une pile
 * @see initialiser, la pile a d�j� �t� initialis�e
 * @param [out] pile : la pile � d�sallouer
 * @
*/
void detruire(Pile& pile) {
	delete[] pile.tab;
	pile.tab = NULL;
	pile.cap = 0;
	pile.nbEl = 0;
	pile.pas = 0;
}

/**
 * @brief Test de pile vide
 * @param [in] pile : la pile
 * return true si p est vide, false sinon
 */
bool est_vide(const Pile& pile) {
	return pile.nbEl == 0;
}

void afficher(const Pile& pile) {
	for (unsigned int i = 0; i < pile.nbEl; ++i) {
		afficher(pile.tab[i]);
		std::cout << "->";
	}
}