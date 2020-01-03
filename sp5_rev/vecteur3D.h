/**
 * @file vecteur3D.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant vecteur 3D
 * Structures de données et algorithmes
 */

#include <iostream>
#include <cassert>

struct Vec3 {
	int x;
	int y;
	int z;
};

/**
 *	@brief Création d'un vecteur à trois coordonnées
 *	@param [in] x : coordonnée d'abscisse
 *	@param [in] y : coordonnée d'ordonnée
 *	@param [in] z : numéro de face
 *	@return v : le vecteur v
 */
Vec3 tuple(int x, int y, int z);

/**
 *	@brief Passage d'un tableau de 3 entiers à un Vecteur 3
 *	@param [in] crd : tableau de 3 entiers
 *	@return nouv : vecteur 3 issu de la conversion
 */
Vec3 from_list(const int crd[3]);

/**
 *	@brief Affichage (x,y,z) d'un Vecteur 3
 *	@param [in] v : coordonnées d'une case
 */
void afficher(const Vec3& v);

/**
 *	@brief Test d'égalité entre deux Vecteurs 3 (ssi toutes coordonnées égales)
 *	@param [in] v1 : premier vecteur
 *	@param [in] v2 : second vecteur
 *	@return true si toutes les coordonnées sont égales, false sinon
 */
bool egal(const Vec3& v1, const Vec3& v2);

/**
 *	@brief Inversion des ordonnées d'un Vecteur 3 par rapport au y_max
 *	@param [in] v ; vecteur 3D
 *	@param [in] max_y : valeur maximale d'ordonnée
 *	@return retour : vecteur avec coordonnée y inversée
 */
Vec3 inv_y(const Vec3& v, const int max_y);