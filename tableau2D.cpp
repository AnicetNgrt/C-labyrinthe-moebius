#include "tableau2D.h"

/** @brief Initialise un tableau 2D
*	@param [in] nbL Nombre de lignes du tableau
*	@param [in] nbC Nombre de colonnes du tableau
*	@param [out] t Tableau 2D à initialiser
*/
void initialiser(unsigned int nbL, unsigned int nbC, Tab2& t) {
	t.nbC = nbC;
	t.nbL = nbL;

	t.mat = new Item * [nbL];
	t.used = new bool * [nbL];

	for (unsigned int l = 0; l < nbL; l++) {
		t.mat[l] = new Item [nbC];
		t.used[l] = new bool [nbC];

		for (unsigned int c = 0; c < nbC; c++) {
			t.used[l][c] = false;
		}
	}
}

/** @brief Remplir une case du tableau avec un Item.
*	@param [in] it Item à mettre dans la case
*	@param [in] l N° de ligne de l'emplacement de la case à remplir
*	@param [in] c N° de colonne de l'emplacement de la case à remplir
*	@param [out] t Tableau 2D à écrire
*	@pre N° de Ligne et de colonne positifs et compris dans le tableau.
*/
void write(Item it, unsigned int l, unsigned int c, Tab2& t) {
	assert(l < t.nbL && c < t.nbC);
	t.mat[l][c] = it;
	t.used[l][c] = true;
}

/** @brief Obtenir l'Item stocké dans une case du tableau
*	@param [in] t Tableau 2D à lire
*	@param [in] l N° de ligne de l'emplacement de la case à lire
*	@param [in] c N° de colonne de l'emplacement de la case à lire
*	@return Item situé dans la case spécifiée
*	@pre N° de Ligne et de colonne positifs et compris dans le tableau.
*	@pre Case spécifiée non vide
*/
Item read(const Tab2& t, unsigned int l, unsigned int c) {
	assert(l < t.nbL && c < t.nbC);
	assert(t.used[l][c] == true);
	return t.mat[l][c];
}

/** @brief Désalloue et rend NULL un tableau 2D
*	@param [in-out] t Tableau 2D à désallouer
*/
void detruire(Tab2& t) {
	for (unsigned int l = 0; l < t.nbL; l++) {
		delete [] t.mat[l];
		t.mat[l] = NULL; 
		delete [] t.used[l];
		t.used[l] = NULL;
	}

	delete[] t.mat;
	t.mat = NULL;
	delete[] t.used;
	t.used = NULL;
}

/** @brief Affiche un tableau 2D et son contenu initialisé
*	@param [in] t Tableau 2D à afficher
*/
void afficher(const Tab2& t) {
	std::cout << "{\n";
	for (unsigned int l = 0; l < t.nbL; l++) {
		std::cout << "	{\n		";
		for (unsigned int c = 0; c < t.nbC; c++) {
			if (t.used[l][c]) std::cout << __string__(t.mat[l][c]);
			else std::cout << "\033[41m?\033[0m";

			if (c < t.nbC - 1) std::cout << ", ";
		}
		std::cout << "\n	}";
		if (l < t.nbL - 1) std::cout << ",\n\n";
	}
	std::cout << "\n}\n	";
}