/**
 * @file item.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant Item
 * Structures de données et algorithmes
 */

#include "case.h"

typedef Case Item;

/**
 *	@brief Affiche la version chaîne de caractères d'un item.
 *	@param [in] it Item à afficher
 *	@pre Il existe une fonction string permettant de convertir le type
	représenté par un Item en chaîne de caractères.
*/
void afficher(const Item& it);