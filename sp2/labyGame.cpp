#include "labyGame.h"
#define PILE_CAP 10
#define PILE_PAS 1

/**
 *	@brief Parcours du labyrinthe par le dragon
 */
void MissionDragon() {
	Laby laby;
	Pile pile;
	char path[] = "inSmall.txt";
	bool plan_found = false;
	Vec3 courant = tuple(0, 0, 0);

	initialiser(path, laby);
	initialiser(PILE_CAP, PILE_PAS, pile);
	empiler(laby.crd_dragon, pile);

	/*while (!plan_found && !est_vide(pile)) {*/
	for (unsigned int k = 0; k < 10; ++k) {
		courant = sommet(pile);
		depiler(pile);

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

				if (est_connexe(courant, translate, laby)) {
					empiler(translate, pile);
				}

			}
			Case* ca = get_case(courant, laby);
			ca->visite = true;
			ca->ordre = k;
		}
		else {
			plan_found = true;
		}
	}

	/*if (read_case(courant, laby).type == PLAN) {
		std::cout << "trouvé";
		afficher(courant);
		std::cout << "\n";
	}
	else {
		std::cout << "non\n";
	}*/

	afficher(laby);
	std::cout << "\n";
}