#include "tableau2D.h"


void initialiser(unsigned int nbL, unsigned int nbC, Tab2& t) {
	t.nbC = nbC;
	t.nbL = nbL;

	t.mat = new Item * [nbL];
	t.used = new bool * [nbL];

	for (unsigned int l = 0; l < nbL; l++) {
		t.mat[l] = new Item[nbC];
		t.used[l] = new bool [nbC];

		for (unsigned int c = 0; c < nbC; c++) {
			t.used[l][c] = false;
		}
	}
}


void write(Item it, unsigned int l, unsigned int c, Tab2& t) {
	assert(l < t.nbL && c < t.nbC);
	t.mat[l][c] = it;
	t.used[l][c] = true;
}


Item read(Tab2& t, unsigned int l, unsigned int c) {
	assert(l < t.nbL && c < t.nbC);
	assert(t.used[l][c] == true);
	return t.mat[l][c];
}


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


void afficher(Tab2& t) {
	std::cout << "{\n";
	for (unsigned int l = 0; l < t.nbL; l++) {
		std::cout << "	{\n		";
		for (unsigned int c = 0; c < t.nbC; c++) {
			std::cout << to_string(t.mat[l][c]);
			if (c < t.nbC - 1) std::cout << ", ";
		}
		std::cout << "\n	}";
		if (l < t.nbL - 1) std::cout << ",\n\n";
	}
	std::cout << "\n}\n	";
}