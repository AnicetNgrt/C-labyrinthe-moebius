#pragma once
#include <iostream>
#include <cassert>

enum typeCase { MUR = '#', CHEMIN = '+', DRAGON = 'D', PLAN = 'P' };

struct Case {
	typeCase type;
};

bool __valid__(const typeCase tc);
char* __string__(const Case& c);
Case char_to_case(char c);