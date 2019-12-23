#include "labyrinthe.h"

Case to_case(char c) {
	Case ca; ca.type = (typeCase) c;
	return ca;
}

void initialiser(char* path, Laby& laby) {
	std::ifstream labyFic;
	labyFic.open(path);

	unsigned int nbC; labyFic >> nbC;
	unsigned int nbL; labyFic >> nbL;

	for (unsigned int f = 0; f < laby.NBFACE; f++) {
		initialiser(nbL, nbC, laby.faces[f]);

		for (unsigned int l = 0; l < nbL; l++) {
			char* ligne;
			ligne = new char[nbC];
			labyFic >> ligne;

			for (unsigned int c = 0; c < nbC; c++) {
				Case ca = to_case(ligne[c]);
				write(ca, l, c, laby.faces[f]);
			}
		}
	}
}

void afficher(Laby& laby) {
	unsigned int& nbC = laby.faces[0].nbC;
	unsigned int& nbL = laby.faces[0].nbL;

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

void detruire(Laby& laby) {
	for (unsigned int f = 0; f < laby.NBFACE; f++) {
		detruire(laby.faces[f]);
	}
}