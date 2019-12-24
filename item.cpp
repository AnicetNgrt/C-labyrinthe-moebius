#include "item.h"

/** @brief Affiche la version cha�ne de caract�res d'un item.
*	@param [in] it Item � afficher
*	@pre Il existe une fonction __string__ permettant de convertir le type 
repr�sent� par un Item en cha�ne de caract�res.
*/
void afficher(const Item& it) {
	char* string = __string__(it);
	std::cout << string;
	delete [] string;
	string = NULL;
}