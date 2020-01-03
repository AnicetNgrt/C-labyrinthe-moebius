/**
 * @file labyGame.h
 * Projet DesprésGr109NougaretGr109
 * @author Antoine Després, Anicet Nougaret
 * @version 1 06/01/20
 * @brief Composant LabyGame
 * Structures de données et algorithmes
 */

#include "labyrinthe.h"

/**
 *	@brief Met à jour la pile contenant les coordonnées du chemin du dragon
 *	@param [in] chemin : chemin déjà parcouru
 *	@param [in] nouv_crd : nouvelle coordonnée à empiler
 *	@param [in] laby : le labyrinthe
*/
void maj_chemin(Pile& chemin, Vec3& nouv_crd, Laby& laby);

/**
 *	@brief Parcours du labyrinthe par le dragon
 */
void MissionDragon();