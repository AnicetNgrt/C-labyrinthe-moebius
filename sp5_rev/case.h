/**
 * @file case.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant case
 * Structures de données et algorithmes
 */

#include "vecteur3D.h"

enum typeCase { MUR = '#', CHEMIN = '+', DRAGON = 'D', PLAN = 'P' };

struct Case {
	typeCase type;
	Vec3 crd;
	bool visite;
	bool dans_chemin;
	unsigned int ordre;
};

/**
 *	@brief Renvoie vrai ssi le type de case d'entrée est vaide.
 *	@param [in] tc Type de case à vérifier
 */
bool est_valide(const typeCase tc);

/**
 *	@brief Convertit une Case en chaîne de caractères
 *	@param [in] c : Case à convertir
 *	@return Chaîne de caractères issue de la conversion
 */
char* string(const Case& c, bool mecontent = false);

/**
 *	@brief Convertit un char en Case
 *	@param [in] c : Case à convertir
 *	@param [in] crd : Coordonnées 3D de la case
 *	@return Chaîne de caractères issue de la conversion
 *	@pre Le char d'entrée correspond à un type de case valide
 */
Case initialiser(char c, Vec3 crd);

/**
 *	@brief Affiche les coordonnées d'une Case
 *	@param [in] c : Case dont on souhaite afficher les coordonnées
 */
void afficher_crd(const Case& c);