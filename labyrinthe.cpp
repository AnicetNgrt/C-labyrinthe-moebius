#include "labyrinthe.h"


/** @brief Lit un fichier .txt pour initialiser le labyrinthe
*	@param [in] path Chemin du fichier .txt qui décrit le labyrinthe
*	@param [out] laby Labyrinthe à initialiser
*/
void initialiser(char* path, Laby& laby) {
	std::ifstream labyFic;
	labyFic.open(path);

	unsigned int nbC; // nombre de colonnes
	labyFic >> nbC;
	unsigned int nbL; // nombre de lignes
	labyFic >> nbL;

	for (unsigned int f = 0; f < laby.NBFACE; f++) {
		initialiser(nbL, nbC, laby.faces[f]);

		for (unsigned int l = 0; l < nbL; l++) {
			char* ligne;
			ligne = new char[nbC];
			labyFic >> ligne;

			for (unsigned int c = 0; c < nbC; c++) {
				Case ca = char_to_case(ligne[c]);
				write(ca, l, c, laby.faces[f]);
			}
		}
	}

	labyFic.close();
}

/** @brief Affiche un labyrinthe
*	@param [in] laby Labyrinthe à afficher
*/
void afficher(const Laby& laby) {
	unsigned int nbC = laby.faces[0].nbC;
	unsigned int nbL = laby.faces[0].nbL;

	std::cout << nbC << " " << nbL << "\n";

	for (unsigned int f = 0; f < laby.NBFACE; f++) {
		for (unsigned int l = 0; l < nbL; l++) {
			for (unsigned int c = 0; c < nbC; c++) {
				Case ca = read(laby.faces[f], l, c);
				afficher(ca);
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}

/** @brief Désalloue les tableaux représentant les faces d'un labyrinthe
*	@param [out] laby Labyrinthe à détruire
*/
void detruire(Laby& laby) {
	for (unsigned int f = 0; f < laby.NBFACE; f++) {
		detruire(laby.faces[f]);
	}
}