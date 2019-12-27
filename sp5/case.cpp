#include "case.h"

/** @brief Renvoie vrai ssi le type de case d'entr�e est vaide.
 *	@param [in] tc Type de case � v�rifier
 */
bool est_valide(const typeCase tc) {
	return tc == MUR || tc == CHEMIN || tc == DRAGON || tc == PLAN;
}

/** @brief Convertis une Case en cha�ne de caract�res
 *	@param [in] c Case � convertir
 *	@return Cha�ne de caract�res issue de la conversion
 */
char* string(const Case& c, bool mecontent) {
	char* str;
	str = new char[2];
	str[0] = (char) c.type;
	//if (c.visite) str[0] = 'V';
	if (c.dans_chemin) str[0] = 'C';
	if (mecontent && c.type != PLAN) str[0] = '#';
	if (mecontent && c.type == PLAN) str[0] = 'P';
	str[1] = '\0';
	return str;
}

/** @brief Convertit un char en Case
 *	@param [in] c : Case � convertir
 *	@param [in] crd : Coordonn�es 3D de la case
 *	@return Cha�ne de caract�res issue de la conversion
 *	@pre Le char d'entr�e correspond � un type de case valide
 */
Case initialiser(char c, Vec3 crd) {
	typeCase tc = (typeCase) c;
	assert(est_valide(tc));
	Case ca;
	ca.type = tc;
	ca.crd = crd;
	ca.ordre = 10;
	ca.visite = false;
	ca.dans_chemin = false;
	return ca;
}

void afficher_crd(const Case& c) {
	afficher(c.crd);
}