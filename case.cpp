#include "case.h"

/** @brief Renvoie vrai ssi le type de case d'entrée est vaide.
*	@param [in] tc Type de case à vérifier
*/
bool __valid__(const typeCase tc) {
	return tc == MUR || tc == CHEMIN || tc == DRAGON || tc == PLAN;
}

/** @brief Convertis une Case en chaîne de caractères
*	@param [in] c Case à convertir
*	@return Chaîne de caractères issue de la conversion
*/
char* __string__(const Case& c) {
	char* string;
	string = new char[2];
	string[0] = (char) c.type;
	string[1] = '\0';
	return string;
}

/** @brief Convertis un char en Case
*	@param [in] c Case à convertir
*	@return Chaîne de caractères issue de la conversion
*	@pre Le char d'entrée correspond à un type de case valide
*/
Case char_to_case(char c) {
	typeCase tc = (typeCase) c;
	assert(__valid__(tc));
	Case ca; ca.type = tc;
	return ca;
}