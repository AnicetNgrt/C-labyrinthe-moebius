/**
 * @file pile.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant Pile
 * Structures de données et algorithmes
 */

#include "tableau2D.h"

struct Pile {
	Vec3* tab;
	unsigned int nbEl;
	unsigned int pas;
	unsigned int cap;
};

/** 
 * @brief Initialiser une pile vide
 * la pile est allouée en mémoire dynamique
 * @see detruire pour une désallocation en fin d'utilisation
 * @param [in] n : la capacité de la pile
 * @param [in] p : le pas d'extension de la pile
 * @param [out] pile : la pile à initialiser
 * @pre n>0
 */
void initialiser(unsigned int n, unsigned int p, Pile& pile);

/**
 * @brief Empiler un item sur une pile
 * @param [in] it : l'item à empiler
 * @param [in,out] pile : la pile
 */
void empiler(const Vec3& it, Pile& pile);

/**
 * @brief Dépiler l'item au sommet de pile
 * @param [in,out] pile : la pile
 * @pre la pile n'est pas vide
 */
void depiler(Pile& pile);

/**
 * @brief Lire l'item au sommet de la pile
 * @param [in] pile : la pile
 * @return la valeur de l'item au sommet de la pile
 * @pre la pile n'est pas vide
 */
Vec3 sommet(const Pile& pile);

/**
 * @brief Désallouer une pile
 * @see initialiser, la pile a déjà été initialisée
 * @param [out] pile : la pile à désallouer
 */
void detruire(Pile& pile);

/**
 * @brief Test de pile vide
 * @param [in] pile : la pile
 * @return true si p est vide, false sinon
 */
bool est_vide(const Pile& pile);

/**
 *	@brief Affichage des coordonnées du chemin selon la mise en forme prévue
 *	@param [in] pile : la pile contenant les coordonnées
 */
void afficher(const Pile& pile);