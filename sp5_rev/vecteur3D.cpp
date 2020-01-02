#include "vecteur3D.h"

/**
 *	@brief Création d'un vecteur à trois coordonnées et de ses composantes x, y et z
 *	@param [in] x : coordonnée d'abscisse
 *	@param [in] y : coordonnée d'ordonnée
 *	@param [in] z : numéro de face
 *	@return v : le vecteur v
 */
Vec3 tuple(int x, int y, int z) {
	Vec3 v; v.x = x; v.y = y; v.z = z;
	return v;
}

/**
 *	@brief Lien entre le coordonnées d'un vecteur et un tableau crd
 *	@param [in] crd : tableau contenant les coordonnées d'une case
 *	@return nouv : vecteur contenant les coordonnées
 */
Vec3 from_list(const int crd[3]) {
	Vec3 nouv;
	nouv.x = crd[0];
	nouv.y = crd[1];
	nouv.z = crd[2];
	return nouv;
}

/**
 *	@brief Affichage de la partie entre parenthèses des coordonnées de chaque case du chemin
 *	@param [in] v : coordonnées d'une case
 */
void afficher(const Vec3& v) {
	std::cout << "(" << v.x << "," << v.y << "," << v.z+1 << ")";
}

/**
 *	@brief Comparaison des coordonnées de deux vecteurs
 *	@param [in] v1 : premier vecteur
 *	@param [in] v2 : second vecteur
 *	@return true si toutes les coordonnées sont égales, false sinon
 */
bool egal(const Vec3& v1, const Vec3& v2) {
	bool x_egal = v1.x == v2.x;
	bool y_egal = v1.y == v2.y;
	bool z_egal = v1.z == v2.z;
	return x_egal && y_egal && z_egal;
}

/**
 *	@brief Inversion des ordonnées au changement de face
 *	@param [in] v ; vecteur 3D
 *	@param [in] max_y : coordonnée maximale d'ordonnée
 *	@return retour : vecteur avec coordonnée y inversée
 */
Vec3 inv_y(const Vec3& v, const int max_y) {
	Vec3 retour;
	retour.x = v.x;
	retour.y = max_y - v.y;
	retour.z = v.z;
	return retour;
}