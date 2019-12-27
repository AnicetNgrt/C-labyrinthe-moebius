#include "labyGame.h"
#define PILE_CAP 10
#define PILE_PAS 1

/**
 *	@brief Parcours du labyrinthe par le dragon
 *	@param [] ? : ???
 */

/*

*/

void maj_chemin(Pile& chemin, Vec3& nouv_crd, Laby& laby) {
	while (!est_vide(chemin) && !est_connexe(nouv_crd, sommet(chemin), laby)) {
		Case* ca = get_case(sommet(chemin), laby);
		ca->dans_chemin = false;
		depiler(chemin);
	}
	Case* ca = get_case(nouv_crd, laby);
	ca->dans_chemin = true;
	empiler(nouv_crd, chemin);
}


void MissionDragon() {
	Laby laby;
	Pile suivantes;
	Pile chemin;
	char path[] = "inSmall.txt";
	bool plan_found = false;
	unsigned int k = 0;
	Vec3 courant = tuple(0, 0, 0);

	initialiser(path, laby);
	initialiser(PILE_CAP, PILE_PAS, suivantes);
	initialiser(PILE_CAP, PILE_PAS, chemin);
	empiler(laby.crd_dragon, suivantes);

	for (k = 0; k < 20;) {
	/*while (!plan_found && !est_vide(suivantes)) {*/
		courant = sommet(suivantes);
		depiler(suivantes);

		if (read_case(courant, laby).type != PLAN) {

			for (int i = 0; i < NBDEPL; ++i) {

				Vec3 translation = from_list(DEPL[i]);

				if (courant.y == 0 && translation.y == -1) {
					continue;
				}
				if (laby.faces[courant.z].nbL <= courant.y + translation.y) {
					continue;
				}

				Vec3 translate = translation_moebius(courant, translation, laby);

				if (est_a_visiter(courant, translate, laby)) {
					empiler(translate, suivantes);
				}

			}
			Case* ca = get_case(courant, laby);
			if (!ca->visite) {
				maj_chemin(chemin, courant, laby);
			}
			ca->visite = true;
			ca->ordre = k;
			++k;
		}
		else {
			plan_found = true;
		}
	}

	/*if (read_case(courant, laby).type == PLAN) {
		std::cout << "";
		afficher(courant);
		std::cout << "\n";
	}
	else {
		std::cout << "non\n";
		afficher(courant);
	}*/

	afficher(laby);
	std::cout << "\n";
}