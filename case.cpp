#include "case.h"

char* to_string(Case& c) {
	char* string;
	string = new char[2];
	string[0] = (char) c.type;
	string[1] = '\0';
	return string;
}