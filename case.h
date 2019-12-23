#pragma once

enum typeCase { MUR = '#', CHEMIN = '+', DRAGON = 'D', PLAN = 'P' };

struct Case {
	typeCase type;
};

char* to_string(Case& c);