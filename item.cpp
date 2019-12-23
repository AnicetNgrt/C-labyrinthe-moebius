#include "item.h"

void afficher(Item& it) {
	char* string = to_string(it);
	std::cout << string;
	delete [] string;
	string = NULL;
}