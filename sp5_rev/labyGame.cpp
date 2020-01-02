#include "labyGame.h"
#define PILE_CAP 10
#define PILE_PAS 1

/**
 *	@brief Met à jour la pile contenant les coordonnées du chemin du dragon
 *	@param [in] chemin : chemin déjà parcouru
 *	@param [in] nouv_crd : nouvelle coordonnée à empiler
 *	@param [in] laby : le labyrinthe
*/
void maj_chemin(Pile& chemin, Pile& chemin_fix, Vec3& nouv_crd, Laby& laby) {
	static Vec3 last = nouv_crd;
	static bool inv_mode = false;
	while (!est_vide(chemin) && !est_connexe(nouv_crd, sommet(chemin), laby)) {
		Case* ca = get_case(sommet(chemin), laby);
		ca->dans_chemin = false;
		depiler(chemin);
		depiler(chemin_fix);
	}
	Case* ca = get_case(nouv_crd, laby);
	ca->dans_chemin = true;
	empiler(nouv_crd, chemin);

	if (last.z == 0 && last.x == laby.faces[0].nbC-1 && nouv_crd.x == 0 && nouv_crd.z == 1) {
		inv_mode = true;
	}
	else if (last.z == 1 && last.x == 0 && nouv_crd.x == laby.faces[0].nbC - 1 && nouv_crd.z == 0) {
		inv_mode = true;
	}

	if (inv_mode) empiler(inv_y(nouv_crd, laby.faces[0].nbL), chemin_fix);
	if (!inv_mode) empiler(nouv_crd, chemin_fix);

	last = nouv_crd;
}

/**
 *	@brief Parcours du labyrinthe par le dragon
 */
void MissionDragon() {
	Laby laby;
	Pile suivantes;
	Pile chemin;
	Pile chemin_fix;
	char path[] = "inMedium.txt";
	bool plan_found = false;
	unsigned int k = 0;
	Vec3 courant = tuple(0, 0, 0);

	initialiser(path, laby);
	initialiser(PILE_CAP, PILE_PAS, suivantes);
	initialiser(PILE_CAP, PILE_PAS, chemin);
	initialiser(PILE_CAP, PILE_PAS, chemin_fix);
	empiler(laby.crd_dragon, suivantes);

	while (!plan_found && !est_vide(suivantes)) {
		courant = sommet(suivantes);
		Case* ca = get_case(courant, laby);
		depiler(suivantes);

		if (!ca->visite) {
			maj_chemin(chemin, chemin_fix, courant, laby);
		}

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
			
			ca->visite = true;
			ca->ordre = k;
			++k;
		}
		else {
			plan_found = true;
		}
	}

	if (read_case(courant, laby).type == PLAN) {
		afficher(laby);
		afficher(chemin);
		std::cout << "C";
		afficher(laby.crd_dragon);
		std::cout << "->";
	}
	else {
		afficher(laby, true);
	}
}