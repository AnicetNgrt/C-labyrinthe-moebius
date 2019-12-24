#include "item.h"

/** @brief Affiche la version chaîne de caractères d'un item.
*	@param [in] it Item à afficher
*	@pre Il existe une fonction __string__ permettant de convertir le type 
représenté par un Item en chaîne de caractères.
*/
void afficher(const Item& it) {
	char* string = __string__(it);
	std::cout << string;
	delete [] string;
	string = NULL;
}