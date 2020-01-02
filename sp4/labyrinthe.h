#include <fstream>
#include "pile.h"

enum { NBDEPL = 8, DIM = 3 };

const int DEPL[NBDEPL][DIM] = {
	{-1,0,0},{-1,1,0},{0,1,0},{1,1,0},{1,0,0},{1,-1,0},{0,-1,0},{-1,-1,0}
};

struct Laby {
	enum {NBFACE = 2};
	Tab2 faces[NBFACE];
	Vec3 crd_dragon;
};

void initialiser(char* path, Laby& laby);
void afficher(const Laby& laby);
void detruire(Laby& laby);
Case* get_case(const Vec3& crd, Laby& laby);
Case read_case(const Vec3& crd, const Laby& laby);
bool est_case(const Vec3& crd, const Laby& laby);
Vec3 translation_moebius(const Vec3& v1, const Vec3& v2, const Laby& laby);
bool est_connexe(const Vec3& c1, const Vec3& c2, const Laby& laby);
bool est_a_visiter(const Vec3& c1, const Vec3& c2, const Laby& laby);
