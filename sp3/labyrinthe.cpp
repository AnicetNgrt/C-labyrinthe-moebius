#include "labyrinthe.h"


/** @brief Lit un fichier .txt pour initialiser le labyrinthe
 *	@param [in] path Chemin du fichier .txt qui décrit le labyrinthe
 *	@param [out] laby Labyrinthe à initialiser
 */
void initialiser(char* path, Laby& laby) {
	std::ifstream labyFic;
	labyFic.open(path);

	int nbC; // nombre de colonnes
	labyFic >> nbC;
	int nbL; // nombre de lignes
	labyFic >> nbL;

	for (int f = 0; f < laby.NBFACE; f++) {
		initialiser(nbL, nbC, laby.faces[f]);

		for (int l = 0; l < nbL; l++) {
			char* ligne;
			ligne = new char[nbC];
			labyFic >> ligne;

			for (int c = 0; c < nbC; c++) {
				Case ca = initialiser(ligne[c], tuple(c, l, f));
				
				if (ca.type == DRAGON) laby.crd_dragon = ca.crd;

				write(ca, l, c, laby.faces[f]);
			}
		}
	}

	labyFic.close();
}

/** @brief Affiche un labyrinthe
 *	@param [in] laby : Labyrinthe à afficher
 */
void afficher(const Laby& laby) {
	int nbC = laby.faces[0].nbC;
	int nbL = laby.faces[0].nbL;

	std::cout << nbC << " " << nbL << "\n";

	for (int f = 0; f < laby.NBFACE; f++) {
		for (int l = 0; l < nbL; l++) {
			for (int c = 0; c < nbC; c++) {
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
	for (int f = 0; f < laby.NBFACE; f++) {
		detruire(laby.faces[f]);
	}
}

/**
 *	@brief Trouver une case
 *	@param [in] crd : coordonnées d'une case
 *	@param [in] laby : le labyrinthe
 *	@return 
 */
Case* get_case(const Vec3& crd, Laby& laby) {
	assert(est_case(crd, laby));
	return get(laby.faces[crd.z], crd.y, crd.x);
}

Case read_case(const Vec3& crd, const Laby& laby) {
	assert(est_case(crd, laby));
	Case ca = read(laby.faces[crd.z], crd.y, crd.x);
	return ca;
}

bool est_case(const Vec3& crd, const Laby& laby) {
	bool z_valide = crd.z < Laby::NBFACE;
	if (!z_valide) return false;
	const Tab2& face = laby.faces[crd.z];
	bool y_valide = face.nbL > crd.y;
	bool x_valide = face.nbC > crd.x;
	return y_valide && x_valide;
}

Vec3 translation_moebius(const Vec3& depart, const Vec3& translation, const Laby& laby) {
	Vec3 nouv;
	nouv.z = (depart.z + translation.z) % Laby::NBFACE;
	Tab2 face = laby.faces[nouv.z];

	nouv.x = depart.x + translation.x;
	nouv.y = depart.y + translation.y;

	while (nouv.x < 0) {
		nouv.z = Laby::NBFACE - (nouv.z + 1);
		face = laby.faces[nouv.z];
		nouv.x += face.nbC;
	}

	while (face.nbC <= nouv.x) {
		nouv.x -= face.nbC;
		nouv.z = (nouv.z + 1) % Laby::NBFACE;
		face = laby.faces[nouv.z];	
	}

	assert(face.nbL > nouv.y);

	return nouv;
}

/**
 *	@brief Rapporte les coordonnées à un labyrinthe d'une seule face
 *	@param [in] crd : la coordonnée d'entrée
 *	@param [in] laby : le labyrinthe
 *	@return nouv : nouvelle coordonnée
 */
Vec3 crd_face_unique(const Vec3& crd, const Laby& laby) {
	assert(crd.z < Laby::NBFACE);
	Tab2 face = laby.faces[crd.z];
	assert(face.nbL > crd.y);
	Vec3 nouv;
	nouv.x = crd.x;
	nouv.y = crd.y;
	nouv.z = 0;

	for (int i = 0; i < crd.z; ++i) {
		face = laby.faces[i];
		nouv.x += face.nbC;
	}

	return nouv;
}

/**
 *	@brief Vérifie si une case est connexe à une autre (si on peut passer de l'une à l'autre)
 *	@param [in] depart : première case
 *	@param [in] arrivee : deuxième case
 *	@param [in] laby : le labyrinthe
 *	@return true ou false selon que les deux cases soient connexes ou non
 */
bool est_a_visiter(const Vec3& depart, const Vec3& arrivee, const Laby& laby) {
	assert(est_case(depart, laby) && est_case(arrivee, laby));

	bool est_acote;
	bool est_chemin;
	bool est_visitee;

	// vérifions si c'est un chemin
	Case c_arrivee = read_case(arrivee, laby);
	est_chemin = c_arrivee.type == CHEMIN;

	// vérifions si elle est visitée
	est_visitee = c_arrivee.visite;

	// vérifions si c'est à côté du départ
	for (int i = 0; i < NBDEPL; ++i) {
		Vec3 translation = from_list(DEPL[i]);
		Vec3 translate = translation_moebius(depart, translation, laby);

		if (egal(translate, arrivee)) est_acote = true;
	}

	return est_acote && est_chemin && !est_visitee;
}