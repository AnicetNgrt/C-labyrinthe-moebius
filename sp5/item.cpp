#include "item.h"

/** @brief Affiche la version chaîne de caractères d'un item.
*	@param [in] it Item à afficher
*	@pre Il existe une fonction __string__ permettant de convertir le type 
    représenté par un Item en chaîne de caractères.
*/
void afficher(const Item& it) {
	char* str = string(it);
	std::cout << str;
	delete [] str;
	str = NULL;
}